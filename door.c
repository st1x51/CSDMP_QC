/*
TODO:add movesnd and stopsnd for doors
*/
#define	SF_DOOR_START_OPEN			1
#define SF_DOOR_PASSABLE			8
#define SF_DOOR_ONEWAY				16
#define	SF_DOOR_NO_AUTO_RETURN			32
#define SF_DOOR_USE_ONLY			256	// door must be opened by player's use button.
#define SF_DOOR_NOMONSTERS			512	// Monster can't open

enum
{
	TS_AT_TOP,
	TS_AT_BOTTOM,
	TS_GOING_UP,
	TS_GOING_DOWN
};

void() door_blocked =
{
	T_Damage (other, self, self, self.dmg);
	
// if a door has a negative wait, it would never come back if blocked,
// so let it just squash the object to death real fast
	if (self.wait >= 0)
	{
		if (self.state == TS_GOING_DOWN)
			door_go_up ();
		else
			door_go_down ();
	}
};


void() door_hit_top =
{
	sound (self, CHAN_VOICE, self.noise1, 1, ATTN_NORM);
	self.state = TS_AT_TOP;
	if (self.spawnflags & SF_DOOR_NO_AUTO_RETURN)
	{
		if (!(self.spawnflags & SF_DOOR_USE_ONLY))
			self.touch = door_touch;
	}
	else
	{	
		self.think = door_go_down;
		self.nextthink = self.ltime + self.wait;	
	}
	SUB_UseTargets();
};

void() door_hit_bottom =
{
	sound (self, CHAN_VOICE, self.noise1, 1, ATTN_NORM);
	self.state = TS_AT_BOTTOM;
	if(self.spawnflags & SF_DOOR_USE_ONLY)
	{	
			self.touch = SUB_Null;
	}
	else
	{	
		self.touch = door_touch;
	}
	SUB_UseTargets();
};

void() door_go_down =
{
	sound (self, CHAN_VOICE, self.noise2, 1, ATTN_NORM);

	self.state = TS_GOING_DOWN;
	SUB_CalcMove (self.pos1, self.speed, door_hit_bottom);
};

void() door_go_up =
{
	sound (self, CHAN_VOICE, self.noise2, 1, ATTN_NORM);
	self.state = TS_GOING_UP;
	SUB_CalcMove (self.pos2, self.speed, door_hit_top);
};

float() door_activate=
{
	if((self.spawnflags & SF_DOOR_NO_AUTO_RETURN ) && self.state == TS_AT_TOP )
	{
		// door should close
		door_go_down();
	}
	else
	{
		door_go_up();
	}

	return 1;	
}

void() door_touch =
{
	if (other.classname != "player")
		return;
	if(door_activate())
		self.touch = SUB_Null;
};

void() func_door =
{
	SetMovedir ();

	self.max_health = self.health;
	self.solid = SOLID_BSP;
	self.movetype = MOVETYPE_PUSH;
	setorigin (self, self.origin);	
	setmodel (self, self.model);
	self.classname = "door";

	self.blocked = door_blocked;
	self.use = door_activate; //weird,but working
	
	if (!self.speed)
		self.speed = 100;
	if (!self.wait)
		self.wait = 3;

	self.pos1 = self.origin;
	self.pos2 = self.pos1 + ( self.movedir * ( fabs( self.movedir_x * ( self.size_x - 2 ) ) + fabs( self.movedir_y * ( self.size_y - 2 ) ) + fabs( self.movedir_z * ( self.size_z - 2 ) ) - self.lip ) );

	if (self.spawnflags & SF_DOOR_START_OPEN)
	{
		setorigin (self, self.pos2);
		self.pos2 = self.pos1;
		self.pos1 = self.origin;
	}

	self.state = TS_AT_BOTTOM;

	if(self.spawnflags & SF_DOOR_USE_ONLY )
	{
		self.touch = SUB_Null;
	}
	else
		self.touch = door_touch;
};
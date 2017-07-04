// declaring the routines before they are called
//Tutor Bot by Coffee
//src is shitty atm
void() bot_jump1;
void() bot_check_ammo;
void() bot_attack;
.float bot_state;
.float search_time;
.float lefty;
.float pausetime;
float RANGE_MELEE				= 0;
float RANGE_NEAR				= 1;
float RANGE_MID					= 2;
float RANGE_FAR 				= 3;
/*
=============
infront

returns 1 if the entity is in front (in sight) of self
=============
*/
float(entity targ) infront =
{
	local vector	vec;
	local float		dot;
	
	makevectors (self.angles);
	vec = normalize (targ.origin - self.origin);
	dot = vec * v_forward;
	
	if ( dot > 0.3)
	{
		return TRUE;
	}
	return FALSE;
};
void() FoundTarget =
{
	if (self.enemy.classname == "player")
	{	
		self.think = self.th_stand;
		self.nextthink = time + 0.1;
	}
};
void() SUB_regen =
{
	//self.model = self.mdl;		
	self.solid = SOLID_TRIGGER;	
	setorigin (self, self.origin);
};
/*
=============
range

returns the range catagorization of an entity reletive to self
0	melee range, will become hostile even if back is turned
1	visibility and infront, or visibility and show hostile
2	infront and show hostile
3	only triggered by damage
=============
*/
float(entity targ) range =
{
	local vector	spot1, spot2;
	local float		r;	
	spot1 = self.origin + self.view_ofs;
	spot2 = targ.origin + targ.view_ofs;
	
	r = vlen (spot1 - spot2);
	if (r < 120)
		return RANGE_MELEE;
	if (r < 500)
		return RANGE_NEAR;
	if (r < 1000)
		return RANGE_MID;
	return RANGE_FAR;
};
/*
=============
visible

returns 1 if the entity is visible to self, even if not infront ()
=============
*/
float (entity targ) visible =
{
	local vector	spot1, spot2;
	
	spot1 = self.origin + self.view_ofs;
	spot2 = targ.origin + targ.view_ofs;
	traceline (spot1, spot2, TRUE, self);	// see through other monsters
	
	if (trace_inopen && trace_inwater)
		return FALSE;			// sight line crossed contents

	if (trace_fraction == 1)
		return TRUE;
	return FALSE;
};


// -----------------------------------------
void() bot_walkmove =
// -----------------------------------------
{

	self.angles_y = vectoyaw(self.goalentity.origin - self.origin);

	if (walkmove(self.angles_y, 20) == FALSE)
	{
		if (random() < 0.3)
		{
			//back_up1();
			return;
		}
	}
	else
	{
		self.flags = self.flags - (self.flags & FL_ONGROUND);
		makevectors(self.angles);
		self.velocity = self.velocity + (v_forward * self.speed);
		return;
	}	

	if (!(self.flags & FL_ONGROUND))
		return;

	self.flags = self.flags - (self.flags & FL_ONGROUND);
	self.velocity_z = 250;
	makevectors(self.angles);
	self.velocity = v_forward * -250;
	if (random() < 0.4)
		self.velocity = self.velocity + (v_right * 250);
		else self.velocity = self.velocity + (v_right * -250);

};



// ------------------------------------------------
void() bot_search_for_items =
// ------------------------------------------------
{
local entity item;

// he gives up on that item and marks it to avoid it for a while
	if (time > self.search_time && self.goalentity != world)
	{
		self.goalentity.search_time = time + 30;
		self.goalentity = world;
	}

	if (self.goalentity != world)
		return;

// checks a radius around him for items
	item = findradius(self.origin, 1500);

	while(item)
	{
		if ( (item.flags & FL_ITEM) && visible(item) && item.model != string_null && time > item.search_time)
			{
			self.search_time = time + 30;
			self.goalentity = item;
			}
		item = item.chain;
	}

};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void() bot_grab_items =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{

// sees if he's close enough to pick that item up

	if (self.goalentity == world)
		return;

	if (vlen(self.origin - self.goalentity.origin) <= 70)
	{
		self.goalentity.search_time = time + 60;
		self.goalentity.solid = SOLID_NOT;
		self.goalentity.model = string_null;
		self.goalentity.nextthink = time + 20;
		self.goalentity.think = SUB_regen;
		 if (self.goalentity.weapon)
			sound (self, CHAN_ITEM, "weapons/pkup.wav", 1, ATTN_NORM);
		else
			sound(self, CHAN_ITEM, "items/armor1.wav", 1, ATTN_NORM);
		self.goalentity = world;
	}

};

// -----------------------------------------
void() jump_forward =
// -----------------------------------------
{
// propels him into the air

	if (!(self.flags & FL_ONGROUND))
		return;

	self.flags = self.flags - (self.flags & FL_ONGROUND);
	makevectors(self.angles);
	self.velocity = self.velocity + (v_forward * 200);
	self.velocity_z = self.velocity_z + 350;

};


// ------------------------------------------------
void() check_for_water =
// ------------------------------------------------
{
local float p;

// bots don't see water like players do, so we check for it

	makevectors(self.angles);
	p = pointcontents(self.origin + v_forward*16);
	if (p != CONTENT_WATER && p != CONTENT_SLIME && p != CONTENT_LAVA)
		return;

	if (p == CONTENT_WATER && time > self.pain_finished)
		{
		T_Damage (self, world, world, 5);
		self.pain_finished = time + 2;
		sound (self, CHAN_VOICE, "player/gasp2.wav", 1, ATTN_NORM);
		}
	if (p == CONTENT_SLIME && time > self.pain_finished)
		{
		T_Damage (self, world, world, 10);
		self.pain_finished = time + 1;
		sound (self, CHAN_VOICE, "player/lburn2.wav", 1, ATTN_NORM);
		}
	if (p == CONTENT_LAVA && time > self.pain_finished)
		{
		T_Damage (self, world, world, 20);
		self.pain_finished = time + 0.5;
		sound (self, CHAN_VOICE, "player/lburn1.wav", 1, ATTN_NORM);
		}

	self.flags = self.flags - (self.flags & FL_ONGROUND);

// he'll try to swim upward here
	self.velocity = self.velocity + (v_forward * 200);
	self.velocity_z = self.velocity_z + 200;
	if (random() < 0.4)
		self.velocity_x = self.velocity_x + 100;
	else if (random() > 0.8)
		self.velocity_y = self.velocity_y + 100;

};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void() check_for_ledge =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
local vector spot;

// movetogoal() will never move over a legde, so we have to 
// check for a break in front of him and force him to jump

	if (random() < 0.80)
		return;

	if (!(self.flags & FL_ONGROUND))
		return;

	makevectors (self.angles);
	spot = self.origin + (v_forward * 60);
	spot = spot - '0 0 35';
	if (pointcontents(spot) == CONTENT_EMPTY)
	{
		//self.frame = 98;
		//bot_jump1();
		jump_forward();
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float() bot_look_for_players =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	local entity	client;
	local float		r;

// this is just like id's FindTarget(), he's looking for clients

	client = checkclient ();
	if (!client)
		return FALSE;

	if (self.team == client.team)
			return FALSE;

	if (client.netname == "observer")
		return FALSE;
	
	if (client == self.enemy)
		return FALSE;

	if (client.flags & FL_NOTARGET)
		return FALSE;
	if(client.view_ofs == '0 0 0' || client.menu_team_on)
		return FALSE;
	r = range (client);
	if (r == RANGE_FAR)
		return FALSE;
		
	if (!visible (client))
		return FALSE;

	if (r == RANGE_NEAR)
	{
		if (!infront (client))
			return FALSE;
	}
	else if (r == RANGE_MID)
	{
		if (!infront (client))
			return FALSE;
	}
	
	self.enemy = client;
	
	FoundTarget ();
	return TRUE;
};

// ------------------------------------------------
void() bot_look_for_bots =
// ------------------------------------------------
{
	local entity found, foe;

// bots aren't clients, so we have to check fo them manually
// we just see if any of the bots in the entity list are visible

	if (self.enemy)
		return;

	found = world;
	foe = find(world, classname, "bot");

	while(foe)
	{
		if (visible(foe) && foe != self && foe.health > 0) 
			found = foe;
		if (teamplay && found.team == self.team)
			found = world;
		foe = find(foe, classname, "bot");
	}

	if (found != world)
	{
		self.enemy = found;
		self.goalentity = found;
		self.th_run();
	}	
};

// ----------------------
void() bot_face =
// ----------------------
{
// this turns him directly toward his enemy
	 self.angles_y = vectoyaw(self.enemy.origin - self.origin);	
};

// ----------------------
void() bot_stand =
// ----------------------
{

// his standing thoughts, pretty simple

	//bot_look_for_bots();
	//bot_look_for_players();
	//check_for_water();

	if (time > self.pausetime)
	{
		self.th_walk();
		return;
	}
	
// do a cute little turn
	if (random() < 0.1)
		self.angles_y = self.angles_y - 45;
	else if (random() > 0.9)
		self.angles_y = self.angles_y + 15;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void() bot_walk =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	

// this is his main AI routine, where he will look for items and enemies

	if (!(self.flags & FL_ONGROUND))
		return;

	//bot_look_for_bots();
	bot_look_for_players();
	//bot_search_for_items();
	//bot_grab_items();
	//check_for_ledge();
	//check_for_water();


	entity pl = find(world, classname, "player");
	if(pl.health <= 0)
		 pl = find(world, classname, "info_player_deathmatch");
	vector pf = pathfind(self.origin + '0 0 28', pl.origin + '0 0 28');
	self.ideal_yaw = vectoyaw(pf - self.origin);
	ChangeYaw();
	movetogoal(15);
};

// --------------------------------
void() bot_run_slide =
// --------------------------------
{
	local float	ofs;
	
// this is a cool strafing routine

	if (self.lefty)
		ofs = 45;
	else
		ofs = -45;

	if (walkmove (self.angles_y + ofs, 15))
		return;
		
	self.lefty = 1 - self.lefty;
	
	walkmove (self.angles_y - ofs, 15);

};

// ----------------------
void() bot_strafe =
// ----------------------
{
// this routine is called every frame during combat, 
// so he strafes and dodges even while shooting


	//bot_check_ammo();

	if (!visible(self.enemy))
		{
			movetogoal(20);
			return;
		}

	bot_face();


// stepping backwards for a long distance shot
	//if (self.weapon == IT_ROCKET_LAUNCHER)
	//	{
	//	if (walkmove (self.angles_y - 180, 20) == FALSE)
			bot_run_slide();
	//	}

// chasing the player here
	//else if (self.weapon == IT_SUPER_SHOTGUN)
	//	movetogoal(20);
//make skill to bots
// standing still while attacking
	//else if (self.weapon == IT_SHOTGUN)
	//	return;

	//else bot_run_slide();

};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void() bot_run =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{

// his fighting thoughts. after a short while, he'll give up 
// on his enemy, but if he can see him, he'll always attack

	if (!(self.flags & FL_ONGROUND))
		return;

	check_for_water();

	if (visible(self.enemy))
		self.search_time = time + 6;

	if (time > self.search_time || self.enemy.health <= 0)
		{
			self.goalentity = world;
			self.enemy = world;
			self.pausetime = time + 4;
			self.th_stand();
			return;
		}

	bot_strafe();

	if (visible(self.enemy) && time > self.attack_finished)
		self.th_missile();

};

/*
==========================================================================
==========================================================================
==========================================================================

	Section 2: Weapons

	This section is the simplest, basically dull stuff. It checks for
	his best weapon and sets the relevant ammo. It gives him a free
	weapon. And it does the actual firing of the weapons. The key
	difference between a player weapon routine and a bot weapon 
	routine is the aiming. In player routines, you'll see a line
	like this:

		dir = aim (self, 100000);

	If you want a bot to share that subroutine, basically all you need
	to do is change it to this:

		if (self.classname == "player")
			dir = aim (self, 100000);
			else dir = normalize(self.enemy.origin - self.origin);
			
	This allows the bot to aim directly at his enemy.


==========================================================================
==========================================================================
==========================================================================
*/


void() bot_run1;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void() bot_drop_pack =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
	//if (random () < 0.5)
	//	DropBackpack();
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void(entity targ) give_random_weapon =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
local float it;

	it = floor(random() * 2);

	if (it == 0)
	{
		//targ.items = targ.items | IT_SHOTGUN;
		//targ.currentammo = targ.ammo_shells = targ.ammo_shells + 25;
		targ.weapon = IT_GLOCK;
	}
	else if(it == 1)
	{
		targ.weapon = IT_USP;
	}
	else
	{
		targ.weapon = IT_DEAGLE;
	}
};

// --------------------------------
void() bot_set_currentammo =
// --------------------------------
{
	/*
	self.items = self.items - ( self.items & (IT_SHELLS | IT_NAILS | IT_ROCKETS | IT_CELLS) );
	
       if (self.weapon == IT_SHOTGUN)
	{
		self.currentammo = self.ammo_shells;
		self.items = self.items | IT_SHELLS;
	}
	else if (self.weapon == IT_SUPER_SHOTGUN)
	{
		self.currentammo = self.ammo_shells;
		self.items = self.items | IT_SHELLS;
	}
	else if (self.weapon == IT_NAILGUN)
	{
		self.currentammo = self.ammo_nails;
		self.items = self.items | IT_NAILS;
	}
	else if (self.weapon == IT_SUPER_NAILGUN)
	{
		self.currentammo = self.ammo_nails;
		self.items = self.items | IT_NAILS;
	}
	else if (self.weapon == IT_ROCKET_LAUNCHER)
	{
		self.currentammo = self.ammo_rockets;
		self.items = self.items | IT_ROCKETS;
	}
	else if (self.weapon == IT_LIGHTNING)
	{
		self.currentammo = self.ammo_cells;
		self.items = self.items | IT_CELLS;
	}
	else
	{
		self.currentammo = 0;
		self.weaponmodel = "";
		self.weaponframe = 0;
	}
	*/
};


// -------------------------
void() bot_check_ammo =
// -------------------------
{
local float chance;

	if (self.currentammo > 0)
		return;

	//if (self.weapon == IT_SHOTGUN)
	//	return;

	//self.weapon = bot_bestweapon();

	//bot_set_currentammo();
	
	//bot_run1();
};



// -------------------------------------
vector() bot_aim_at_enemy =
// -------------------------------------
{
	return normalize(self.enemy.origin - self.origin);
};

// movement animation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void() bot_stand1		=[	$stand1,	bot_stand2	] {};
void() bot_stand2		=[	$stand2,	bot_stand3	] {bot_face();bot_attack();};
void() bot_stand3		=[	$stand3,	bot_stand4	] {};
void() bot_stand4		=[	$stand4,	bot_stand5	] {};
void() bot_stand5		=[	$stand5,	bot_stand1	] {};

void()	bot_walk1=[63, bot_walk2]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk2=[64, bot_walk3]{self.nextthink = time + 0.02;};
void()	bot_walk3=[65, bot_walk4]{self.nextthink = time + 0.02;};
void()	bot_walk4=[66, bot_walk5]{self.nextthink = time + 0.02;};
void()	bot_walk5=[67, bot_walk6]{self.nextthink = time + 0.02;};
void()	bot_walk6=[68, bot_walk7]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk7=[69, bot_walk8]{self.nextthink = time + 0.02;};
void()	bot_walk8=[70, bot_walk9]{self.nextthink = time + 0.02;};
void()	bot_walk9=[71, bot_walk10]{self.nextthink = time + 0.02;};
void()	bot_walk10=[72, bot_walk11]{self.nextthink = time + 0.02;};
void()	bot_walk11=[73, bot_walk12]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk12=[74, bot_walk13]{self.nextthink = time + 0.02;};
void()	bot_walk13=[75, bot_walk14]{self.nextthink = time + 0.02;};
void()	bot_walk14=[76, bot_walk15]{self.nextthink = time + 0.02;};
void()	bot_walk15=[77, bot_walk16]{self.nextthink = time + 0.02;};
void()	bot_walk16=[78, bot_walk17]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk17=[79, bot_walk18]{self.nextthink = time + 0.02;};
void()	bot_walk18=[80, bot_walk19]{self.nextthink = time + 0.02;};
void()	bot_walk19=[81, bot_walk20]{self.nextthink = time + 0.02;};
void()	bot_walk20=[82, bot_walk21]{self.nextthink = time + 0.02;};
void()	bot_walk21=[83, bot_walk22]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk22=[84, bot_walk23]{self.nextthink = time + 0.02;};
void()	bot_walk23=[85, bot_walk24]{self.nextthink = time + 0.02;};
void()	bot_walk24=[86, bot_walk25]{self.nextthink = time + 0.02;};
void()	bot_walk25=[87, bot_walk26]{self.nextthink = time + 0.02;};
void()	bot_walk26=[88, bot_walk27]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk27=[89, bot_walk28]{self.nextthink = time + 0.02;};
void()	bot_walk28=[90, bot_walk29]{self.nextthink = time + 0.02;};
void()	bot_walk29=[91, bot_walk30]{self.nextthink = time + 0.02;};
void()	bot_walk30=[92, bot_walk31]{self.nextthink = time + 0.02;};
void()	bot_walk31=[93, bot_walk32]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk32=[94, bot_walk33]{self.nextthink = time + 0.02;};
void()	bot_walk33=[95, bot_walk34]{self.nextthink = time + 0.02;};
void()	bot_walk34=[96, bot_walk35]{bot_walk();self.nextthink = time + 0.02;};
void()	bot_walk35=[97, bot_walk1]{self.nextthink = time + 0.02;};


/*
void() bot_walk1=
{
	if(self.frame == 63 || self.frame == 68 || self.frame == 73 || self.frame == 78 )
		bot_walk();
	if(self.frame == 83 || self.frame == 88 || self.frame == 93 || self.frame == 96 )
		bot_walk();
	self.frame += 1;
	self.think = bot_walk1;
	self.nextthink = time + 0.02;
	if(self.frame == 97)
	{
		self.frame = 63;
		bot_walk1();
	}
}
*/
void()  bot_run1		=[	$rockrun1,	bot_run2	] {bot_run();};
void()  bot_run2		=[	$rockrun2,	bot_run3	] {bot_run();};
void()  bot_run3		=[	$rockrun3,	bot_run4	] {bot_run();};
void()  bot_run4		=[	$rockrun4,	bot_run5	] {bot_run();};
void()  bot_run5		=[	$rockrun5,	bot_run6	] {bot_run();};
void()  bot_run6		=[	$rockrun6,	bot_run1	] {bot_run();};

/*
void()  bot_jump1		=[	$rockrun1,	bot_jump2	] {jump_forward();};
void()  bot_jump2		=[	$rockrun1,	bot_jump3	] {};
void()  bot_jump3		=[	$rockrun1,	bot_jump4	] {};
void()  bot_jump4		=[	$rockrun1,	bot_jump5	] {};
void()  bot_jump5		=[	$rockrun1,	bot_walk1	] {};
*/
void()  bot_jump1=
{
		if(self.frame == 108)
			jump_forward();
		if(self.frame == 158)
		{
			//bot_walk1();
			return;
		}
		self.frame += 1;
		self.think = bot_jump1;
		self.nextthink = time + 0.01;
		
}
// attack animation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void()  bot_rock1		=[	$rockatt1,	bot_rock2	] {bot_strafe();};
void()  bot_rock2		=[	$rockatt2,	bot_rock3	] {bot_strafe();};
void()  bot_rock3		=[	$rockatt3,	bot_rock4	] {bot_strafe();};
void()  bot_rock4		=[	$rockatt4,	bot_rock5	] {bot_strafe();};
void()  bot_rock5		=[	$rockatt5,	bot_rock6	] {bot_strafe();};
void()  bot_rock6		=[	$rockatt6,	bot_run1	] {bot_strafe();};

void()  bot_shot1		=[	$shotatt1,	bot_shot2	] {bot_strafe();};
void()  bot_shot2		=[	$shotatt2,	bot_shot3	] {bot_strafe();};
void()  bot_shot3		=[	$shotatt3,	bot_shot4	] {bot_strafe();};
void()  bot_shot4		=[	$shotatt4,	bot_shot5	] {bot_strafe();};
void()  bot_shot5		=[	$shotatt5,	bot_shot6	] {bot_strafe();};
void()  bot_shot6		=[	$shotatt6,	bot_run1	] {bot_strafe();};

void()  bot_nail1		=[	$nailatt1,	bot_nail2	] {bot_strafe();};
void()  bot_nail2		=[	$nailatt2,	bot_nail3	] {bot_strafe();};
void()  bot_nail3		=[	$nailatt1,	bot_nail4	] {bot_strafe();};
void()  bot_nail4		=[	$nailatt2,	bot_nail5	] {bot_strafe();};
void()  bot_nail5		=[	$nailatt1,	bot_nail6	] {bot_strafe();};
void()  bot_nail6		=[	$nailatt2,	bot_run1	] {bot_strafe();};

void()  bot_light1	=[	$light1,	bot_light2	] {bot_strafe();};
void()  bot_light2	=[	$light2,	bot_light3	] {bot_strafe();};
void()  bot_light3	=[	$light1,	bot_light4	] {bot_strafe();};
void()  bot_light4	=[	$light2,	bot_light5	] {bot_strafe();};
void()  bot_light5	=[	$light1,	bot_light6	] {bot_strafe();};
void()  bot_light6	=[	$light2,	bot_run1	] {bot_strafe();};

void()  back_up1		=[	$rockrun1,	back_up2	] {walkmove(self.angles_y - 180, 20);};
void()  back_up2		=[	$rockrun2,	back_up3	] {walkmove(self.angles_y - 180, 20);};
void()  back_up3		=[	$rockrun3,	back_up4	] {walkmove(self.angles_y - 180, 20);};
void()  back_up4		=[	$rockrun4,	back_up5	] {walkmove(self.angles_y - 180, 20);};
void()  back_up5		=[	$rockrun5,	back_up6	] {walkmove(self.angles_y - 180, 20);};
void()  back_up6		=[	$rockrun1,	back_up7	] {walkmove(self.angles_y - 90, 20);};
void()  back_up7		=[	$rockrun2,	back_up8	] {walkmove(self.angles_y - 90, 20);};
void()  back_up8		=[	$rockrun3,	back_up9	] {walkmove(self.angles_y - 90, 20);};
void()  back_up9		=[	$rockrun4,	back_up10	] {walkmove(self.angles_y - 90, 20);};
void()  back_up10		=[	$rockrun5,	bot_walk1	] {walkmove(self.angles_y - 90, 20);};



void() th_respawn =
{
	//self.think = respawn_bot;
	//self.nextthink = time + 1;
};


void()	bot_die_anim=[159, bot_die_anim2]{self.nextthink = time + 0.02;};
void()	bot_die_anim2=[160, bot_die_anim3]{self.nextthink = time + 0.02;};
void()	bot_die_anim3=[161, bot_die_anim4]{self.nextthink = time + 0.02;};
void()	bot_die_anim4=[162, bot_die_anim5]{self.nextthink = time + 0.02;};
void()	bot_die_anim5=[163, bot_die_anim6]{self.nextthink = time + 0.02;};
void()	bot_die_anim6=[164, bot_die_anim7]{self.nextthink = time + 0.02;};
void()	bot_die_anim7=[165, bot_die_anim8]{self.nextthink = time + 0.02;};
void()	bot_die_anim8=[166, bot_die_anim9]{self.nextthink = time + 0.02;};
void()	bot_die_anim9=[167, bot_die_anim10]{self.nextthink = time + 0.02;};
void()	bot_die_anim10=[168, bot_die_anim11]{self.nextthink = time + 0.02;};
void()	bot_die_anim11=[169, bot_die_anim12]{self.nextthink = time + 0.02;};
void()	bot_die_anim12=[170, bot_die_anim13]{self.nextthink = time + 0.02;};
void()	bot_die_anim13=[171, bot_die_anim14]{self.nextthink = time + 0.02;};
void()	bot_die_anim14=[172, bot_die_anim15]{self.nextthink = time + 0.02;};
void()	bot_die_anim15=[173, bot_die_anim16]{self.nextthink = time + 0.02;};
void()	bot_die_anim16=[174, bot_die_anim17]{self.nextthink = time + 0.02;};
void()	bot_die_anim17=[175, bot_die_anim18]{self.nextthink = time + 0.02;};
void()	bot_die_anim18=[176, bot_die_anim19]{self.nextthink = time + 0.02;};
void()	bot_die_anim19=[177, bot_die_anim20]{self.nextthink = time + 0.02;};
void()	bot_die_anim20=[178, bot_die_anim21]{self.nextthink = time + 0.02;};
void()	bot_die_anim21=[179, bot_die_anim22]{self.nextthink = time + 0.02;};
void()	bot_die_anim22=[180, bot_die_anim23]{self.nextthink = time + 0.02;};
void()	bot_die_anim23=[181, bot_die_anim24]{self.nextthink = time + 0.02;};
void()	bot_die_anim24=[182, bot_die_anim25]{self.nextthink = time + 0.02;};
void()	bot_die_anim25=[183, bot_die_anim26]{self.nextthink = time + 0.02;};
void()	bot_die_anim26=[184, bot_die_anim27]{self.nextthink = time + 0.02;};
void()	bot_die_anim27=[185, bot_die_anim28]{self.nextthink = time + 0.02;};
void()	bot_die_anim28=[186, bot_die_anim29]{self.nextthink = time + 0.02;};
void()	bot_die_anim29=[187, bot_die_anim30]{self.nextthink = time + 0.02;};
void()	bot_die_anim30=[188, bot_die_anim31]{self.nextthink = time + 0.02;};
void()	bot_die_anim31=[189, bot_die_anim32]{self.nextthink = time + 0.02;};
void()	bot_die_anim32=[190, bot_die_anim33]{self.nextthink = time + 0.02;};
void()	bot_die_anim33=[191, bot_die_anim34]{self.nextthink = time + 0.02;};
void()	bot_die_anim34=[192, bot_die_anim35]{self.nextthink = time + 0.02;};
void()	bot_die_anim35=[193, bot_die_anim36]{self.nextthink = time + 0.02;};
void()	bot_die_anim36=[194, bot_die_anim37]{self.nextthink = time + 0.02;};
void()	bot_die_anim37=[195, bot_die_anim38]{self.nextthink = time + 0.02;};
void()	bot_die_anim38=[196, bot_die_anim39]{self.nextthink = time + 0.02;};
void()	bot_die_anim39=[197, bot_die_anim40]{self.nextthink = time + 0.02;};
void()	bot_die_anim40=[198, bot_die_anim41]{self.nextthink = time + 0.02;};
void()	bot_die_anim41=[199, th_respawn]{self.nextthink = time + 0.02;};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void(entity attacker, float damage)	bot_pain =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
// get mad at attacker if he's just walking
	if (attacker != self.enemy && attacker != world && self.enemy.classname != "player")
	{
		self.enemy = attacker;
		FoundTarget();
	}

	if (self.pain_finished > time)
		return;

	if (random() < 0.25)
		return;
	
	//PainSound();

	if (random() > 0.75)
		return;
	
	self.pain_finished = time + 1;
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void() bot_die =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{

// we're turning the bot off here and playing his death scene

	self.deadflag = DEAD_DYING;
	self.solid = SOLID_NOT;
	self.flags = self.flags - (self.flags & FL_ONGROUND);
	self.movetype = MOVETYPE_TOSS;
	//if (self.velocity_z < 10)
	//	self.velocity_z = self.velocity_z + random()*300;
	//DeathSound();
	bot_die_anim();
};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void() bot_attack =
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
// this routine decides which animation sequence to play
	local vector vecSrc,vecAcc,vecAim;
	if (time < self.attack_finished)
		return;
	if(self.enemy.health <= 0)
	{
		self.enemy = world;
		self.th_walk();
		return;
	}
	if(!visible(self.enemy))
	{
		self.enemy = world;
		self.th_walk();
		return;
	}
	//self.think = bot_attack;
	//bot_check_ammo();
	if(self.weapon == IT_GLOCK)
	{
		self.attack_finished = time + 0.085;
		DefaultFire(1,21, "weapons/glock18-2.wav" );
	}
	else if(self.weapon == IT_USP)
	{
		self.attack_finished = time + 0.085;
		DefaultFire(1, 30, "weapons/usp1.wav");
	}
	else if(self.weapon == IT_DEAGLE)
	{
		self.attack_finished = time + 0.18;
		DefaultFire(1, 47, "weapons/deagle-1.wav");
	}
/*
	if (self.weapon == IT_SHOTGUN)
		{
			self.attack_finished = time + 0.2;
			bot_fire_shotgun();
		}
	else if (self.weapon == IT_NAILGUN)
		{
			self.attack_finished = time + 0.05;
			bot_fire_nailgun();
		}	
*/	
	/*	
	else if (self.weapon == IT_SUPER_SHOTGUN)
		{
		self.attack_finished = time + 0.7;
		bot_shot1();
		}
	else if (self.weapon == IT_NAILGUN)
		{
		self.attack_finished = time + 0.2;
		bot_nail1();
		}
	else if (self.weapon == IT_SUPER_NAILGUN)
		{
		self.attack_finished = time + 0.2;
		bot_nail1();
		}
	else if (self.weapon == IT_GRENADE_LAUNCHER)
		{
		self.attack_finished = time + 0.8;
		bot_rock1();
		}
	else if (self.weapon == IT_ROCKET_LAUNCHER)
		{
		self.attack_finished = time + 1;
		bot_rock1();
		}
	else if (self.weapon == IT_LIGHTNING)
		{
		self.attack_finished = time + 0.1;
		bot_light1();
		}
*/

};


// ------------------------------------------------
string() bot_name =
// ------------------------------------------------
{
	local float n;

	n = floor(random() * 11);
	if (n == 0)	return "Nate";
	else if (n == 1) return "Adam";
	else if (n == 2) return "Andy";
	else if (n == 3) return "Chris";
	else if (n == 4) return "Colin";
	else if (n == 5) return "Doug";
	else if (n == 6) return "Gary";
	else if (n == 7) return "Grant";
	else if (n == 8) return "Mark";
	else if (n == 9) return "Uncle Mike";
	else return "Scott";
};
//impulse 101 ct
//impulse 100 t
entity(float teem) BotSpawnPoint =
{

	local	entity spot;
	local	entity thing;
	local	float  pcount;

	if (teem == CT_SIDE)
	{
		spot = lastspawn;
		while (1)
		{
			spot = find(spot, classname, "info_player_start");
			if (spot != world)
			{
				if (spot == lastspawn)
					return lastspawn;
				pcount = 0;
				thing = findradius(spot.origin, 32);
				while(thing)
				{
					if (thing.classname == "player")
						pcount = pcount + 1;
					thing = thing.chain;
				}
				if (pcount == 0)
				{
					lastspawn = spot;
					return spot;
				}
			}
		}
	}
	else if (teem == T_SIDE)
	{
		spot = lastspawn;
		while (1)
		{
			spot = find(spot, classname, "info_player_deathmatch");
			if (spot != world)
			{
				if (spot == lastspawn)
					return lastspawn;
				pcount = 0;
				thing = findradius(spot.origin, 32);
				while(thing)
				{
					if (thing.classname == "player")
						pcount = pcount + 1;
					thing = thing.chain;
				}
				if (pcount == 0)
				{
					lastspawn = spot;
					return spot;
				}
			}
		}
	}	
	spot = find (world, classname, "info_player_start");
	if (!spot)
		error ("PutClientInServer: no info_player_start on level");
	
	return spot;
};
// ------------------------------------------------
void(float teem) create_bot =
// ------------------------------------------------
{
local entity bot, spot, plr;

// initializing the entity
	bot = spawn();
	bot.team = teem;
	spot = BotSpawnPoint(teem);
	bot.origin = spot.origin + '0 0 5';
	bot.angles = spot.angles;
	bot.fixangle = TRUE;	
	bot.solid = SOLID_SLIDEBOX;
	bot.movetype = MOVETYPE_STEP;

// defining his animation
	if(bot.team ==1)
		setmodel(bot, "progs/leet.mdl");
	else
		setmodel(bot, "progs/gign.mdl");
	bot.frame = 62;
	bot.th_stand = bot_stand1;
	bot.th_walk = bot_walk1;
	bot.th_run = bot_run1;
	bot.th_pain = bot_pain;
	bot.th_die = bot_die;
	bot.th_missile = bot_attack;

	give_random_weapon(bot);
	bot.health = 100;
	bot.classname = "bot";

	bot.netname = bot_name();
	bprint(bot.netname);
	bprint(" enters the game\n");

// polishing him up
	setsize (bot, '-16 -16 -32', '16 16 32');
	bot.ideal_yaw = bot.angles * '0 1 0';
	bot.yaw_speed = 15;
	bot.view_ofs = '0 0 28';
	bot.takedamage = DAMAGE_AIM;
	bot.nextthink = time + 5;
	bot.think = bot.th_walk;
};
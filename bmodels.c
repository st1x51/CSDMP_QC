void() func_illusionary =
{
	self.angles = '0 0 0';
	self.movetype = MOVETYPE_NONE;
	self.solid = SOLID_NOT;
	setmodel (self, self.model);
	makestatic (self);
};
void() func_wall_use =
{	
	self.frame = 1 - self.frame;
};

void() func_wall =
{
	self.angles = '0 0 0';
	self.movetype = MOVETYPE_PUSH;
	self.solid = SOLID_BSP;
	self.use = func_wall_use;
	setmodel (self, self.model);
};

float m_flHealth,m_angle,m_flDelay;
.float material; 
vector g_vecAttackDir;
//TODO: make more materials and sounds
//its not like cs,but better then nothing
void() spawn_material=
{
	local entity new;
	local vector tmpvec;
	for(float i = 0;i < 5;i++)
	{
    new = spawn();
    new.origin = self.origin;
	if(self.material == matGlass)
	{
		setmodel (new, "progs/glass.mdl" );
		sound (self, CHAN_AUTO,"debris/bustglass2.wav", 1, ATTN_NORM);	
	}
	if(self.material == matCinderBlock)
	{
		setmodel (new, "progs/cindergibs.mdl" );
		sound (self, CHAN_AUTO,"debris/bustconcrete1.wav", 1, ATTN_NORM);	
	}

	setsize (new, '0 0 0', '0 0 0');
	new.velocity_x = 70 * crandom();
	new.velocity_y = 70 * crandom();
	new.velocity_z = 140 + 70 * random();
	new.movetype = MOVETYPE_BOUNCE;
	new.solid = SOLID_BBOX;
	new.avelocity_x = random()*600;
	new.avelocity_y = random()*600;
	new.avelocity_z = random()*600;
	new.nextthink = time + 2 + random()*3;
	new.think = SUB_Remove;

	self.absmin = self.origin + self.mins;
	self.absmax = self.origin + self.maxs;
	tmpvec_x = self.absmin_x + (random() * (self.absmax_x - self.absmin_x));
	tmpvec_y = self.absmin_y + (random() * (self.absmax_y - self.absmin_y));
	tmpvec_z = self.absmin_z + (random() * (self.absmax_z - self.absmin_z));

	setorigin(new, tmpvec);
	}
	self.model = string_null;
	self.solid = SOLID_NOT;
};
void()Die =
{
	local vector vecSpot;
	local vector vecVelocity;
	
	self.takedamage = DAMAGE_NO;
	self.deadflag = DEAD_DEAD;
	spawn_material();
}
void() BreakTouch =
{
	float flDamage;
	if(other.classname != "player") //|| !IsBreakable())
	{
		self.angles_y = m_angle;
		makevectors(self.angles);
		g_vecAttackDir = v_forward;
		self.takedamage = DAMAGE_NO;
		self.deadflag = DEAD_DEAD;
		Die();
	}
	
	if(self.spawnflags & SF_BREAK_TOUCH)
	{
		flDamage = vlen(other.velocity) * 0.01;
		
		if(flDamage >= self.health)
		{
			self.touch = SUB_Null;
			T_Damage(other,self,self,flDamage); //DMG_CRUSH sound?
		}
	}
	if ((self.spawnflags & SF_BREAK_PRESSURE) && other.absmin.z >= self.maxs.z - 2)
	{
		//DamageSound();
		
		self.think = Die;
		self.touch = SUB_Null;
		
		if(m_flDelay == 0.0)
			m_flDelay = 0.1;
		self.nextthink = time + m_flDelay;
	}
}
void() func_breakable =
{
	if(self.spawnflags & SF_BREAK_TRIGGER_ONLY)
		self.takedamage = DAMAGE_NO;
	else
		self.takedamage = DAMAGE_YES;
	m_flHealth = self.health;
	self.solid = SOLID_BSP;
	self.movetype = MOVETYPE_PUSH;
	m_angle = self.angles_y;
	self.angles_y = 0;
	setmodel(self,self.model);
	self.th_die = Die;
	self.touch = BreakTouch;
	if(self.spawnflags & SF_BREAK_TRIGGER_ONLY)
		self.touch = SUB_Null;
}
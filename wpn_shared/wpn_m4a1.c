void()anim_m4a1_attack=
{
	if(self.weaponframe == 29)
		{
			self.state = 0;
			self.weaponframe = 1;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_m4a1_attack;
	self.nextthink = time + 0.02;
}
void()M4A1_PrimaryAttack=
{
	if(self.m4a1clip <= 0)
	{
		Reload(102); 
		return;
	}
	self.weaponframe = 9;
	self.m4a1clip -= 1;
	anim_m4a1_attack();
	DefaultFire(1,31,"weapons/m4a1-1.wav");
	self.attack_finished = time + 0.0875;
}

void()M4A1_Reload=
{
	if(self.weaponframe == 215) 
	{
		self.weaponframe = 1;
		self.m4a1clip = 30;
		self.currentammo = self.m4a1clip;
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 124)
		sound (self, CHAN_AUTO, "weapons/m4a1_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 160)	
		sound (self, CHAN_AUTO, "weapons/m4a1_clipin.wav", 1, ATTN_NORM);
	if(self.weaponframe == 190)	
		sound (self, CHAN_AUTO, "weapons/m4a1_boltpull.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = M4A1_Reload;
	self.nextthink = time + 0.03;	
}
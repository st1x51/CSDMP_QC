void()m4a1_silencer=
{
	if(self.weaponframe == 60)
	{
		self.wepsequence = 0;
		self.weaponframe = 0;
		self.m4a1silencer = 1;
		self.state = 0;
		UpdateWeapon();
		return;
	}
	if(self.weaponframe == 28)
		sound (self, CHAN_AUTO, "weapons/m4a1_silencer_on.wav", 1, ATTN_NORM);	
	self.weaponframe += 1;
	self.think = m4a1_silencer;
	self.nextthink = time + 0.025;
}
void()m4a1_unsilencer=
{
	if(self.weaponframe == 60)
	{
		self.wepsequence = 7;
		self.weaponframe = 0;
		self.m4a1silencer = 0;
		self.state = 0;
		UpdateWeapon();
		return;
	}
	if(self.weaponframe == 21)
		sound (self, CHAN_AUTO, "weapons/m4a1_silencer_off.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = m4a1_unsilencer;
	self.nextthink = time + 0.025;
}
void()anim_m4a1_attack=
{
	if(self.weaponframe == 30)
	{
		self.state = 0;
		if(self.m4a1silencer)
			self.wepsequence = 0;
		else
			self.wepsequence = 7;
		self.weaponframe = 0;
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
		ReloadM4A1(0); 
		return;
	}

	self.m4a1clip -= 1;
	self.m4a1_fired +=1;

	if(self.m4a1silencer)
	{
		self.wepsequence = 1;
		self.weaponframe = 0;
		DefaultFire(1,31,"weapons/m4a1-1.wav");
	}
	else
	{
		self.wepsequence = 8;
		self.weaponframe = 0;
		DefaultFire(1,31,"weapons/m4a1_unsil-1.wav");
	}
	anim_m4a1_attack();
	self.attack_finished = time + 0.0875;
}

void()M4A1_Reload=
{
	if(self.weaponframe == 113) 
	{
		if(self.m4a1silencer)
			self.wepsequence = 0;
		else
			self.wepsequence = 7;
		self.weaponframe = 0;
		UpdateWeapon();
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 25)
		sound (self, CHAN_AUTO, "weapons/m4a1_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 53)	
		sound (self, CHAN_AUTO, "weapons/m4a1_clipin.wav", 1, ATTN_NORM);
	if(self.weaponframe == 88)	
		sound (self, CHAN_AUTO, "weapons/m4a1_boltpull.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = M4A1_Reload;
	self.nextthink = time + 0.03;	
}
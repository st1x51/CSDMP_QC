
void()anim_glock_attack=
{
	if(self.weaponframe == 20)
	{
		self.wepsequence = 0;
		self.weaponframe = 0;
		self.state = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = anim_glock_attack;
	self.nextthink = time + 0.03;
}
//change this shit
void()anim_burst_glock_attack=
{
	if(self.weaponframe == 30)
	{
		self.wepsequence = 0;
		self.weaponframe = 0;
		return;
	}		
	if(self.weaponframe == 2)	
	{
		if(self.glockclip >= 3)
		{
			self.glockclip -=1;
			self.glock_fired +=1;
			DefaultFire(1,21,"weapons/glock18-2.wav");
		}
	}
	if(self.weaponframe == 4)
	{
		if(self.glockclip >= 2)
		{
			self.glockclip -=1;
			self.glock_fired +=1;
			DefaultFire(1,21,"weapons/glock18-2.wav");
		}
	}
	if(self.weaponframe == 6)
	{
		if(self.glockclip >= 1)
		{
			self.glockclip -=1;
			self.glock_fired +=1;
			DefaultFire(1,21,"weapons/glock18-2.wav");
		}
	}
	self.weaponframe += 1;
	self.think = anim_burst_glock_attack;
	self.nextthink = time + 0.02;
}
void() Glock_Reload=
{
	if(self.weaponframe == 75) 
	{
		self.wepsequence = 0;
		self.weaponframe = 0;
		UpdateWeapon();
		self.state = 0;
		return;
	}

	if(self.weaponframe  == 16)
		sound (self, CHAN_AUTO, "weapons/clipout1.wav", 1, ATTN_NORM);	
	if(self.weaponframe  == 48)
		sound (self, CHAN_AUTO, "weapons/clipin1.wav", 1, ATTN_NORM);		
	if(self.weaponframe  == 62)
		sound (self, CHAN_AUTO, "weapons/sliderelease1.wav", 1, ATTN_NORM);			
	self.weaponframe += 1;
	self.think = Glock_Reload;
	self.nextthink = time + 0.035;
}
void()GLOCK_Attack=
{
	if(self.glockclip == 0)
	{
		ReloadWeaponGlock(0); 
		return;
	}
	if(self.autofire == 0)
	{
		self.attack_finished = time + 0.2;
		DefaultFire(1,21, "weapons/glock18-2.wav" );
		self.wepsequence = 5;
		self.weaponframe = 0;
		anim_glock_attack();
		self.glockclip -=1;
		self.glock_fired +=1;
	}
	else
	{
		self.attack_finished = time + 1;
		self.wepsequence = 4;
		self.weaponframe = 0;
		anim_burst_glock_attack();
	}	
}
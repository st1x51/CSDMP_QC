
void()anim_glock_attack=
{
	if(self.weaponframe == 102)
		{
			self.weaponframe = 1;
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
	if(self.weaponframe == 63)
	{
		self.weaponframe = 1;
		return;
	}		
	if(self.weaponframe == 35)	
	{
		if(self.glockclip >= 3)
		{
			self.glockclip -=1;
			self.glock_fired +=1;
			DefaultFire(1,21,"weapons/glock18-2.wav");
		}
	}
	if(self.weaponframe == 37)
	{
		if(self.glockclip >= 2)
		{
			self.glockclip -=1;
			self.glock_fired +=1;
			DefaultFire(1,21,"weapons/glock18-2.wav");
		}
	}
	if(self.weaponframe == 39)
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
	if(self.weaponframe == 212) 
	{
		self.weaponframe = 1;
		UpdateWeapon();
		self.state = 0;
		return;
	}
	if(self.weaponframe  == 154)
		sound (self, CHAN_AUTO, "weapons/clipout1.wav", 1, ATTN_NORM);	
	if(self.weaponframe  == 188)
		sound (self, CHAN_AUTO, "weapons/clipin1.wav", 1, ATTN_NORM);		
	if(self.weaponframe  == 205)
		sound (self, CHAN_AUTO, "weapons/sliderelease1.wav", 1, ATTN_NORM);			
	self.weaponframe += 1;
	self.think = Glock_Reload;
	self.nextthink = time + 0.035;
}
void()GLOCK_Attack=
{
	if(self.glockclip == 0)
	{
		ReloadWeaponGlock(144); 
		return;
	}
	if(self.autofire == 0)
	{
		self.attack_finished = time + 0.2;
		DefaultFire(1,21, "weapons/glock18-2.wav" );
		self.weaponframe = 94;
		anim_glock_attack();
		self.glockclip -=1;
		self.glock_fired +=1;
	}
	else
	{
		self.attack_finished = time + 1;
		self.weaponframe = 33;
		anim_burst_glock_attack();
	}	
}
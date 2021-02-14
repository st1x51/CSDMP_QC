void()anim_deagle_attack=
{
	if(self.weaponframe == 23)
		{
			self.state = 0;
			self.wepsequence = 0;
			self.weaponframe = 0;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_deagle_attack;
	self.nextthink = time + 0.01;
}
void() Deagle_Reload=
{
	if(self.weaponframe == 65) 
	{
		self.wepsequence = 0;
		self.weaponframe = 0;
		UpdateWeapon();
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 14)
		sound (self, CHAN_AUTO, "weapons/de_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 34)
		sound (self, CHAN_AUTO, "weapons/de_clipin.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = Deagle_Reload;
	self.nextthink = time + 0.035;
}
void()DEAGLE_Attack=
{
	if(self.deagleclip == 0)
	{
		ReloadWeaponDeagle(0);
		return;
	}
	self.attack_finished = time + 0.18;
	self.wepsequence = 2;
	self.weaponframe = 0;
	anim_deagle_attack();
	DefaultFire(1, 47, "weapons/deagle-1.wav");
	self.deagleclip -=1;
	self.deagle_fired +=1;
}
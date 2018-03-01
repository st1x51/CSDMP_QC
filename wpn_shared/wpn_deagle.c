void()anim_deagle_attack=
{
	if(self.weaponframe == 25)
		{
			self.state = 0;
			self.weaponframe = 1;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_deagle_attack;
	self.nextthink = time + 0.01;
}
void() Deagle_Reload=
{
	if(self.weaponframe == 113) 
	{
		self.weaponframe = 1;
		self.deagleclip = 7;
		self.ammo_deagle -=7;
		UpdateWeapon();
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 68)
		sound (self, CHAN_AUTO, "weapons/de_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 94)
		sound (self, CHAN_AUTO, "weapons/de_clipin.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = Deagle_Reload;
	self.nextthink = time + 0.035;
}
void()DEAGLE_Attack=
{
	if(self.deagleclip == 0)
	{
		Reload(51);
		return;
	}
	self.attack_finished = time + 0.18;
	self.weaponframe = 1;
	anim_deagle_attack();
	DefaultFire(1, 47, "weapons/deagle-1.wav");
	self.deagleclip -=1;
}
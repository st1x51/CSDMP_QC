void()anim_galil_attack=
{
	if(self.weaponframe == 30)
	{
		self.state = 0;
		self.sequence = 0;
		self.weaponframe = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = anim_galil_attack;
	self.nextthink = time + 0.03;
}
void()Galil_Reload=
{
	if(self.weaponframe == 15)
		sound (self, CHAN_AUTO, "weapons/galil_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 47)
		sound (self, CHAN_AUTO, "weapons/galil_clipin.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 65)
		sound (self, CHAN_AUTO, "weapons/galil_boltpull.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 90)
	{
		self.state = 0;
		UpdateWeapon();
		self.sequence = 0;
		self.weaponframe = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = Galil_Reload;
	self.nextthink = time + 0.03;
}

void()Galil_PrimaryAttack=
{
	if(self.galilclip <= 0)
	{
		ReloadGalil(0); 
		return;
	}
	self.sequence = 3;
	self.weaponframe = 0;
	self.galilclip -= 1;
	self.galil_fired += 1;
	anim_galil_attack();
	DefaultFire(1,29,"weapons/galil-1.wav");
	self.attack_finished = time + 0.0875;	
}
void()anim_galil_attack=
{
	if(self.weaponframe == 220)
	{
		self.state = 0;
		self.weaponframe = 1;
		return;
	}
	self.weaponframe += 1;
	self.think = anim_galil_attack;
	self.nextthink = time + 0.03;
}
void()Galil_Reload=
{
	if(self.weaponframe == 17)
		sound (self, CHAN_AUTO, "weapons/galil_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 52)
		sound (self, CHAN_AUTO, "weapons/galil_clipin.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 69)
		sound (self, CHAN_AUTO, "weapons/galil_boltpull.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 92)
	{
		self.state = 0;
		self.galilclip = 35;
		self.currentammo = self.galilclip;
		self.weaponframe = 1;
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
		Reload(2); 
		return;
	}
	self.weaponframe = 190;
	self.galilclip -= 1;
	anim_galil_attack();
	DefaultFire(1,29,"weapons/galil-1.wav");
	self.attack_finished = time + 0.0875;	
}
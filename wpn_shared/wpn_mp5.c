void()anim_mp5_attack=
{
	if(self.weaponframe == 20)
	{
		self.state = 0;
		self.sequence = 0;
		self.weaponframe = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = anim_mp5_attack;
	self.nextthink = time + 0.03;
}
void()Mp5_Reload=
{
	if(self.weaponframe == 15)
		sound (self, CHAN_AUTO, "weapons/mp5_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 46)
		sound (self, CHAN_AUTO, "weapons/mp5_clipin.wav", 1, ATTN_NORM);
	if(self.weaponframe == 77)
		sound (self, CHAN_AUTO, "weapons/mp5_slideback.wav", 1, ATTN_NORM);
	if(self.weaponframe == 100)
	{
		self.state = 0;
		UpdateWeapon();
		self.sequence = 0;
		self.weaponframe = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = Mp5_Reload;
	self.nextthink = time + 0.03;
}
void()Mp5_PrimaryAttack=
{
	if(self.mp5clip <= 0)
	{
		ReloadMp5(0);
		return;
	}
	self.sequence = 3;
	self.weaponframe = 0;
	self.mp5clip -= 1;
	self.mp5_fired += 1;
	anim_mp5_attack();
	DefaultFire(1,26,"weapons/mp5-1.wav");
	self.attack_finished = time + 0.075;	
}

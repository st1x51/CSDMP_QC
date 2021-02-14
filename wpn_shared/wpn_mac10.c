void()anim_mac10_attack=
{
	if(self.weaponframe == 25)
	{
		self.state = 0;
		self.wepsequence = 0;
		self.weaponframe = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = anim_mac10_attack;
	self.nextthink = time + 0.03;
}
void()Mac10_Reload=
{
	if(self.weaponframe == 22)
		sound (self, CHAN_AUTO, "weapons/mac10_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 55)
		sound (self, CHAN_AUTO, "weapons/mac10_clipin.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 87)
		sound (self, CHAN_AUTO, "weapons/mac10_boltpull.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 110)
	{
		self.state = 0;
		UpdateWeapon();
		self.wepsequence = 0;
		self.weaponframe = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = Mac10_Reload;
	self.nextthink = time + 0.03;
}
void()Mac10_PrimaryAttack=
{
	if(self.mac10clip <= 0)
	{
		ReloadMac10(0); 
		return;
	}
	self.wepsequence = 3;
	self.weaponframe = 0;
	self.mac10clip -= 1;
	self.mac10_fired += 1;
	anim_mac10_attack();
	DefaultFire(1,29,"weapons/mac10-1.wav");
	self.attack_finished = time + 0.07;	
}
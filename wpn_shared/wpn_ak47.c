void()anim_ak47_attack=
{
	if(self.weaponframe == 156)
		{
			self.state = 0;
			self.weaponframe = 1;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_ak47_attack;
	self.nextthink = time + 0.01;
}
void()AK47_PrimaryAttack=
{
	if(self.ak47clip <= 0)
	{
		Reload(18); 
		return;
	}
	self.weaponframe = 140;
	self.ak47clip -= 1;
	anim_ak47_attack();
	DefaultFire(1,20,"weapons/ak47-1.wav");
	self.attack_finished = time + 0.1;
}

void()AK47_Reload=
{
	if(self.weaponframe == 108) 
	{
		self.weaponframe = 1;
		self.ak47clip = 30;
		self.ammo_ak47 -=30;
		UpdateWeapon();
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 45)
		sound (self, CHAN_AUTO, "weapons/ak47_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 80)	
		sound (self, CHAN_AUTO, "weapons/ak47_clipin.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = AK47_Reload;
	self.nextthink = time + 0.03;	
}

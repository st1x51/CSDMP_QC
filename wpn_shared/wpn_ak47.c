void()anim_ak47_attack=
{
	if(self.weaponframe == 16)
		{
			self.state = 0;
			self.sequence = 0;
			self.weaponframe = 0;
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
		ReloadAK47(18); 
		return;
	}
	self.sequence = 3;
	self.weaponframe = 0;
	self.ak47clip -= 1;
	self.ak47_fired += 1;
	anim_ak47_attack();
	DefaultFire(1,20,"weapons/ak47-1.wav");
	self.attack_finished = time + 0.1;
}

void()AK47_Reload=
{
	if(self.weaponframe == 90) 
	{
		self.sequence = 0;
		self.weaponframe = 1;
		UpdateWeapon();
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 13)
		sound (self, CHAN_AUTO, "weapons/ak47_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 57)	
		sound (self, CHAN_AUTO, "weapons/ak47_clipin.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = AK47_Reload;
	self.nextthink = time + 0.03;	
}

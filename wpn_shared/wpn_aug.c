void()anim_aug_attack=
{
	if(self.weaponframe == 214)
		{
			self.state = 0;
			self.weaponframe = 1;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_aug_attack;
	self.nextthink = time + 0.01;
}
void()Aug_PrimaryAttack=
{
	if(self.augclip <= 0)
	{
		stuffcmd(self,"fov 90\n");
		self.fov = 90;
		self.scope = 0;
		ReloadAug(9); 
		return;
	}
	self.weaponframe = 202;
	self.augclip -= 1;
	self.aug_fired += 1;
	anim_aug_attack();
	DefaultFire(1,32,"weapons/aug-1.wav");
	if(!self.scope)
		self.attack_finished = time + 0.0825;
	else
		self.attack_finished = time + 0.1825;
}

void()Aug_Reload=
{
	if(self.weaponframe == 140) 
	{
		self.weaponframe = 1;
		UpdateWeapon();
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 21)
		sound (self, CHAN_AUTO, "weapons/aug_boltpull.wav", 1, ATTN_NORM);
	if(self.weaponframe == 61)	
		sound (self, CHAN_AUTO, "weapons/aug_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 97)	
		sound (self, CHAN_AUTO, "weapons/aug_clipin.wav", 1, ATTN_NORM);
	if(self.weaponframe == 122)	
		sound (self, CHAN_AUTO, "weapons/aug_boltslap.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = Aug_Reload;
	self.nextthink = time + 0.03;	
}

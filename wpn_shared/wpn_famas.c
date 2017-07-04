void()anim_famas_attack=
{
	if(self.weaponframe == 198)
	{
		self.state = 0;
		self.weaponframe = 1;
		return;
	}
	self.weaponframe += 1;
	self.think = anim_famas_attack;
	self.nextthink = time + 0.01;
}
void()anim_burst_famas_attack=
{
	if(self.weaponframe == 198)
	{
		self.state = 0;
		self.weaponframe = 1;
		return;
	}		
	if(self.weaponframe == 187 || self.weaponframe == 188|| self.weaponframe == 189)	
	{
		self.famasclip -=1;
		DefaultFire(1,29,string_null);
	}
	self.weaponframe += 1;
	self.think = anim_burst_famas_attack;
	self.nextthink = time + 0.02;
}
void()Famas_Reload=
{
	if(self.weaponframe == 19)
		sound (self, CHAN_AUTO, "weapons/famas_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 50)
		sound (self, CHAN_AUTO, "weapons/famas_clipin.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 68)
		sound (self, CHAN_AUTO, "weapons/famas_boltslap.wav", 1, ATTN_NORM);	
	if(self.weaponframe == 90)
	{
		self.state = 0;
		self.famasclip = 25;
		self.currentammo = self.famasclip;
		self.weaponframe = 1;
		return;
	}
	self.weaponframe += 1;
	self.think = Famas_Reload;
	self.nextthink = time + 0.035;
}

void()Famas_PrimaryAttack=
{
	if(self.famasburst == 0)
	{
		if(self.famasclip <= 0)
		{
			Reload(2); 
			return;
		}
		self.weaponframe = 180;
		self.famasclip -= 1;
		anim_famas_attack();
		DefaultFire(1,29,"weapons/famas-1.wav");
		self.attack_finished = time + 0.0825;	
	}
	if(self.famasburst == 1)
	{
		if(self.famasclip <= 0)
		{
			Reload(2); 
			return;
		}
		sound (self, CHAN_AUTO, "weapons/famas-burst.wav", 1, ATTN_NORM);	
		self.weaponframe = 180;
		anim_burst_famas_attack();
		self.attack_finished = time + 0.3825;	
	}
}
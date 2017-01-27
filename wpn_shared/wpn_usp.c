void()UpdateWeapon;
void(float startframe)Reload;
void()usp_silencer=
{
	if(self.weaponframe == 114)
		{
			self.silencer = 1;
			self.state = 0;
			UpdateWeapon();
			return;
		}
	if(self.weaponframe == 40)
		sound (self, CHAN_AUTO, "weapons/usp_silencer_on.wav", 1, ATTN_NORM);	
	self.weaponframe += 1;
	self.think = usp_silencer;
	self.nextthink = time + 0.025;
}
void()usp_unsilencer=
{
	if(self.weaponframe == 247)
		{
			self.silencer = 0;
			self.state = 0;
			UpdateWeapon();
			return;
		}
	if(self.weaponframe == 158)
		sound (self, CHAN_AUTO, "weapons/usp_silencer_off.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = usp_unsilencer;
	self.nextthink = time + 0.025;
}

void()anim_usp_attack_sil=
{
	if(self.weaponframe == 7)
		{
			self.weaponframe = 1;
			self.state = 0;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_usp_attack_sil;
	self.nextthink = time + 0.02;
}
void()anim_usp_attack=
{
	if(self.weaponframe == 122)
		{
			self.weaponframe = 0;
			self.state = 0;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_usp_attack;
	self.nextthink = time + 0.02;
}
void() USP_Reload=
{
	if(self.weaponframe == 246)
	{
		self.weaponframe = 0;
		self.uspclip = 12;
		self.state = 0;
		return;
	}
	if(self.weaponframe  == 237)
		sound (self, CHAN_AUTO, "weapons/usp_sliderelease.wav", 1, ATTN_NORM);
	if(self.weaponframe  == 167)
		sound (self, CHAN_AUTO, "weapons/usp_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe  == 185)
		sound (self, CHAN_AUTO, "weapons/usp_clipin.wav", 1, ATTN_NORM);	
	self.weaponframe += 1;
	self.think = USP_Reload;
	self.nextthink = time + 0.025;
}
void() USP_Silencer_Reload=
{
	if(self.weaponframe == 130)
	{
		self.weaponframe = 1;
		self.uspclip = 12;
		self.currentammo = self.uspclip;
		self.state = 0;
		return;
	}
	if(self.weaponframe  == 122)
		sound (self, CHAN_AUTO, "weapons/usp_sliderelease.wav", 1, ATTN_NORM);
	if(self.weaponframe  == 51)
		sound (self, CHAN_AUTO, "weapons/usp_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe  == 72)
		sound (self, CHAN_AUTO, "weapons/usp_clipin.wav", 1, ATTN_NORM);		
	self.weaponframe += 1;
	self.think = USP_Silencer_Reload;
	self.nextthink = time + 0.025;
} 
void()USP_Attack=
{
	if(self.uspclip == 0)
		{
			self.state = RELOADING;
			if(self.silencer == 1)
				Reload(32);
			else
				Reload(147);
			return;
		}
	self.attack_finished = time + 0.085;
	if(!self.silencer )
	{
		self.weaponframe = 115;
		anim_usp_attack();
		DefaultFire(1, 30, "weapons/usp_unsil-1.wav");
	}
	else
	{
		self.weaponframe = 1;
		anim_usp_attack_sil();
		DefaultFire(1, 30, "weapons/usp1.wav");
	}
	self.uspclip -=1;
}
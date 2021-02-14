void()UpdateWeapon;
void()usp_silencer=
{
	if(self.weaponframe == 115)
		{
			self.silencer = 1;
			self.state = 0;
			UpdateWeapon();
			return;
		}
	if(self.weaponframe == 38)
		sound (self, CHAN_AUTO, "weapons/usp_silencer_on.wav", 1, ATTN_NORM);	
	self.weaponframe += 1;
	self.think = usp_silencer;
	self.nextthink = time + 0.025;
}
void()usp_unsilencer=
{
	if(self.weaponframe == 115)
		{
			self.silencer = 0;
			self.state = 0;
			UpdateWeapon();
			return;
		}
	if(self.weaponframe == 29)
		sound (self, CHAN_AUTO, "weapons/usp_silencer_off.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = usp_unsilencer;
	self.nextthink = time + 0.025;
}

void()anim_usp_attack_sil=
{
	if(self.weaponframe == 30)
		{
			self.wepsequence = 0;
			self.weaponframe = 0;
			self.state = 0;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_usp_attack_sil;
	self.nextthink = time + 0.02;
}
void()anim_usp_attack=
{
	if(self.weaponframe == 30)
		{
			self.wepsequence = 8;
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
	if(self.weaponframe == 100)
	{
		self.wepsequence = 8;
		self.weaponframe = 0;
		UpdateWeapon();
		self.state = 0;
		return;
	}
	if(self.weaponframe  == 90)
		sound (self, CHAN_AUTO, "weapons/usp_sliderelease.wav", 1, ATTN_NORM);
	if(self.weaponframe  == 20)
		sound (self, CHAN_AUTO, "weapons/usp_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe  == 58)
		sound (self, CHAN_AUTO, "weapons/usp_clipin.wav", 1, ATTN_NORM);	
	self.weaponframe += 1;
	self.think = USP_Reload;
	self.nextthink = time + 0.025;
}
void() USP_Silencer_Reload=
{
	if(self.weaponframe == 100)
	{
		self.wepsequence = 0;
		self.weaponframe = 0;
		UpdateWeapon();
		self.state = 0;
		return;
	}
	if(self.weaponframe  == 82)
		sound (self, CHAN_AUTO, "weapons/usp_sliderelease.wav", 1, ATTN_NORM);
	if(self.weaponframe  == 17)
		sound (self, CHAN_AUTO, "weapons/usp_clipout.wav", 1, ATTN_NORM);	
	if(self.weaponframe  == 40)
		sound (self, CHAN_AUTO, "weapons/usp_clipin.wav", 1, ATTN_NORM);		
	self.weaponframe += 1;
	self.think = USP_Silencer_Reload;
	self.nextthink = time + 0.025;
} 

void()USP_Attack=
{
	if(self.uspclip == 0)
		{
			if(self.silencer == 1)
				ReloadWeaponUSP(0);
			else
				ReloadWeaponUSP(0);
			return;
		}
	self.attack_finished = time + 0.15;
	if(!self.silencer )
	{
		self.wepsequence = 9;
		self.weaponframe = 1;
		anim_usp_attack();
		DefaultFire(1, 30, "weapons/usp_unsil-1.wav");
	}
	else
	{
		self.wepsequence = 1;
		self.weaponframe = 1;
		anim_usp_attack_sil();
		DefaultFire(1, 30, "weapons/usp1.wav");
	}
	self.uspclip -=1;
	self.usp_fired +=1;
}
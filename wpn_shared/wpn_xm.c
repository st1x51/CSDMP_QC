void(float cShots,vector vecSrc,vector vecDirShooting,vector vecSpread,float flDistance,float iDamage)FireBullets;
void()anim_xm_attack=
{
	if(self.weaponframe == 20)
	{
		self.sequence = 0;	
		self.weaponframe = 0;
		self.state = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = anim_xm_attack;
	self.nextthink = time + 0.03;
}
void() XM_Reload_End=
{
	if(self.weaponframe == 12) 
	{
        sound (self, CHAN_AUTO, "weapons/reload3.wav", 1, ATTN_NORM);
		self.sequence = 0;
		self.weaponframe = 0;
		UpdateWeapon();
		self.state = 0;
		return;
	}
	self.weaponframe += 1;
	self.think = XM_Reload_End;
	self.nextthink = time + 0.03;
}
void() XM_Reload=
{
	if(self.ammo_xm == 0)
	{	
		if(self.xmclip == xma)
		{
			self.sequence = 4;
			self.weaponframe = 0;
			XM_Reload_End();
			return;
		}
	}
	if(self.xmclip == 7)
	{
		self.sequence = 4;
		self.weaponframe = 0;
		XM_Reload_End();
		return;
	}
	if(self.weaponframe == 20) 
		sound (self, CHAN_AUTO, "weapons/reload1.wav", 1, ATTN_NORM);
	if(self.weaponframe == 35) 
	{
		self.weaponframe = 0;
		self.xmclip += 1;
	}		
	self.weaponframe += 1;
	self.think = XM_Reload;
	self.nextthink = time + 0.015;
}
void() XM_Reload_Start=
{
	if(self.weaponframe == 20) 
	{
        sound (self, CHAN_AUTO, "items/cliprelease1.wav", 1, ATTN_NORM);
		self.sequence = 3;
		self.weaponframe = 0;
		XM_Reload();
		return;
	}		
	self.weaponframe += 1;
	self.think = XM_Reload_Start;
	self.nextthink = time + 0.03;	
}
void()XM_PrimaryAttack=
{
	local vector vecSrc,vecAcc,vecAim;
	if(self.xmclip == 0)
	{
		ReloadWeaponXM(0); 
		return;
	}
	sound (self, CHAN_AUTO, "weapons/xm1014-1.wav", 1, ATTN_NORM);
	self.attack_finished = time + 0.2;
	vecSrc = self.origin + self.view_ofs;
	vecAcc = '0.0725 0.0725 0.0';
	vecAim = GetAutoaimVector(AUTOAIM_2DEGREES);
	FireBullets(6,vecSrc,vecAim,vecAcc,3048,20);
	self.punchangle_x -= 3;
	self.sequence = 2;
	self.weaponframe = 0;
	anim_xm_attack();
	self.xmclip -=1;
	self.currentammo -= 1;
	self.xm_fired += 1;
}
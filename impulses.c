void()ChangeWeapon;
void()KNIFE_SecondaryAttack;
void()usp_unsilencer;
void()usp_silencer;
float()GetWeaponId;
void() CheckImpulses =
{
	if (self.impulse == 121)
		ChangeWeapon ();
	if(self.impulse == 20)	
	{
		if(self.money < GLOCK18_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,GLOCK18_PRICE,BUY);
		bprint("Bought glock \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_GLOCK;
		self.weapon = IT_GLOCK;
		self.glockclip = 20;
		self.ammo_glock = 120;
		UpdateWeapon();
	}
	if(self.impulse == 21)	
	{
		if(self.money < USP_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,USP_PRICE,BUY);
		bprint("Bought usp \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_USP;
		self.weapon = IT_USP;
		self.uspclip = 12;
		self.ammo_45acp = 100;
		UpdateWeapon();
	}
	if(self.impulse == 22)	
	{
		if(self.money < DEAGLE_PRICE)
		{
			sprint(self, "Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,DEAGLE_PRICE,BUY);
		bprint("Bought Deagle \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_DEAGLE;
		self.weapon = IT_DEAGLE;
		self.deagleclip = 7;
		self.ammo_deagle = 35;
		UpdateWeapon();
	}
	if(self.impulse == 41)	
	{
		if(self.he_grenades == 1)
			return;
		if(self.money < HEGRENADE_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,HEGRENADE_PRICE,BUY);
		bprint("Bought HE \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.items = self.items | IT_HEGRENADE;
		self.weapon = IT_HEGRENADE;
		self.he_grenades += 1;
		UpdateWeapon();
	}
	if(self.impulse == 62)	
	{
		if(self.money < M3_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,M3_PRICE,BUY);
		bprint("Bought M3 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_M3;
		self.weapon = IT_M3;
		self.ammo_m3 = 32;
		self.m3clip = 7;
		UpdateWeapon();
	}
	if(self.impulse == 43)
	{
		if(self.money < AK47_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,AK47_PRICE,BUY);
		bprint("Bought AK-47 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_AK47;
		self.weapon = IT_AK47;
		self.ak47clip = 30;
		self.ammo_ak47 = 90;
		UpdateWeapon();
	}
	if(self.impulse == 46)
	{
		if(self.money < AWP_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,AWP_PRICE,BUY);
		bprint("Bought AWP \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_AWP;
		self.weapon = IT_AWP;
		self.awpclip = 10;
		self.ammo_awp = 30;
		self.crosshair = cvar("crosshair");
		UpdateWeapon();	
	}
	if(self.impulse == 89)
	{
		if(self.money < GALIL_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,GALIL_PRICE,BUY);
		bprint("Bought Galil \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_GALIL;
		self.weapon = IT_GALIL;
		self.galilclip = 35;
		self.ammo_galil = 90;
		UpdateWeapon();
	}
	if(self.impulse == 82)
	{
		if(self.money < AUG_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,AUG_PRICE,BUY);
		bprint("Bought AUG \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_AUG;
		self.weapon = IT_AUG;
		self.augclip = 30;
		self.ammo_aug = 90;
		UpdateWeapon();
	}
	if(self.impulse == 84)
	{
		if(self.money < FAMAS_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,FAMAS_PRICE,BUY);
		bprint("Bought Famas \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_FAMAS;
		self.weapon = IT_FAMAS;
		self.famasclip = 25;
		self.ammo_famas = 90;
		UpdateWeapon();
	}
	if(self.impulse == 45)
	{
		if(self.money < M4A1_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,M4A1_PRICE,BUY);
		bprint("Bought M4A1 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_M4A1;
		self.weapon = IT_M4A1;
		self.m4a1clip = 30;
		self.ammo_m4a1 = 90;
		UpdateWeapon();
	}
	if (self.impulse == 94)
	{
		if(self.team == T_SIDE)
			m_iNumTerrorist -= 1;
		if(m_iNumCT == 2)
		{
			bprint("Too many players in team\n");
		}
		else	
		{
			bprint (self.netname);
			bprint (" Joining Counter-Terrorist team\n");
			self.team = CT_SIDE;
			self.m_iTeam = CT;
			PutClientCTInServer();
		}
	}
	if (self.impulse == 54)
	{
		if(self.team == CT_SIDE)
			m_iNumCT -= 1;
		if(m_iNumTerrorist == 2)
		{
			bprint("Too many players in team\n");
		}
		else	
		{
			bprint (self.netname);
			bprint (" Joining Terrorist team\n");
			self.team = T_SIDE;
			self.m_iTeam = TERRORIST;
			PutClientTInServer();
		}
	}
	if(self.impulse == 105)
	{
		if(self.m_bInBuyZone)
		{
			if(self.team == CT_SIDE)
				stuffcmd(self,"menu_buyct \n");
			else
				stuffcmd(self,"menu_buyt \n");
		}
		else
			centerprint(self,"You are not in the buy zone\n");
	}
	
	stop: self.impulse = 0;                              // Clear impulse list.
};
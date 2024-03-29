void()ChangeWeapon;
void()KNIFE_SecondaryAttack;
void()usp_unsilencer;
void()usp_silencer;
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
		self.weapon = IT_GLOCK;
		self.secondaryweapon = IT_GLOCK;
		self.glockclip = 20;
		self.ammo_glock = 120;
		self.glock_fired = 0;
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
		self.weapon = IT_USP;
		self.secondaryweapon = IT_USP;
		self.uspclip = 12;
		self.ammo_45acp = 100;
		self.usp_fired = 0;
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
		self.weapon = IT_DEAGLE;
		self.secondaryweapon = IT_DEAGLE;
		self.deagleclip = 7;
		self.ammo_deagle = 35;
		self.deagle_fired = 0;
		UpdateWeapon();
	}
	if(self.impulse == 23)
	{
		if(self.money < P228_PRICE)
		{
			sprint(self, "Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,P228_PRICE,BUY);
		bprint("Bought P228 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.weapon = IT_P228;
		self.secondaryweapon = IT_P228;
		self.p228clip = 13;
		self.ammo_p228 = 52;
		self.p228_fired = 0;
		UpdateWeapon();
	}
	if(self.impulse == 25)
	{
		if(self.money < ELITE_PRICE)
		{
			sprint(self, "Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,ELITE_PRICE,BUY);
		bprint("Bought Elite \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.weapon = IT_ELITE;
		self.secondaryweapon = IT_ELITE;
		self.eliteclip = 30;
		self.ammo_elite = 120;
		self.elite_fired = 0;
		UpdateWeapon();
	}
	if(self.impulse == 41)
	{
		if(self.he_grenades == 1)
		{
			goto stop;
			return;
		}
		if(self.money < HEGRENADE_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,HEGRENADE_PRICE,BUY);
		bprint("Bought HE \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
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
		self.weapon = IT_M3;
		self.primaryweapon = IT_M3;
		self.ammo_m3 = 32;
		self.m3clip = 7;
		self.m3_fired = 0;
		UpdateWeapon();
	}
	if(self.impulse == 63)
	{
		if(self.money < XM1014_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,XM1014_PRICE,BUY);
		bprint("Bought XM \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.weapon = IT_XM;
		self.primaryweapon = IT_XM;
		self.ammo_xm = 32;
		self.xmclip = 7;
		self.xm_fired = 0;
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
		self.weapon = IT_AK47;
		self.primaryweapon = IT_AK47;
		self.ak47clip = 30;
		self.ammo_ak47 = 90;
		self.ak47_fired = 0;
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
		self.weapon = IT_AWP;
		self.primaryweapon = IT_AWP;
		self.awpclip = 10;
		self.ammo_awp = 30;
		//self.crosshair = cvar("crosshair");
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
		self.weapon = IT_GALIL;
		self.primaryweapon = IT_GALIL;
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
		self.weapon = IT_AUG;
		self.primaryweapon = IT_AUG;
		self.augclip = 30;
		self.ammo_aug = 90;
		self.awp_fired = 0;
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
		self.weapon = IT_FAMAS;
		self.primaryweapon = IT_FAMAS;
		self.famasclip = 25;
		self.ammo_famas = 90;
		self.famas_fired = 0;
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
		self.weapon = IT_M4A1;
		self.primaryweapon = IT_M4A1;
		self.m4a1clip = 30;
		self.ammo_m4a1 = 90;
		self.m4a1_fired = 0;
		UpdateWeapon();
	}
	if(self.impulse == 42)
	{
		if(self.money < MAC10_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,MAC10_PRICE,BUY);
		bprint("Bought MAC10 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.weapon = IT_MAC10;
		self.primaryweapon = IT_MAC10;
		self.mac10clip = 30;
		self.ammo_mac10 = 100;
		self.mac10_fired = 0;
		UpdateWeapon();
	}
	if(self.impulse == 65)
	{
		if(self.money < MP5NAVY_PRICE)
		{
			bprint("Not enough money \n");
			goto stop;
			return;
		}
		AddAccount(self,MP5NAVY_PRICE,BUY);
		bprint("Bought MP5 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.weapon = IT_MP5;
		self.primaryweapon = IT_MP5;
		self.mp5clip = 30;
		self.ammo_mp5 = 120;
		self.mp5_fired = 0;
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
	if(self.impulse == 120)
		use_button();
	if(self.impulse == 122)
	{
		if(self.state > 0)
		{
			goto stop;
			return;
		}
		//todo: move this to wep_reload
		if(self.weapon == IT_USP)
		{
			if(self.silencer == 1)
				ReloadWeaponUSP(0);
			else
				ReloadWeaponUSP(0);
		}
		if(self.weapon == IT_GLOCK)
			ReloadWeaponGlock(0);
		if(self.weapon == IT_M3)
			ReloadWeaponM3(0);
		if(self.weapon == IT_DEAGLE)
			ReloadWeaponDeagle(0);
		if(self.weapon == IT_AK47)
			ReloadAK47(0);
		if(self.weapon == IT_AWP)
			ReloadAWP(0);
		if(self.weapon == IT_GALIL)
			ReloadGalil(0);
		if(self.weapon == IT_AUG)
			ReloadAug(0);
		if(self.weapon == IT_FAMAS)
			ReloadFamas(0);
		if(self.weapon == IT_M4A1)
			ReloadM4A1(0);
		if(self.weapon == IT_MAC10)
			ReloadMac10(0);
		if(self.weapon == IT_MP5)
			ReloadMp5(0);
	}

	if(self.impulse == 125)
	{
		if (time < m_flNextDecalTime)
		{
			goto stop;
			return;
		}
		m_flNextDecalTime = time + 30;
		CSprayCan();
	}

	stop: self.impulse = 0;                              // Clear impulse list.
};

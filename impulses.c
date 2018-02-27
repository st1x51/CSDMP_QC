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
		bprint("Bought glock \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_GLOCK;
		self.weapon = IT_GLOCK;
		self.glockclip = 20;
		UpdateWeapon();
	}
	if(self.impulse == 21)	
	{
		bprint("Bought usp \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_USP;
		self.weapon = IT_USP;
		self.uspclip = 12;
		UpdateWeapon();
	}
	if(self.impulse == 22)	
	{
		bprint("Bought Deagle \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_DEAGLE;
		self.weapon = IT_DEAGLE;
		self.deagleclip = 7;
		UpdateWeapon();
	}
	if(self.impulse == 41)	
	{
		if(self.he_grenades == 1)
			return;
		bprint("Bought HE \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.items = self.items | IT_HEGRENADE;
		self.weapon = IT_HEGRENADE;
		self.he_grenades += 1;
		UpdateWeapon();
	}
	if(self.impulse == 62)	
	{
		bprint("Bought M3 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_M3;
		self.weapon = IT_M3;
		self.m3clip = 7;
		UpdateWeapon();
	}
	if(self.impulse == 43)
	{
		bprint("Bought AK-47 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_AK47;
		self.weapon = IT_AK47;
		self.ak47clip = 30;
		UpdateWeapon();
	}
	if(self.impulse == 46)
	{
		bprint("Bought AWP \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_AWP;
		self.weapon = IT_AWP;
		self.awpclip = 10;
		self.crosshair = cvar("crosshair");
		UpdateWeapon();	
	}
	if(self.impulse == 89)
	{
		bprint("Bought Galil \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_GALIL;
		self.weapon = IT_GALIL;
		self.galilclip = 35;
		UpdateWeapon();
	}
	if(self.impulse == 82)
	{
		bprint("Bought AUG \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_AUG;
		self.weapon = IT_AUG;
		self.augclip = 30;
		UpdateWeapon();
	}
	if(self.impulse == 84)
	{
		bprint("Bought Famas \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_FAMAS;
		self.weapon = IT_FAMAS;
		self.famasclip = 25;
		UpdateWeapon();
	}
	if(self.impulse == 45)
	{
		bprint("Bought M4A1 \n");
		sound (self, CHAN_AUTO, "items/gunpickup2.wav", 1, ATTN_NORM);
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_M4A1;
		self.weapon = IT_M4A1;
		self.m4a1clip = 30;
		UpdateWeapon();
	}
	if(self.impulse == 90)
	{
		bprint("CT Players:",ftos(m_iNumCT),"\n");
		bprint("T Players:",ftos(m_iNumTerrorist),"\n");		}	
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
	
	self.impulse = 0;                              // Clear impulse list.
};
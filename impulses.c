     void()ChangeWeapon;
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
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_GLOCK;
		self.weapon = IT_GLOCK;
		UpdateWeapon();
	}
	if(self.impulse == 21)	
	{
		bprint("Bought usp \n");
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_USP;
		self.weapon = IT_USP;
		UpdateWeapon();
	}
	if(self.impulse == 22)	
	{
		bprint("Bought Deagle \n");
		self.iSlot = SECONDARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_DEAGLE;
		self.weapon = IT_DEAGLE;
		UpdateWeapon();
	}
	if(self.impulse == 23)	
	{
		if(self.he_grenades == 1)
			return;
		bprint("Bought HE \n");
		self.items = self.items | IT_HEGRENADE;
		self.weapon = IT_HEGRENADE;
		self.he_grenades += 1;
		UpdateWeapon();
	}
	if(self.impulse == 62)	
	{
		bprint("Bought M3 Shotgun \n");
		self.iSlot = PRIMARY;
		self.items = self.items - (self.items & GetWeaponId());
		self.items = self.items | IT_M3;
		self.weapon = IT_M3;
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
				bprint (" Joining Couter-Terrorist team\n");
				counter1 ();
			}
	}
	if (self.impulse == 95)
				   counter2 ();
	if (self.impulse == 96)
					counter3 ();
	if (self.impulse == 97)
				   counter4 ();
			
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
			terror1 ();
		}
	}
	if (self.impulse == 55)
				   terror2 ();
	if (self.impulse == 56)
					terror3 ();
	if (self.impulse == 57)
				   terror4 ();
	if(self.impulse == 50)
	{
		if(self.weapon == IT_USP)
		{
			self.state = SILENCER;
			if(self.silencer == 1)
			{
				self.weaponframe = 134;
				usp_unsilencer();
			}	
			else		
			{		
				self.weaponframe = 1;
				usp_silencer();
			}
		}
		if(self.weapon == IT_GLOCK)
		{
			if(self.burst == 1)
			{	
				centerprint(self,"Switched to semi-automatic\n");
				self.burst = 0;
			}
			else
			{
				centerprint(self,"Switched to Burst-fire mode\n");
				self.burst = 1;
			}
		}
	}
	self.impulse = 0;                              // Clear impulse list.
};
void(float r_frame)ReloadWeaponUSP= 
{ 
	if(self.ammo_45acp == 0)
		return;
	if(self.uspclip == 12)
		return;
	self.state = RELOADING;
	if(self.usp_fired >= self.ammo_45acp) 
	{ 
		self.uspclip += self.ammo_45acp;
		self.ammo_45acp = 0;
		UpdateWeapon(); 
		self.usp_fired = 0;
		if(self.silencer == 1)
			self.sequence = 5;
		else
			self.sequence = 13;
		self.weaponframe = r_frame;
		if(self.silencer == 1)
			USP_Silencer_Reload();
		else
			USP_Reload();
		return; 
	} 
	self.ammo_45acp -= self.usp_fired;
	self.uspclip += self.usp_fired;
	UpdateWeapon(); 
	self.usp_fired = 0; 
	if(self.silencer == 1)
		self.sequence = 5;
	else
		self.sequence = 13;
	self.weaponframe = r_frame;
	if(self.silencer == 1)
		USP_Silencer_Reload();
	else
		USP_Reload();
} 

void(float r_frame)ReloadWeaponGlock= 
{ 
	if(self.ammo_glock == 0)
		return;
	if(self.glockclip == 20)
		return;
	self.state = RELOADING;
	if(self.glock_fired >= self.ammo_glock) 
	{ 
		self.glockclip += self.ammo_glock;
		self.ammo_glock = 0;
		UpdateWeapon(); 
		self.glock_fired = 0;
		self.sequence = 7;
		self.weaponframe = r_frame;
		Glock_Reload();
		return; 
	} 
	self.ammo_glock -= self.glock_fired;
	self.glockclip += self.glock_fired;
	UpdateWeapon(); 
	self.glock_fired = 0; 
	self.sequence = 7;
	self.weaponframe = r_frame;
	Glock_Reload();
}

//shit omg
float m3a;
void(float r_frame)ReloadWeaponM3= 
{ 
	if(self.ammo_m3 == 0)
		return;
	if(self.m3clip == 7)
		return;
	self.state = RELOADING;
	if(self.m3_fired >= self.ammo_m3) 
	{ 
		m3a = self.m3clip + self.ammo_m3;
		self.ammo_m3 = 0;
		UpdateWeapon(); 
		self.m3_fired = 0;
		self.sequence = 5;
		self.weaponframe = r_frame;
		M3_Reload_Start();
		return; 
	} 
	self.ammo_m3 -= self.m3_fired;
	UpdateWeapon(); 
	self.m3_fired = 0;
	self.sequence = 5;
	self.weaponframe = r_frame;
	M3_Reload_Start();
}

void(float r_frame)ReloadWeaponDeagle= 
{ 
	if(self.ammo_deagle == 0)
		return;
	if(self.deagleclip == 7)
		return;
	self.state = RELOADING;
	if(self.deagle_fired >= self.ammo_deagle) 
	{ 
		self.deagleclip += self.ammo_deagle;
		self.ammo_deagle = 0;
		UpdateWeapon(); 
		self.deagle_fired = 0;
		self.sequence = 4;
		self.weaponframe = r_frame;
		Deagle_Reload();
		return; 
	} 
	self.ammo_deagle -= self.deagle_fired;
	self.deagleclip += self.deagle_fired;
	UpdateWeapon(); 
	self.deagle_fired = 0; 
	self.sequence = 4;
	self.weaponframe = r_frame;
	Deagle_Reload();
}

void(float r_frame)ReloadAK47= 
{ 
	if(self.ammo_ak47 == 0)
		return;
	if(self.ak47clip == 30)
		return;
	self.state = RELOADING;
	if(self.ak47_fired >= self.ammo_ak47) 
	{ 
		self.ak47clip += self.ammo_ak47;
		self.ammo_ak47 = 0;
		UpdateWeapon(); 
		self.ak47_fired = 0;
		self.sequence = 1;
		self.weaponframe = r_frame;
		AK47_Reload();
		return; 
	} 
	self.ammo_ak47 -= self.ak47_fired;
	self.ak47clip += self.ak47_fired;
	UpdateWeapon(); 
	self.ak47_fired = 0; 
	self.sequence = 1;
	self.weaponframe = r_frame;
	AK47_Reload();
}

void(float r_frame)ReloadAWP= 
{ 
	if(self.ammo_awp == 0)
		return;
	if(self.awpclip == 10)
		return;
	self.state = RELOADING;
	if(self.awp_fired >= self.ammo_awp) 
	{ 
		self.awpclip += self.ammo_awp;
		self.ammo_awp = 0;
		UpdateWeapon(); 
		self.awp_fired = 0;
		self.sequence = 4;
		self.weaponframe = r_frame;
		AWP_Reload();
		return; 
	} 
	self.ammo_awp -= self.awp_fired;
	self.awpclip += self.awp_fired;
	UpdateWeapon(); 
	self.awp_fired = 0; 
	self.sequence = 4;
	self.weaponframe = r_frame;
	AWP_Reload();
}

void(float r_frame)ReloadGalil= 
{ 
	if(self.ammo_galil == 0)
		return;
	if(self.galilclip == 35)
		return;
	self.state = RELOADING;
	if(self.galil_fired >= self.ammo_galil) 
	{ 
		self.galilclip += self.ammo_galil;
		self.ammo_galil = 0;
		UpdateWeapon(); 
		self.galil_fired = 0;
		self.sequence = 1;
		self.weaponframe = r_frame;
		Galil_Reload();
		return; 
	} 
	self.ammo_galil -= self.galil_fired;
	self.galilclip += self.galil_fired;
	UpdateWeapon(); 
	self.galil_fired = 0; 
	self.sequence = 1;
	self.weaponframe = r_frame;
	Galil_Reload();
}

void(float r_frame)ReloadAug= 
{ 
	if(self.ammo_aug == 0)
		return;
	if(self.augclip == 30)
		return;
	self.state = RELOADING;
	if(self.aug_fired >= self.ammo_aug) 
	{ 
		self.augclip += self.ammo_aug;
		self.ammo_aug = 0;
		UpdateWeapon(); 
		self.aug_fired = 0;
		self.sequence = 1;
		self.weaponframe = r_frame;
		Aug_Reload();
		return; 
	} 
	self.ammo_aug -= self.aug_fired;
	self.augclip += self.aug_fired;
	UpdateWeapon(); 
	self.aug_fired = 0; 
	self.sequence = 1;
	self.weaponframe = r_frame;
	Aug_Reload();
}

void(float r_frame)ReloadFamas= 
{ 
	if(self.ammo_famas == 0)
		return;
	if(self.famasclip == 25)
		return;
	self.state = RELOADING;
	if(self.famas_fired >= self.ammo_famas) 
	{ 
		self.famasclip += self.ammo_famas;
		self.ammo_famas = 0;
		UpdateWeapon(); 
		self.famas_fired = 0;
		self.sequence = 1;
		self.weaponframe = r_frame;
		Famas_Reload();
		return; 
	} 
	self.ammo_famas -= self.famas_fired;
	self.famasclip += self.famas_fired;
	UpdateWeapon(); 
	self.famas_fired = 0; 
	self.sequence = 1;
	self.weaponframe = r_frame;
	Famas_Reload();
}

void(float r_frame)ReloadM4A1= 
{ 
	if(self.ammo_m4a1 == 0)
		return;
	if(self.m4a1clip == 30)
		return;
	self.state = RELOADING;
	if(self.m4a1_fired >= self.ammo_m4a1) 
	{ 
		self.m4a1clip += self.ammo_m4a1;
		self.ammo_m4a1 = 0;
		UpdateWeapon(); 
		self.m4a1_fired = 0;
		if(self.m4a1silencer)
			self.sequence = 4;
		else
			self.sequence = 11;
		self.weaponframe = r_frame;
		M4A1_Reload();
		return; 
	} 
	self.ammo_m4a1 -= self.m4a1_fired;
	self.m4a1clip += self.m4a1_fired;
	UpdateWeapon(); 
	self.m4a1_fired = 0; 
	if(self.m4a1silencer)
		self.sequence = 4;
	else
		self.sequence = 11;
	self.weaponframe = r_frame;
	M4A1_Reload();
}
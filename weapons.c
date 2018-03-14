float() crandom =
{
	return 2*(random() - 0.5);
};

void(vector org, vector vel, float damage) SpawnBlood =
{
	particle (org, vel*0.1, 73, damage*4);
};

entity	multi_ent;
float	multi_damage;
void() ClearMultiDamage =
{
	multi_ent = world;
	multi_damage = 0;
};

void() ApplyMultiDamage =
{
	if (!multi_ent)
		return;
	T_Damage (multi_ent, self, self, multi_damage);
};

void(entity hit, float damage) AddMultiDamage =
{
	if (!hit)
		return;
	
	if (hit != multi_ent)
	{
		ApplyMultiDamage ();
		multi_damage = damage;
		multi_ent = hit;
	}
	else
		multi_damage = multi_damage + damage;
};

/*
-=-=-=-=-=-=
TraceAttack
-=-=-=-=-=-=
*/
void(float damage, vector dir) TraceAttack=
{
	local	vector	vel, org;
	
	vel = normalize(dir + v_up*crandom() + v_right*crandom());
	vel = vel + 2*trace_plane_normal;
	vel = vel * 200;

	org = trace_endpos - dir*4;

	if (trace_ent.takedamage)
	{
		SpawnBlood (org, vel*0.2, damage);
		AddMultiDamage (trace_ent, damage);
	}
	else
	{
		WriteByte (MSG_BROADCAST, SVC_TEMPENTITY);
		WriteByte (MSG_BROADCAST, TE_GUNSHOT);
		WriteCoord (MSG_BROADCAST, org_x);
		WriteCoord (MSG_BROADCAST, org_y);
		WriteCoord (MSG_BROADCAST, org_z);
	}
};
void(float cShots,vector vecSrc,vector vecDirShooting,vector vecSpread,float flDistance,float iDamage)FireBullets=
{
	local vector vecRight = v_right;
	local vector vecUp = v_up;
	local float x,y,z;
	local float newDamage = iDamage;
	
	ClearMultiDamage ();
	for(float iShot = 1; iShot <= cShots; iShot++)
	{
		
		do{
			x = RANDOM_LONG(-0.5,0.5) + RANDOM_LONG(-0.5,0.5);
			y = RANDOM_LONG(-0.5,0.5) + RANDOM_LONG(-0.5,0.5);
			z = x*x+y*y;
		} while(z>1);
	local vector vecDir = vecDirShooting + x * vecSpread_x * vecRight + y * vecSpread_y * vecUp;
	local vector vecEnd;
	vecEnd = vecSrc + vecDir * flDistance;
	traceline(vecSrc,vecEnd,0,self);
	if (trace_fraction != 1.0)
	{
		if(iDamage)
		{
			TraceAttack(iDamage,vecDir);
		}
		if(cShots == 1)
		{
			local float unit = iDamage;
			while(newDamage > 0)
			{
				if(pointcontents(trace_endpos + vecDir * iDamage) == CONTENT_SOLID)
					break;
				traceline(trace_endpos + vecDir * iDamage,vecSrc,0,self);
				if(trace_allsolid)
					break;
				WriteByte (MSG_BROADCAST, SVC_TEMPENTITY);
				WriteByte (MSG_BROADCAST, TE_GUNSHOT);
				WriteCoord (MSG_BROADCAST, trace_endpos_x);
				WriteCoord (MSG_BROADCAST, trace_endpos_y);
				WriteCoord (MSG_BROADCAST, trace_endpos_z);
				newDamage /= 2;
				unit /= 2;
				vecSrc = trace_endpos;
				traceline(trace_endpos,vecEnd,0,self);
				newDamage -= vlen(trace_endpos - vecSrc) * 0.01;
				TraceAttack(newDamage,vecDir);
			}
		}
	}	
	}
	ApplyMultiDamage ();
}
void()SecondaryAttack=
{
	if(time < self.m_flNextSecondaryAttack)
		return;
	if(self.weapon == IT_KNIFE)
	{
		KNIFE_SecondaryAttack();
	}
	if(self.weapon == IT_USP)
	{
		self.m_flNextSecondaryAttack = time + 0.3;
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
		self.m_flNextSecondaryAttack = time + 0.3;
		if(self.autofire == 1)
		{	
			centerprint(self,"Switched to semi-automatic\n");
			self.autofire = 0;
		}
		else
		{
			centerprint(self,"Switched to Burst-fire mode\n");
			self.autofire = 1;
		}
	}
	if(self.weapon == IT_AWP)
	{
		if(self.state > 0)
			return;
		self.m_flNextSecondaryAttack = time + 0.3;
		if(self.fov == 90)
		{
			stuffcmd(self,"fov 40\n");
			stuffcmd(self,"scope 1\n");
			self.scope = 1;
			self.fov = 40;
		}
		else if(self.fov == 40)
		{
			self.fov = 10;
			stuffcmd(self,"fov 10\n");
		}
		else
		{
			self.fov = 90;
			stuffcmd(self,"fov 90\n");
			stuffcmd(self,"scope 0\n");
			self.scope = 0;
		}
		sound (self, CHAN_AUTO, "weapons/zoom.wav", 1, ATTN_NORM);
	}
	if(self.weapon == IT_AUG)
	{
		if(self.state > 0)
			return;
		self.m_flNextSecondaryAttack = time + 0.3;
		if(self.fov == 90)
		{
			stuffcmd(self,"fov 55\n");
			self.scope = 1;
			self.fov = 40;
		}
		else
		{
			self.fov = 90;
			stuffcmd(self,"fov 90\n");
			self.scope = 0;
		}
	}
	if(self.weapon == IT_FAMAS)
	{
		self.m_flNextSecondaryAttack = time + 0.3;
		if(self.famasburst  == 1)
		{	
			centerprint(self,"Switched to Full Auto\n");
			self.famasburst = 0;
		}
		else
		{
			centerprint(self,"Switched to Burst Fire\n");
			self.famasburst = 1;
		}
	}
}
void() UpdateWeapon=
{
	stuffcmd(self,"crosshair ");
	stuffcmd(self,ftos(self.crosshair));
	stuffcmd(self,"\n");
	if(self.weapon == IT_KNIFE)
	{
		self.weaponmodel = "progs/v_knife.mdl";
		self.weaponframe = 0;
		self.currentammo = 0;
		self.ammo_shells = 0;
	}
	if(self.weapon == IT_USP)
	{
		if(self.silencer == 1)
			self.weaponmodel = "progs/v_usp_silencer.mdl";
		else	
			self.weaponmodel = "progs/v_usp.mdl";
		if(self.silencer == 1)
			self.weaponframe = 1;
		else
			self.weaponframe = 0;
		self.currentammo = self.uspclip;
		self.ammo_shells = self.ammo_45acp;
		MaxSpreadX = 5;
		MaxSpreadY = 5;
		SpreadX = 2;
		SpreadY = 2;
	}
	if(self.weapon == IT_GLOCK)
	{
		self.weaponmodel = "progs/v_glock18.mdl";
		self.weaponframe = 1;
		self.currentammo = self.glockclip;
		self.ammo_shells = self.ammo_glock;
		MaxSpreadX = 2;
		MaxSpreadY = 3;
		SpreadX = 1.7;
		SpreadY = 1.7;
	}
	if(self.weapon == IT_DEAGLE)
	{
		self.weaponmodel = "progs/v_deagle.mdl";
		self.weaponframe = 0;
		self.currentammo = self.deagleclip;
		self.ammo_shells = self.ammo_deagle;
		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 3.5;
		SpreadY = 3.5;
	}
	if(self.weapon == IT_HEGRENADE)
	{
		self.weaponmodel = "progs/v_hegrenade.mdl";
		self.weaponframe = 1;
		self.currentammo = self.he_grenades;
		self.ammo_shells = 0;
	}
	if(self.weapon == IT_M3)
	{
		self.weaponmodel = "progs/v_m3.mdl";
		self.weaponframe = 1;
		self.currentammo = self.m3clip;
		self.ammo_shells = self.ammo_m3;
		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 2;
		SpreadY = 2;
	}
	if(self.weapon == IT_AK47)
	{
		self.weaponmodel = "progs/v_ak47.mdl";
		self.weaponframe = 1;
		self.currentammo = self.ak47clip;
		self.ammo_shells = self.ammo_ak47;
		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 2;
		SpreadY = 2;
	}	
	if(self.weapon == IT_AWP)
	{
		self.weaponmodel = "progs/v_awp.mdl";
		self.weaponframe = 1;
		self.currentammo = self.awpclip;
		self.crosshair = cvar("crosshair");
		stuffcmd(self,"crosshair 0\n");
		self.ammo_shells = self.ammo_awp;
		MaxSpreadX = 5;
		MaxSpreadY = 5;
		SpreadX = 5;
		SpreadY = 5;
	}
	if(self.weapon == IT_GALIL)
	{
		self.weaponmodel = "progs/v_galil.mdl";
		self.weaponframe = 1;
		self.currentammo = self.galilclip;
		self.ammo_shells = self.ammo_galil;
		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 1.6;
		SpreadY = 1.6;
	}
	if(self.weapon == IT_AUG)
	{
		self.weaponmodel = "progs/v_aug.mdl";
		self.weaponframe = 1;
		self.currentammo = self.augclip;
		self.ammo_shells = self.ammo_aug;
		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 2;
		SpreadY = 2;
	}
	if(self.weapon == IT_FAMAS)
	{
		self.weaponmodel = "progs/v_famas.mdl";
		self.weaponframe = 1;
		self.currentammo = self.famasclip;
		self.ammo_shells = self.ammo_famas;
		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 1.6;
		SpreadY = 1.6;
	}
	if(self.weapon == IT_M4A1)
	{
		self.weaponmodel = "progs/v_m4a1.mdl";
		self.weaponframe = 1;
		self.currentammo = self.m4a1clip;
		self.ammo_shells = self.ammo_m4a1;
		MaxSpreadX = 5;
		MaxSpreadY = 5;
		SpreadX = 1.5;
		SpreadY = 1.5;
	}
}

void(float startframe)Reload=
{	
	if(self.ammo_shells == 0)
		return;
	self.weaponframe = startframe;
	self.state = RELOADING;
	if(self.weapon == IT_USP && self.silencer == 0)
		USP_Reload();
	if(self.weapon == IT_USP && self.silencer == 1)	
		USP_Silencer_Reload();
	if(self.weapon == IT_GLOCK)	
		Glock_Reload();	
	if(self.weapon == IT_DEAGLE)	
		Deagle_Reload();	
	if(self.weapon == IT_M3)	
		M3_Reload();	
	if(self.weapon == IT_AK47)
		AK47_Reload();
	if(self.weapon == IT_AWP)
		AWP_Reload();
	if(self.weapon == IT_GALIL)
		Galil_Reload();
	if(self.weapon == IT_AUG)
		Aug_Reload();
	if(self.weapon == IT_FAMAS)
		Famas_Reload();
	if(self.weapon == IT_M4A1)
		M4A1_Reload();
}
void() WeaponAttack =
{
	makevectors(self.v_angle);
	if(self.weapon == IT_KNIFE)
	{
		KNIFE_PrimaryAttack();
	}
	if(self.currentammo == 0 && self.ammo_shells == 0 && self.weapon != IT_KNIFE)
	{
		sound (self, CHAN_AUTO,"weapons/357_cock1.wav", 1, ATTN_NORM);	
		self.attack_finished = time + 0.2;
	}
	if(self.weapon == IT_M3)
	{
		M3_PrimaryAttack();
	}
	if(self.weapon == IT_AK47)
	{
		AK47_PrimaryAttack();
	}
	if(self.weapon == IT_GALIL)
	{
		Galil_PrimaryAttack();
	}
	if(self.weapon == IT_AUG)
	{
		Aug_PrimaryAttack();
	}
	if(self.weapon == IT_FAMAS)
	{
		Famas_PrimaryAttack();
	}
	if(self.weapon == IT_M4A1)
	{
		M4A1_PrimaryAttack();
	}
	if(!self.semi)
	{
		self.semi = 1;
		if(self.weapon == IT_USP)
		{
			USP_Attack();
		}
		if(self.weapon == IT_GLOCK)
		{
			GLOCK_Attack();
		}
		if(self.weapon == IT_DEAGLE)
		{
			DEAGLE_Attack();
		}
		if(self.weapon == IT_AWP)
		{
			AWP_PrimaryAttack();
		}
		if(self.weapon == IT_HEGRENADE)
		{
			HE_Attack();
		}
	}
}
void() WeaponFrameAll=
{
	if(time < self.attack_finished || self.state > 0)
		return;
	if (!self.button0)
        self.semi = 0;			
	if(self.button0)
		WeaponAttack();
	if(self.button1)
		SecondaryAttack();
}
float() GetWeaponId=
{
	if(self.iSlot == PRIMARY)
	{
		if(self.items == self.items | IT_M3)
			return IT_M3;	
		else if(self.items == self.items | IT_AK47)
			return IT_AK47;
		else if(self.items == self.items | IT_AWP)
			return IT_AWP;
		else if(self.items == self.items | IT_GALIL)
			return IT_GALIL; 
		else if(self.items == self.items | IT_AUG)
			return IT_AUG;
		else if(self.items == self.items | IT_FAMAS)
			return IT_FAMAS;
		else if(self.items == self.items | IT_M4A1)
			return IT_M4A1;
	}
	if(self.iSlot == SECONDARY)
	{
		if(self.items == self.items | IT_USP)
			return IT_USP;
		else if(self.items == self.items | IT_GLOCK)
			return IT_GLOCK;	
		else if(self.items == self.items | IT_DEAGLE)
			return IT_DEAGLE;		
	}
	if(self.iSlot == GRENADES)
	{
		if(self.items == self.items | IT_HEGRENADE)
			return IT_HEGRENADE;	
	}
	
	return 0; //just shut up compiler warning
}
void() ChangeWeapon =
{
	if(time < self.attack_finished || self.state > 0)
		return;
	
	if(self.scope)
	{
		stuffcmd(self,"fov 90\n");
		stuffcmd(self,"scope 0\n");
		self.fov = 90;
		self.scope = 0;		
	}
	
	while(1)
	{
		if(self.iSlot == PRIMARY)
		{
			self.iSlot = SECONDARY;
			self.weapon = GetWeaponId();
		}
		else if(self.iSlot == SECONDARY)
		{
			self.iSlot = KNIFE;
			self.weapon = IT_KNIFE;
		}
		else if(self.iSlot == KNIFE)
		{
			self.iSlot = GRENADES;
			self.weapon = GetWeaponId();
		}
		else if(self.iSlot == GRENADES)
		{
			self.iSlot = PRIMARY;
			self.weapon = GetWeaponId();
		}
		if((self.items & self.weapon))	
		{
			UpdateWeapon();
			return;	
		}	
	}
}

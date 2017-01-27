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
	}
	}
	ApplyMultiDamage ();
}

void() UpdateWeapon=
{
	if(self.weapon == IT_KNIFE)
	{
		self.weaponmodel = "progs/v_knife.mdl";
		self.weaponframe = 0;
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
		
		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 3.5;
		SpreadY = 3.5;
	}
	if(self.weapon == IT_HEGRENADE)
	{
		self.weaponmodel = "progs/v_hegrenade.mdl";
		self.weaponframe = 1;
		self.currentammo = self.uspclip;
	}
	if(self.weapon == IT_M3)
	{
		self.weaponmodel = "progs/v_m3.mdl";
		self.weaponframe = 1;
		self.currentammo = self.m3clip;
		
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

		MaxSpreadX = 2;
		MaxSpreadY = 5;
		SpreadX = 2;
		SpreadY = 2;
	}	
}

void(float startframe)Reload=
{
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
}
void() WeaponAttack =
{
	makevectors(self.v_angle);
	if(self.weapon == IT_KNIFE)
	{
		KNIFE_PrimaryAttack();
	}
	if(self.weapon == IT_M3)
	{
		M3_PrimaryAttack();
	}
	if(self.weapon == IT_AK47)
	{
		AK47_PrimaryAttack();
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
}
float() GetWeaponId=
{
	if(self.iSlot == PRIMARY)
	{
		if(self.items == self.items | IT_M3)
			return IT_M3;	
		if(self.items == self.items | IT_AK47)
			return IT_AK47;
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
	local float skip;
	
	if(time < self.attack_finished || self.state > 0)
		return;
		
	while(1)
	{
		skip = 0;
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
		if((self.items & self.weapon) && skip == 0)	
		{
			UpdateWeapon();
			return;	
		}	
	}
}

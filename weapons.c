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
void(float shotcount, vector dir, vector spread) FireBullets=
{
	local	vector direction;
	local	vector	src;
	
	makevectors(self.v_angle);

	src = self.origin + v_forward*10;
	src_z = self.absmin_z + self.size_z * 0.7;

	ClearMultiDamage ();
	while (shotcount > 0)
	{
		direction = dir + crandom()*spread_x*v_right + crandom()*spread_y*v_up;

		traceline (src, src * 2048, FALSE, self);
		if (trace_fraction != 1.0)
			TraceAttack (30, direction);

		shotcount = shotcount - 1;
	}
	ApplyMultiDamage ();
};

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
	}
	if(self.weapon == IT_GLOCK)
	{
		self.weaponmodel = "progs/v_glock18.mdl";
		self.weaponframe = 1;
		self.currentammo = self.glockclip;
	}
	if(self.weapon == IT_DEAGLE)
	{
		self.weaponmodel = "progs/v_deagle.mdl";
		self.weaponframe = 0;
		self.currentammo = self.deagleclip;
	}
	if(self.weapon == IT_HEGRENADE)
	{
		self.weaponmodel = "progs/v_hegrenade.mdl";
		self.weaponframe = 1;
		self.currentammo = self.uspclip;
	}
}

void(float startframe)Reload=
{
	self.weaponframe = startframe;
	if(self.weapon == IT_USP && self.silencer == 0)
		USP_Reload();
	if(self.weapon == IT_USP && self.silencer == 1)	
		USP_Silencer_Reload();
	if(self.weapon == IT_GLOCK)	
		Glock_Reload();	
	if(self.weapon == IT_DEAGLE)	
		Deagle_Reload();		
}
void() WeaponAttack =
{
	makevectors(self.v_angle);
	if(self.weapon == IT_KNIFE)
	{
		KNIFE_PrimaryAttack();
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
	if(time < self.attack_finished || self.state == RELOADING || self.state == SILENCER || self.state == ATTACK)
		return;
	if (!self.button0)
        self.semi = 0;			
	if(self.button0)
		WeaponAttack();
}
float() GetWeaponId=
{
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
}
void() ChangeWeapon =
{
	local float skip;
	
	if(time < self.attack_finished || self.state > 0)
		return;
		
	while(1)
	{
		skip = 0;
		if(self.iSlot == SECONDARY)
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
			self.iSlot = SECONDARY;
			self.weapon = GetWeaponId();
		}
		if((self.items & self.weapon) && skip == 0)	
		{
			UpdateWeapon();
			return;	
		}	
	}
}

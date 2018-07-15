
void()anim_knife_attack=
{
	if(self.weaponframe == 214)
		{
			self.state = 0;
			self.weaponframe = 0;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_knife_attack;
	self.nextthink = time + 0.005;
}
void()anim_sec_knife_attack=
{
	if(self.weaponframe == 92)
		{
			self.state = 0;
			self.weaponframe = 0;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_sec_knife_attack;
	self.nextthink = time + 0.025;
}
void KnifeAttack(float iDamage,float iDistance)
{
	local vector org, end;
	local float r;
	makevectors(self.v_angle);
	org = self.origin + self.view_ofs;
	end = org + v_forward * iDistance;
	traceline(org,end,0,self);
	sound (self, CHAN_AUTO, "weapons/knife_slash1.wav", 1, ATTN_NORM);
	if(trace_fraction ==1)
		return;
	r = floor(random()*4);
	if(trace_ent.takedamage)
	{
		switch(r)
		{
		case 0:
			sound (self, CHAN_AUTO, "weapons/knife_hit1.wav", 1, ATTN_NORM);
			break;
		case 1:
			sound (self, CHAN_AUTO, "weapons/knife_hit2.wav", 1, ATTN_NORM);
			break;
		case 2:
			sound (self, CHAN_AUTO, "weapons/knife_hit3.wav", 1, ATTN_NORM);
			break;
		case 3:
			sound (self, CHAN_AUTO, "weapons/knife_hit4.wav", 1, ATTN_NORM);
			break;
		}
		T_Damage (trace_ent, self, self, iDamage);
	}
	else
		sound (self, CHAN_AUTO, "weapons/knife_hitwall1.wav", 1, ATTN_NORM);
}

void()KNIFE_PrimaryAttack=
{
		self.attack_finished = time + 0.5;
		self.weaponframe = 155;
		self.state = ATTACK;
		anim_knife_attack();
		KnifeAttack(20,48);	
}
void()KNIFE_SecondaryAttack=
{
		self.m_flNextSecondaryAttack = time + 1.1;
		self.weaponframe = 48;
		self.state = ATTACK;
		anim_sec_knife_attack();
		KnifeAttack(60,30);	
}

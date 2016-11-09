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
void KnifeAttack(float iDamage,float iDistance)
{
	local vector org, end;
	makevectors(self.v_angle);
	org = self.origin + self.view_ofs;
	end = org + v_forward * iDistance;
	traceline(org,end,0,self);
	sound (self, CHAN_AUTO, "weapons/knife_slash1.wav", 1, ATTN_NORM);
	if(trace_fraction ==1)
		return;

	if(trace_ent.takedamage)
	{
		switch(randomfloat(0,3))
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

void()KNIFE_Attack=
{
		self.attack_finished = time + 0.5;
		self.weaponframe = 155;
		anim_knife_attack();
		self.state = ATTACK;
		KnifeAttack(20,48);	
}
void()anim_deagle_attack=
{
	if(self.weaponframe == 25)
		{
			self.state = 0;
			self.weaponframe = 1;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_deagle_attack;
	self.nextthink = time + 0.01;
}
void() Deagle_Reload=
{
	if(self.weaponframe == 113) 
	{
		self.weaponframe = 1;
		self.deagleclip = 7;
		self.state = 0;
		return;
	}	
	if(self.weaponframe == 68)
		sound (self, CHAN_AUTO, "weapons/de_clipout.wav", 1, ATTN_NORM);
	if(self.weaponframe == 94)
		sound (self, CHAN_AUTO, "weapons/de_clipin.wav", 1, ATTN_NORM);
	self.weaponframe += 1;
	self.think = Deagle_Reload;
	self.nextthink = time + 0.035;
}
void()DEAGLE_Attack=
{
	local vector vorg,dir;
	if(self.deagleclip == 0)
	{
		self.state = RELOADING;
		Reload(51);
		return;
	}
	self.attack_finished = time + 0.2;
	self.weaponframe = 1;
	self.state = ATTACK;
	anim_deagle_attack();
	sound (self, CHAN_AUTO, "weapons/deagle-1.wav", 1, ATTN_NORM);
	if(self.velocity_x || self.velocity_y)
		dir = v_forward + (v_right * (random() - 0.5)*0.25) + (v_up * (random() - 0.5)*0.25); 
	else	
		dir = v_forward + (v_right * (random() - 0.5)*0.13) + (v_up * (random() - 0.5)*0.13); 
	vorg = self.origin + '0 0 22';
	traceline(vorg, vorg + dir * 16000, FALSE, self);
	T_Damage (trace_ent, self, self, 54);
	WriteByte (MSG_BROADCAST, SVC_TEMPENTITY);
	WriteByte (MSG_BROADCAST, TE_GUNSHOT);
	WriteCoord (MSG_BROADCAST, trace_endpos_x);
	WriteCoord (MSG_BROADCAST, trace_endpos_y);
	WriteCoord (MSG_BROADCAST, trace_endpos_z);
	self.deagleclip -=1;
}
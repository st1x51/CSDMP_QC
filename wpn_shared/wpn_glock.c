
void()anim_glock_attack=
{
	if(self.weaponframe == 102)
		{
			self.weaponframe = 1;
			return;
		}
	self.weaponframe += 1;
	self.think = anim_glock_attack;
	self.nextthink = time + 0.03;
}
//change this shit
void()anim_burst_glock_attack=
{
	local vector vorg, dir;
	if(self.weaponframe == 63)
		{
			self.weaponframe = 1;
			return;
		}
	if(self.weaponframe == 35 && self.glockclip > 2)
		{
			if(self.velocity_x || self.velocity_y)
				dir = v_forward + (v_right * (random() - 0.5)*0.15) + (v_up * (random() - 0.5)*0.15); 
			else	
				dir = v_forward + (v_right * (random() - 0.5)*0.1) + (v_up * (random() - 0.5)*0.1); 
			vorg = self.origin + '0 0 22';
			traceline(vorg, vorg + dir * 16000, FALSE, self);
			T_Damage (trace_ent, self, self, 25);
			WriteByte (MSG_BROADCAST, SVC_TEMPENTITY);
			WriteByte (MSG_BROADCAST, TE_GUNSHOT);
			WriteCoord (MSG_BROADCAST, trace_endpos_x);
			WriteCoord (MSG_BROADCAST, trace_endpos_y);
			WriteCoord (MSG_BROADCAST, trace_endpos_z);
			self.glockclip -=1;
		}
	if(self.weaponframe == 37 && self.glockclip > 1)
		{
			if(self.velocity_x || self.velocity_y)
				dir = v_forward + (v_right * (random() - 0.5)*0.15) + (v_up * (random() - 0.5)*0.15); 
			else	
				dir = v_forward + (v_right * (random() - 0.5)*0.1) + (v_up * (random() - 0.5)*0.1); 
			vorg = self.origin + '0 0 22';
			traceline(vorg, vorg + dir * 16000, FALSE, self);
			T_Damage (trace_ent, self, self, 25);
			WriteByte (MSG_BROADCAST, SVC_TEMPENTITY);
			WriteByte (MSG_BROADCAST, TE_GUNSHOT);
			WriteCoord (MSG_BROADCAST, trace_endpos_x);
			WriteCoord (MSG_BROADCAST, trace_endpos_y);
			WriteCoord (MSG_BROADCAST, trace_endpos_z);
			self.glockclip -=1;
		}		
	if(self.weaponframe == 39)
		{
			if(self.velocity_x || self.velocity_y)
				dir = v_forward + (v_right * (random() - 0.5)*0.15) + (v_up * (random() - 0.5)*0.15); 
			else	
				dir = v_forward + (v_right * (random() - 0.5)*0.1) + (v_up * (random() - 0.5)*0.1); 
			vorg = self.origin + '0 0 22';
			traceline(vorg, vorg + dir * 16000, FALSE, self);
			T_Damage (trace_ent, self, self, 25);
			WriteByte (MSG_BROADCAST, SVC_TEMPENTITY);
			WriteByte (MSG_BROADCAST, TE_GUNSHOT);
			WriteCoord (MSG_BROADCAST, trace_endpos_x);
			WriteCoord (MSG_BROADCAST, trace_endpos_y);
			WriteCoord (MSG_BROADCAST, trace_endpos_z);
			self.glockclip -=1;
		}		
	self.weaponframe += 1;
	self.think = anim_burst_glock_attack;
	self.nextthink = time + 0.02;
}
void() Glock_Reload=
{
	if(self.weaponframe == 212) 
	{
		self.weaponframe = 1;
		self.glockclip = 20;
		self.state = 0;
		return;
	}
	if(self.weaponframe  == 154)
		sound (self, CHAN_AUTO, "weapons/clipout1.wav", 1, ATTN_NORM);	
	if(self.weaponframe  == 188)
		sound (self, CHAN_AUTO, "weapons/clipin1.wav", 1, ATTN_NORM);		
	if(self.weaponframe  == 205)
		sound (self, CHAN_AUTO, "weapons/sliderelease1.wav", 1, ATTN_NORM);			
	self.weaponframe += 1;
	self.think = Glock_Reload;
	self.nextthink = time + 0.035;
}
void()GLOCK_Attack=
{
	local vector vorg,dir;
	if(self.burst == 0)
	{
		if(self.glockclip == 0)
			{
				Reload(144); 
				return;
			}
		self.attack_finished = time + 0.2;
		self.weaponframe = 94;
		anim_glock_attack();
		sound (self, CHAN_AUTO, "weapons/glock18-2.wav", 1, ATTN_NORM);
		if(self.velocity_x || self.velocity_y)
			dir = v_forward + (v_right * (random() - 0.5)*0.1) + (v_up * (random() - 0.5)*0.1); 
		else	
			dir = v_forward + (v_right * (random() - 0.5)*0.05) + (v_up * (random() - 0.5)*0.05); 
		vorg = self.origin + '0 0 22';
		traceline(vorg, vorg + dir * 16000, FALSE, self);
		T_Damage (trace_ent, self, self, 25);
		WriteByte (MSG_BROADCAST, SVC_TEMPENTITY);
		WriteByte (MSG_BROADCAST, TE_GUNSHOT);
		WriteCoord (MSG_BROADCAST, trace_endpos_x);
		WriteCoord (MSG_BROADCAST, trace_endpos_y);
		WriteCoord (MSG_BROADCAST, trace_endpos_z);
		self.glockclip -=1;
	}
	else
	{
		self.attack_finished = time + 0.3;
		if(self.glockclip == 0)
		{
			Reload(144); 
			return;
		}
		sound (self, CHAN_AUTO, "weapons/glock18-1.wav", 1, ATTN_NORM);
		self.weaponframe = 33;
		anim_burst_glock_attack();
	}	
}
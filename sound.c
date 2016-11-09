.float Radius,roomtype;
float (entity ent, entity enttarget)sound_inrange =
{
    local vector vecSpot1;
	local vector vecSpot2;
	local vector vecRange;
	local float flRange;

    vecSpot1 = ent.origin + ent.view_ofs;
    vecSpot2 = enttarget.origin + enttarget.view_ofs;

	vecRange = vecSpot1 - vecSpot2;
	flRange = vlen(vecRange);
/*
    traceline (vecSpot1, vecSpot2, TRUE, self);

	// check if line of sight crosses water boundary, or is blocked
	if ((trace_inopen && trace_inwater) || (trace_fraction != 1))
		return -1;

	// calc range from sound entity to player
	vecRange = trace_endpos - vecSpot1;
	flRange = vlen(vecRange);
*/
	return flRange;
};

void() radius_player_find =
{
	local entity client;
	local float res;
	
	client = checkclient ();
	if(!client)
		return;
	msg_entity = client;
    res = sound_inrange(self, client);
    if(res <= self.Radius)
    {
       WriteByte (MSG_ONE,  SVC_ROOMTYPE);
       WriteShort(MSG_ONE, self.roomtype);
    }
	self.nextthink = time + 0.75;
	self.think = radius_player_find;
};

void() env_sound =
{
    self.classname = "env_sound";
	self.nextthink = time + 0.75;
    self.think = radius_player_find;
};
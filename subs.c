/*
QuakeEd only writes a single float for angles (bad idea), so up and down are
just constant angles.
*/
vector() SetMovedir =
{
	if (self.angles == '0 -1 0')
		self.movedir = '0 0 1';
	else if (self.angles == '0 -2 0')
		self.movedir = '0 0 -1';
	else
	{
		makevectors (self.angles);
		self.movedir = v_forward;
	}
	
	self.angles = '0 0 0';
};

void UTIL_ScreenFadeBuild(vector color, float fadeTime, float fadeHold, float alpha,float flags)
{
	duration = fadeTime;
	holdTime = fadeHold;
	R = color_x;
	G = color_y;
	B = color_z;
	A = alpha;
	fadeFlags = flags;
}
void UTIL_ScreenFadeWrite(entity pEntity)
{
	if (!pEntity)
		return;
	
	msg_entity = pEntity; 
	
	WriteByte (MSG_ONE, SVC_SCREENFADE);
	WriteShort(MSG_ONE,duration);
	WriteShort(MSG_ONE,holdTime);
	WriteShort(MSG_ONE,fadeFlags);
	WriteByte(MSG_ONE,R);
	WriteByte(MSG_ONE,G);
	WriteByte(MSG_ONE,B);
	WriteByte(MSG_ONE,A);
}
void UTIL_ScreenFade(entity pEntity,vector color, float fadeTime, float fadeHold, float alpha,float flags)
{
	UTIL_ScreenFadeBuild(color, fadeTime, fadeHold, alpha,flags);
	UTIL_ScreenFadeWrite(pEntity);
}
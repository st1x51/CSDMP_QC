void() counter1=
{
	self.team = CT_SIDE;
	self.m_iTeam = CT;
	PutClientCTInServer();
}
void() counter2=
{}
void() counter3=
{}
void() counter4=
{}

void() terror1=
{
	self.team = T_SIDE;
	self.m_iTeam = TERRORIST;
	PutClientTInServer();
}
void() terror2=
{}
void() terror3=
{}
void() terror4=
{}
vector  DEFAULT_VIEWHEIGHT = '0 0 28';
vector  VEC_DUCK_VIEW = '0 0 12';
vector  VEC_DUCK_HULL_MIN = '-16 -16 -18';
vector  VEC_DUCK_HULL_MAX =  '16 16 18';

// screen fade flags
float FFADE_IN		    = 0;		// Just here so we don't pass 0 into the function
float FFADE_OUT		    = 1;		// Fade out (not in)
float FFADE_MODULATE	= 2;		// Modulate (don't blend)
float FFADE_STAYOUT	    = 4;		// ignores the duration, stays faded out until new ScreenFade message received

float T_SIDE = 1;
float CT_SIDE = 2;
float m_iNumTerrorist,m_iNumCT;
.float menu_team_on;
.float semi;
.float ammo_45acp,uspclip,silencer;
.float ammo_glock,glockclip,burst;
.float ammo_deagle,deagleclip;
.float ammo_m3,m3clip;
.float he_grenades;
.float attack_finished;
.float iSlot;
.float m_iMenu,m_iTeam;
enum
{
	PRIMARY,
	SECONDARY,
	KNIFE,
	GRENADES,
	GRENADES
};
enum
{
	JOINED,
	SHOWLTEXT,
	READINGLTEXT,
	SHOWTEAMSELECT,
	PICKINGTEAM,
	GETINTOGAME
};
enum
{
	Menu_OFF,
	Menu_ChooseTeam,
	Menu_IGChooseTeam,
	Menu_ChooseAppearance,
	Menu_Buy
};
enum
{
	UNASSIGNED,
	TERRORIST,
	CT,
	SPECTATOR,
};
.float m_iJoiningState;
entity m_pIntroCamera;
.float m_fIntroCamTime;
//for flashbang
.float m_blindUntilTime;
.float m_blindStartTime;
.float m_blindHoldTime;
.float m_blindFadeTime;
.float m_blindAlpha;

float IT_KNIFE = 1;
float IT_USP = 2;
float IT_GLOCK = 4;
float IT_DEAGLE = 8;
float IT_HEGRENADE = 16;
float IT_M3 = 32;
.float state;
float RELOADING = 1;
float SILENCER  = 2;
float ATTACK 	= 3;
//footsteps
string sound_step1;
string sound_step2;
string sound_step3;
string sound_step4;

float m_bMapHasBuyZone,buyTime;
.float m_bInBuyZone;

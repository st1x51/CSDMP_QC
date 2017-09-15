vector  DEFAULT_VIEWHEIGHT = '0 0 28';
vector  VEC_DUCK_VIEW = '0 0 12';
vector  VEC_DUCK_HULL_MIN = '-16 -16 -18';
vector  VEC_DUCK_HULL_MAX =  '16 16 18';

#define AUTOAIM_2DEGREES  0.0348994967025
#define AUTOAIM_5DEGREES  0.08715574274766
#define AUTOAIM_8DEGREES  0.1391731009601
#define AUTOAIM_10DEGREES 0.1736481776669
// func breakable
#define SF_BREAK_TRIGGER_ONLY		1	// may only be broken by trigger
#define	SF_BREAK_TOUCH			2	// can be 'crashed through' by running player (plate glass)
#define SF_BREAK_PRESSURE		4	// can be broken by a player standing on it
#define SF_BREAK_CROWBAR	256	// instant break if hit with crowbar
// screen fade flags
float FFADE_IN		    = 0;		// Just here so we don't pass 0 into the function
float FFADE_OUT		    = 1;		// Fade out (not in)
float FFADE_MODULATE	= 2;		// Modulate (don't blend)
float FFADE_STAYOUT	    = 4;		// ignores the duration, stays faded out until new ScreenFade message received
float T_SIDE = 1;
float CT_SIDE = 2;

float m_iNumTerrorist,m_iNumCT;
.float menu_team_on;
.float ammo_45acp,uspclip,silencer;
.float ammo_glock,glockclip,autofire;
.float ammo_deagle,deagleclip;
.float ammo_m3,m3clip;
.float ammo_ak47,ak47clip;
.float ammo_awp,awpclip,scope;
.float ammo_galil,galilclip;
.float ammo_aug,augclip;
.float ammo_famas,famasclip,famasburst;
.float ammo_m4a1,m4a1clip;
.float he_grenades;
.float attack_finished;
.float iSlot;
.float m_iMenu,m_iTeam;
enum
{
	PRIMARY,
	SECONDARY,
	KNIFE,
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
	SPECTATOR
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

.float m_flNextSecondaryAttack;
float MaxSpreadY,MaxSpreadX,SpreadX,SpreadY;
float LeftSpread;
float IT_KNIFE = 1;
float IT_USP = 2;
float IT_GLOCK = 4;
float IT_DEAGLE = 8;
float IT_HEGRENADE = 16;
float IT_M3 = 32;
float IT_AK47 = 64;
float IT_AWP = 128;
float IT_GALIL = 256;
float IT_AUG = 512;
float IT_FAMAS = 1024;
float IT_M4A1 = 2048;
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
.float fov,crosshair;
.float direction,wp;
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

/*
-----------------------------------------
min

Returns the lesser of two (or more) numbers

-----------------------------------------
*/
float (float a, float b) mathlib_min =
{
	if (a<b)
		return a;
	else
		return b;
};
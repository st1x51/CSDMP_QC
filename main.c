void() precaches;
void() LightStyles_setup;
void() main = {};

void()CheckRules=
{
	m_bMapHasBuyZone = find(world,classname,"func_buyzone") != 0;
}
void() worldspawn = 
{
	lastspawn = world;
	precaches();
	LightStyles_setup();
	CheckRules();
};
void() SetNewParms = {};
void() SetChangeParms = {};
void() StartFrame = {};
 
void() precaches =
{
	//models
	precache_model ("progs/player.mdl");
	precache_model ("progs/v_usp.mdl");
	precache_model ("progs/v_knife.mdl"); 
	precache_model("progs/v_usp_silencer.mdl");
	precache_model("progs/v_glock18.mdl");
	precache_model("progs/v_deagle.mdl");
	precache_model("progs/v_m3.mdl");
	precache_model("progs/v_hegrenade.mdl");
	precache_model("progs/w_grenade.mdl");
	 
	precache_model ("progs/gign.mdl"); 
	precache_model ("progs/leet.mdl"); 
	//sounds
	precache_sound("player/jump.wav");
	precache_sound("weapons/knife_slash1.wav");
	precache_sound("weapons/knife_hit1.wav");
	precache_sound("weapons/knife_hit2.wav");
	precache_sound("weapons/knife_hit3.wav");
	precache_sound("weapons/knife_hit4.wav");
	precache_sound("weapons/knife_hitwall1.wav");
	precache_sound("items/gunpickup2.wav");
	//usp
	precache_sound("weapons/usp1.wav");
	precache_sound("weapons/usp_unsil-1.wav");
	precache_sound("weapons/usp_sliderelease.wav");
	precache_sound("weapons/usp_clipin.wav");
	precache_sound("weapons/usp_clipout.wav");
	precache_sound("weapons/usp_silencer_on.wav");
	precache_sound("weapons/usp_silencer_off.wav");
	//flock
	precache_sound("weapons/glock18-1.wav");
	precache_sound("weapons/glock18-2.wav");
	precache_sound("weapons/clipout1.wav");
	precache_sound("weapons/clipin1.wav");
	precache_sound("weapons/sliderelease1.wav");
	precache_sound("weapons/slideback1.wav");
	//deagle
	precache_sound("weapons/de_clipin.wav");
	precache_sound("weapons/de_clipout.wav");
	precache_sound("weapons/deagle-1.wav");
	//grenade
	precache_sound("weapons/grenade_hit1.wav");
	precache_sound("weapons/grenade_hit2.wav");
	precache_sound("weapons/grenade_hit3.wav");
	precache_sound("weapons/he_bounce-1.wav");
	//m3
	precache_sound("weapons/m3-1.wav");
	precache_sound("weapons/m3_insertshell.wav");
	precache_sound("weapons/m3_pump.wav");
	//ak47
	precache_model("progs/v_ak47.mdl");
	precache_sound("weapons/ak47-1.wav");
	precache_sound("weapons/ak47_clipout.wav");
	precache_sound("weapons/ak47_clipin.wav");
	//awp
	precache_model("progs/v_awp.mdl");
	precache_sound("weapons/awp1.wav");
	precache_sound("weapons/zoom.wav");
	precache_sound("weapons/boltup.wav");
	precache_sound("weapons/boltpull1.wav");
	precache_sound("weapons/boltdown.wav");
	precache_sound("weapons/awp_clipin.wav");
	precache_sound("weapons/awp_clipout.wav");
	//galil
	precache_model("progs/v_galil.mdl");
	precache_sound("weapons/galil-1.wav");
	//footsteps
	precache_sound ("player/pl_step1.wav");
	precache_sound ("player/pl_step2.wav");
	precache_sound ("player/pl_step3.wav");
	precache_sound ("player/pl_step4.wav");

	precache_sound ("player/pl_metal1.wav");
	precache_sound ("player/pl_metal2.wav");
	precache_sound ("player/pl_metal3.wav");
	precache_sound ("player/pl_metal4.wav");
	
	precache_sound ("player/pl_dirt1.wav");
	precache_sound ("player/pl_dirt2.wav");
	precache_sound ("player/pl_dirt3.wav");
	precache_sound ("player/pl_dirt4.wav");

	precache_sound ("player/pl_duct1.wav");
	precache_sound ("player/pl_duct2.wav");
	precache_sound ("player/pl_duct3.wav");
	precache_sound ("player/pl_duct4.wav");

	precache_sound ("player/pl_grate1.wav");
	precache_sound ("player/pl_grate2.wav");
	precache_sound ("player/pl_grate3.wav");
	precache_sound ("player/pl_grate4.wav");


	precache_sound ("player/pl_tile1.wav");
	precache_sound ("player/pl_tile2.wav");
	precache_sound ("player/pl_tile3.wav");
	precache_sound ("player/pl_tile4.wav");
	precache_sound ("player/pl_tile5.wav");
	
	precache_sound ("player/pl_snow1.wav");
	precache_sound ("player/pl_snow2.wav");
	precache_sound ("player/pl_snow3.wav");
	precache_sound ("player/pl_snow4.wav");
};
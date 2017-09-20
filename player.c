void()PutClientCTInServer;
void()PutClientTInServer;
void()RespawnCounter;
.float anim_time; // used for animation timing
.float anim_end; // end frame for current scene
.float anim_priority; // prioritize animations
.float anim_run; // running or not

// client_t->anim_priority
float ANIM_BASIC		= 0;	// stand / run
float ANIM_PAIN			= 1;
float ANIM_ATTACK		= 2;
float ANIM_DEATH		= 3;


// running
$frame axrun1 axrun2 axrun3 axrun4 axrun5 axrun6
$frame rockrun1 rockrun2 rockrun3 rockrun4 rockrun5 rockrun6

// standing
$frame stand1 stand2 stand3 stand4 stand5
$frame axstnd1 axstnd2 axstnd3 axstnd4 axstnd5 axstnd6
$frame axstnd7 axstnd8 axstnd9 axstnd10 axstnd11 axstnd12

// pain
$frame axpain1 axpain2 axpain3 axpain4 axpain5 axpain6
$frame pain1 pain2 pain3 pain4 pain5 pain6

// death
$frame axdeth1 axdeth2 axdeth3 axdeth4 axdeth5 axdeth6
$frame axdeth7 axdeth8 axdeth9
$frame deatha1 deatha2 deatha3 deatha4 deatha5 deatha6 deatha7 deatha8
$frame deatha9 deatha10 deatha11
$frame deathb1 deathb2 deathb3 deathb4 deathb5 deathb6 deathb7 deathb8
$frame deathb9
$frame deathc1 deathc2 deathc3 deathc4 deathc5 deathc6 deathc7 deathc8
$frame deathc9 deathc10 deathc11 deathc12 deathc13 deathc14 deathc15
$frame deathd1 deathd2 deathd3 deathd4 deathd5 deathd6 deathd7
$frame deathd8 deathd9
$frame deathe1 deathe2 deathe3 deathe4 deathe5 deathe6 deathe7
$frame deathe8 deathe9

// attacks
$frame nailatt1 nailatt2
$frame light1 light2
$frame rockatt1 rockatt2 rockatt3 rockatt4 rockatt5 rockatt6
$frame shotatt1 shotatt2 shotatt3 shotatt4 shotatt5 shotatt6
$frame axatt1 axatt2 axatt3 axatt4 axatt5 axatt6
$frame axattb1 axattb2 axattb3 axattb4 axattb5 axattb6
$frame axattc1 axattc2 axattc3 axattc4 axattc5 axattc6
$frame axattd1 axattd2 axattd3 axattd4 axattd5 axattd6

void () SetClientFrame =
{

// note: call whenever weapon frames are called!

    if (self.anim_time > time)
        return; //don't call every frame, if it is the animations will play too fast
	
    self.anim_time = time + 0.02;

    local float anim_change, run;

    if (self.velocity_x || self.velocity_y)
        run = TRUE;
    else
        run = FALSE;

    anim_change = FALSE;


    // check for stop/go and animation transitions
    if (run != self.anim_run && self.anim_priority == ANIM_BASIC)
        anim_change = TRUE;

    if (anim_change != TRUE)
    {
        if (self.frame < self.anim_end)
        {   // continue an animation
            self.frame = self.frame + 1;
            return;
        }
        if (self.anim_priority == ANIM_DEATH)
        {
					
            if (self.deadflag == DEAD_DYING)
            {
               // self.nextthink = -1;
                self.deadflag = DEAD_DEAD;
            }
            return;    // stay there
        }
    }

    // return to either a running or standing frame
    self.anim_priority = ANIM_BASIC;
    self.anim_run = run;
	
    if (self.velocity_x || self.velocity_y)
    {   // running
        self.frame = 62;
        self.anim_end = 98;
    }
    else
    {   // standing
        self.frame = 1;
        self.anim_end = 61;
    }

};
float rcount;
void() RespawnCounter =
{
	if(rcount == 0)
	{
		if(self.team == CT_SIDE)	
			PutClientCTInServer();
		else
			PutClientTInServer();
		return;
	}
	if(rcount == 1 || rcount == 2 || rcount == 3)
		stuffcmd(self, "bf\n");
	centerprint2(self,"Respawn in: ",ftos(rcount));	
	rcount -= 1;
	self.think = RespawnCounter;
	self.nextthink = time + 1;
}
void()rest=
{
	if(self.team == CT_SIDE)	
		PutClientCTInServer();
	else
		PutClientTInServer();
	return;
}
void() PlayerDead =
{
	self.nextthink = -5;
// allow respawn after a certain time
	self.deadflag = DEAD_DEAD;
	rest();
};
void()	die_anim1=[160, die_anim2]{self.nextthink = time + 0.02;};
void()	die_anim2=[161, die_anim3]{self.nextthink = time + 0.02;};
void()	die_anim3=[162, die_anim4]{self.nextthink = time + 0.02;};
void()	die_anim4=[163, die_anim5]{self.nextthink = time + 0.02;};
void()	die_anim5=[164, die_anim6]{self.nextthink = time + 0.02;};
void()	die_anim6=[165, die_anim7]{self.nextthink = time + 0.02;};
void()	die_anim7=[166, die_anim8]{self.nextthink = time + 0.02;};
void()	die_anim8=[167, die_anim9]{self.nextthink = time + 0.02;};
void()	die_anim9=[168, die_anim10]{self.nextthink = time + 0.02;};
void()	die_anim10=[169, die_anim11]{self.nextthink = time + 0.02;};
void()	die_anim11=[170, die_anim12]{self.nextthink = time + 0.02;};
void()	die_anim12=[171, die_anim13]{self.nextthink = time + 0.02;};
void()	die_anim13=[172, die_anim14]{self.nextthink = time + 0.02;};
void()	die_anim14=[173, die_anim15]{self.nextthink = time + 0.02;};
void()	die_anim15=[174, die_anim16]{self.nextthink = time + 0.02;};
void()	die_anim16=[175, die_anim17]{self.nextthink = time + 0.02;};
void()	die_anim17=[176, die_anim18]{self.nextthink = time + 0.02;};
void()	die_anim18=[177, die_anim19]{self.nextthink = time + 0.02;};
void()	die_anim19=[178, die_anim20]{self.nextthink = time + 0.02;};
void()	die_anim20=[179, die_anim21]{self.nextthink = time + 0.02;};
void()	die_anim21=[180, die_anim22]{self.nextthink = time + 0.02;};
void()	die_anim22=[181, die_anim23]{self.nextthink = time + 0.02;};
void()	die_anim23=[182, die_anim24]{self.nextthink = time + 0.02;};
void()	die_anim24=[183, die_anim25]{self.nextthink = time + 0.02;};
void()	die_anim25=[184, die_anim26]{self.nextthink = time + 0.02;};
void()	die_anim26=[185, die_anim27]{self.nextthink = time + 0.02;};
void()	die_anim27=[186, die_anim28]{self.nextthink = time + 0.02;};
void()	die_anim28=[187, die_anim29]{self.nextthink = time + 0.02;};
void()	die_anim29=[188, die_anim30]{self.nextthink = time + 0.02;};
void()	die_anim30=[189, die_anim31]{self.nextthink = time + 0.02;};
void()	die_anim31=[190, die_anim32]{self.nextthink = time + 0.02;};
void()	die_anim32=[191, die_anim33]{self.nextthink = time + 0.02;};
void()	die_anim33=[192, die_anim34]{self.nextthink = time + 0.02;};
void()	die_anim34=[193, die_anim35]{self.nextthink = time + 0.02;};
void()	die_anim35=[194, die_anim36]{self.nextthink = time + 0.02;};
void()	die_anim36=[195, die_anim37]{self.nextthink = time + 0.02;};
void()	die_anim37=[196, die_anim38]{self.nextthink = time + 0.02;};
void()	die_anim38=[197, die_anim39]{self.nextthink = time + 0.02;};
void()	die_anim39=[198, die_anim40]{self.nextthink = time + 0.02;};
void()	die_anim40=[199, PlayerDead]{};
void () PlayerDie =
{
	self.anim_priority = ANIM_DEATH;
	self.deadflag = DEAD_DYING;
	self.items = 0; 
    self.view_ofs = '0 0 -8';
    self.angles_x = self.angles_z = 0;
    self.solid = SOLID_NOT;
    self.movetype = MOVETYPE_TOSS;
    self.flags = self.flags - (self.flags & FL_ONGROUND);
    if (self.velocity_z < 10)
        self.velocity_z = self.velocity_z + random()*300;
	rcount = 5;
	die_anim1();
};

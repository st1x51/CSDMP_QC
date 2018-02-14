void()PutClientCTInServer;
void()PutClientTInServer;
.float anim_time;
.float anim_end; 
void () SetClientFrame =
{
    if (self.anim_time > time)
        return; //don't call every frame, if it is the animations will play too fast
	
    self.anim_time = time + 0.02;
	if (self.frame < self.anim_end)
        {   // continue an animation
            self.frame = self.frame + 1;
            return;
        }
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
void()PlayerRespawn=
{
	if(self.team == CT_SIDE)	
		PutClientCTInServer();
	else
		PutClientTInServer();
}
void() PlayerDead =
{
	self.nextthink = -5;
	self.deadflag = DEAD_DEAD;
	PlayerRespawn();
};
void()	die_anim1=[160, die_anim2]{self.nextthink = time + 0.05;};
void()	die_anim2=[162, die_anim3]{self.nextthink = time + 0.05;};
void()	die_anim3=[164, die_anim4]{self.nextthink = time + 0.05;};
void()	die_anim4=[166, die_anim5]{self.nextthink = time + 0.05;};
void()	die_anim5=[168, die_anim6]{self.nextthink = time + 0.05;};
void()	die_anim6=[170, die_anim7]{self.nextthink = time + 0.05;};
void()	die_anim7=[172, die_anim8]{self.nextthink = time + 0.05;};
void()	die_anim8=[174, die_anim9]{self.nextthink = time + 0.05;};
void()	die_anim9=[176, die_anim10]{self.nextthink = time + 0.05;};
void()	die_anim10=[178, die_anim11]{self.nextthink = time + 0.05;};
void()	die_anim11=[180, die_anim12]{self.nextthink = time + 0.05;};
void()	die_anim12=[182, die_anim13]{self.nextthink = time + 0.05;};
void()	die_anim13=[184, die_anim14]{self.nextthink = time + 0.05;};
void()	die_anim14=[186, die_anim15]{self.nextthink = time + 0.05;};
void()	die_anim15=[188, die_anim16]{self.nextthink = time + 0.05;};
void()	die_anim16=[190, die_anim17]{self.nextthink = time + 0.05;};
void()	die_anim17=[192, die_anim18]{self.nextthink = time + 0.05;};
void()	die_anim18=[194, die_anim19]{self.nextthink = time + 0.05;};
void()	die_anim19=[196, die_anim20]{self.nextthink = time + 0.05;};
void()	die_anim20=[198, PlayerDead]{};
void () PlayerDie =
{
	self.deadflag = DEAD_DEAD;
	self.items = 0; 
    self.view_ofs = '0 0 -8';
    self.angles_x = self.angles_z = 0;
    self.solid = SOLID_NOT;
    self.movetype = MOVETYPE_TOSS;
    self.flags = self.flags - (self.flags & FL_ONGROUND);
    if (self.velocity_z < 10)
        self.velocity_z = self.velocity_z + random()*300;
	die_anim1();
};

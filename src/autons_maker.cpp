#include "EZ-Template/piston.hpp"
#include "EZ-Template/util.hpp"
#include "autons.hpp"
#include "constantsauton.cpp"
#include "pros/rtos.hpp"
#include "subsystems.hpp"



void mogorushfunnicktestt(){

armPID.target_set(245);
// Position: -248, 269, Angle: 335�
//set angle (335)
intake2.move(127);
chassis.pid_drive_set(38_in, DRIVE_SPEED);
Piston22.set(true);
chassis.pid_wait_until(35_in);
Piston737.set(true);
chassis.pid_wait_quick_chain();


chassis.pid_drive_set(-38_in, DRIVE_SPEED);
chassis.pid_wait();

intake2.move(0);


Piston737.set(false);

armPID.target_set(500);

Piston22.set(false);

chassis.pid_turn_set( 15_deg, TURN_SPEED, shortest);
chassis.pid_wait();

chassis.pid_drive_set(4_in, DRIVE_SPEED);
chassis.pid_wait();

intake2.move(0);

armPID.target_set(2100);

pros::delay(500);
armPID.target_set(10);
pros::delay(200);
chassis.pid_turn_set(75, 60, shortest);
pros::delay(200);
armPID.target_set(10);
chassis.pid_wait_quick_chain();


chassis.pid_turn_set(110, 60, shortest);
chassis.pid_wait_quick_chain();

chassis.pid_turn_set(140, 70, shortest);
chassis.pid_wait_quick();

chassis.pid_drive_set(-38_in, DRIVE_SPEED);
chassis.pid_wait();

chassis.pid_drive_set(-4_in, 50);
chassis.pid_wait();

Piston11.set(true);


pros::delay(200);


chassis.pid_turn_set(155, TURN_SPEED, shortest);
chassis.pid_wait();

chassis.pid_drive_set(60_in, 110);

intake2.move(127);

chassis.pid_wait_until(30_in);
chassis.pid_speed_max_set(30);

chassis.pid_wait();

pros::delay(350);


chassis.pid_drive_set(-15_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(15_in, 40);
chassis.pid_wait();

chassis.pid_drive_set(-15_in, DRIVE_SPEED);
chassis.pid_wait();




}//end



    void testawp(){
// Position: -293, 70, Angle: 255�
//set angle (255)
//set zero (111)
int i = 0;

armPID.target_set(1360);
while (i < 400){
//arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
//arm.move(armPID.compute(arm.get_position()));

chassis.pid_turn_set(-45_deg, TURN_SPEED);

i = 0;
armPID.target_set(10);
while (i < 300){
// arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
//arm.move(armPID.compute(arm.get_position()));

chassis.pid_wait();

chassis.pid_drive_set(-30_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-10_in, 80);
chassis.pid_wait();

Piston11.set(true);
pros::delay(100);

chassis.pid_turn_set( -20_deg, TURN_SPEED);
chassis.pid_wait();

intake2.move(127);

chassis.pid_drive_set(30_in, 80);

i = 0;
armPID.target_set(1360);

while (i < 300){
//arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
// arm.move(armPID.compute(arm.get_position()));

chassis.pid_wait();

pros::delay(500);

chassis.pid_drive_set(-30_in, DRIVE_SPEED);
chassis.pid_wait();

i = 0;
armPID.target_set(10);

while (i < 300){
// arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}

chassis.pid_turn_set(-150_deg, 50,  shortest);
chassis.pid_wait();

chassis.pid_drive_set(28_in, DRIVE_SPEED);
chassis.pid_wait();


chassis.pid_drive_set(-20_in, DRIVE_SPEED);
chassis.pid_wait();

chassis.pid_turn_set( 20_deg, TURN_SPEED);
chassis.pid_wait();

intake2.move(0);

chassis.pid_drive_set(15_in, DRIVE_SPEED);
chassis.pid_wait_quick_chain();

chassis.pid_drive_set(15_in, 60);
chassis.pid_wait();





}//end
    void testsave(){
}//end
void testthinge(){
// Position: -255, 113, Angle: 182�
chassis.pid_turn_set(182_deg, 90);
chassis.pid_wait();

Piston11.set(true);
chassis.pid_turn_set(88_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(-19_in, 110);
chassis.pid_wait();

chassis.pid_drive_set(28_in, 110);
chassis.pid_wait();

}//end


void midle_ring_rush(){
// Position: -250, 117, Angle: 180�
//set zero (180)
//Piston22.set(true);
antijam = 1;
pros::Task antijamtasko(antijamtask);
chassis.pid_drive_set(-27_in, 127);
chassis.pid_wait_until(-12_in);
chassis.pid_speed_max_set(35);
chassis.pid_wait_until(-24_in);
//Piston22.set(false);
Piston11.set(true);
intake2.move(127);
chassis.pid_wait();

chassis.pid_turn_set(130_deg, 90, true);
chassis.pid_wait();

intake2.move(0);


chassis.pid_drive_set(10_in, 110);
chassis.pid_wait_quick_chain();

PistonB29.set(true);

chassis.pid_drive_set(5_in, 35);
chassis.pid_wait();


Piston737.set(true);

pros::delay(250);

chassis.pid_turn_set(148_deg, 110, true);
chassis.pid_wait();

chassis.pid_drive_set(5_in, 110);
chassis.pid_wait();

Piston22.set(true);

pros::delay(450);

chassis.pid_drive_set(-18.5_in, 110);
chassis.pid_wait();

PistonB29.set(false);

intake2.move(0);
chassis.pid_turn_set(200_deg, 100, true);
chassis.pid_wait_quick_chain();

chassis.pid_turn_set(240_deg, 100, true);
chassis.pid_wait_quick_chain();


chassis.pid_turn_set(283_deg, 90);
chassis.pid_wait_quick();

intake2.move(127);

Piston22.set(false);

pros::delay(200);

chassis.pid_turn_set(268_deg, 110, shortest, true);
chassis.pid_wait();

chassis.pid_drive_set(28_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(320_deg, 110, true);
chassis.pid_wait();

Piston737.set(false);

pros::delay(250);


chassis.pid_turn_set(330_deg, 100, true);
chassis.pid_wait();

chassis.pid_drive_set(45_in, 110, true);
chassis.pid_wait_until(30_in);
chassis.pid_speed_max_set(70);
chassis.pid_wait_until(35_in);
antijam = 0;
chassis.pid_wait();

chassis.pid_drive_set(-16_in, 90);
chassis.pid_wait_quick_chain();

chassis.pid_drive_set(12_in, 90);
chassis.pid_wait_quick_chain();

antijam = 1;


pros::delay(350);

chassis.pid_drive_set(-24_in, 127);
chassis.pid_wait_quick_chain();



//Piston11.set(false);

//pros::delay(350);

//armPID.target_set(1850);
//armPID.target_set(1850);
//armPID.target_set(1850);
chassis.pid_turn_set(213_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(30_in, 110);
chassis.pid_wait();

//armPID.target_set(1850);


}//end
void redqualbakerauton(){
// Position: -286, 78, Angle: 243�
//set zyrero (243)
chassis.drive_imu_reset(243);

armPID.target_set(1100);

pros::delay(450);

armPID.target_set(10);

pros::delay(200);

chassis.pid_turn_set(200_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(-38_in, 110);
chassis.pid_wait_until(-13_in);
chassis.pid_speed_max_set(25);
chassis.pid_wait_until(-35_in);
Piston11.set(true);
intake2.move(127);
chassis.pid_wait();

chassis.pid_turn_set(310_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(10_in, 60);
intake2.move(0);
chassis.pid_wait_quick_chain();

PistonB29.set(true);

chassis.pid_drive_set(5_in, 60);
chassis.pid_wait();

Piston737.set(true);
pros::delay(400);


chassis.pid_turn_set(335_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(4_in, 110);
chassis.pid_wait();

Piston22.set(true);
pros::delay(300);

PistonB29.set(false);

//chassis.pid_turn_set(330_deg, 90);
//chassis.pid_wait_quick();

chassis.pid_drive_set(-19_in, 127);
chassis.pid_wait();

chassis.pid_turn_set(34_deg, 90, shortest, true);
chassis.pid_wait_quick_chain();

chassis.pid_turn_set(105_deg, 90, shortest, true);
chassis.pid_wait_quick();

intake2.move(127);

Piston22.set(false);

pros::delay(200);

chassis.pid_turn_set(95_deg, 110, shortest, true);
chassis.pid_wait();

chassis.pid_drive_set(32_in, 127);
chassis.pid_wait_until(2_in);
chassis.pid_speed_max_set(65);
chassis.pid_wait();


chassis.pid_turn_set(295_deg, 110, shortest, true);
chassis.pid_wait();

Piston737.set(false);

pros::delay(350);

chassis.pid_turn_set(305_deg, 110, shortest, true);
chassis.pid_wait();


//chassis.pid_drive_set(34_in, 127);
//chassis.pid_wait_quick();

pros::delay(250);

//chassis.pid_drive_set(-10_in, 127);
//chassis.pid_wait();

chassis.pid_turn_set(305_deg, 110, true);
chassis.pid_wait();

//pros::delay(250);

//Piston11.set(false);
//intake2.move(0);

chassis.pid_drive_set(30_in, 100);
//armPID.target_set(1000);
chassis.pid_wait();

}//end
void redsixplusone(){
// Position: -285, -45, Angle: 117�
//semmt zero (117)
chassis.drive_imu_reset(117);
armPID.target_set(1850);

pros::delay(450);

armPID.target_set(10);

pros::delay(250);


chassis.pid_turn_set(161_deg, 110);
chassis.pid_wait();

chassis.pid_drive_set(-40_in, 110);
chassis.pid_wait_until(-20_in);
chassis.pid_speed_max_set(35);
chassis.pid_wait_until(-38_in);
Piston11.set(true);
intake2.move(127);
Piston737.set(true);
chassis.pid_wait();

chassis.pid_turn_set(320_deg, 110, true);
chassis.pid_wait();


chassis.pid_drive_set(14.5_in, 110);
chassis.pid_wait();


chassis.pid_turn_set(290, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(12_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(260, 90, true);
chassis.pid_wait();

Piston737.set(false);

chassis.pid_drive_set(18_in, 110);
chassis.pid_wait_until(7_in);
chassis.pid_wait();

pros::delay(250);



chassis.pid_turn_set(285_deg, 90, true);
chassis.pid_wait();

// New jhientryyyyyy
chassis.pid_turn_set(145_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(26_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(215_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(36_in, 110);
chassis.pid_wait();

chassis.pid_drive_set(-19_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(92_deg, 90, true);
chassis.pid_wait();

PistonB29.set(true);

chassis.pid_drive_set(54_in, 110);
chassis.pid_wait();

PistonB29.set(false);

chassis.pid_turn_set(357_deg, 90, true);
chassis.pid_wait();

armPID.target_set(10);

chassis.pid_drive_set(15_in, 110);
chassis.pid_wait();

}//end



void solowapbutworks(){
// Position: -285, -45, Angle: 117�
//semmt zero (117)
chassis.drive_imu_reset(117);
armPID.target_set(1850);

pros::delay(450);

armPID.target_set(10);

pros::delay(250);


chassis.pid_turn_set(161_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(-40_in, 110);
chassis.pid_wait_until(-20_in);
chassis.pid_speed_max_set(35);
chassis.pid_wait_until(-38_in);
Piston11.set(true);
intake2.move(127);
Piston737.set(true);
chassis.pid_wait();

chassis.pid_turn_set(309_deg, 90);
chassis.pid_wait();


chassis.pid_drive_set(15_in, 110);
chassis.pid_wait();


chassis.pid_turn_set(287, 90);
chassis.pid_wait();

chassis.pid_drive_set(12_in, 70);
chassis.pid_wait();

chassis.pid_turn_set(260, 90);
chassis.pid_wait();

chassis.pid_drive_set(12_in, 70);
chassis.pid_wait();

pros::delay(250);

Piston737.set(false);

chassis.pid_turn_set(285_deg, 90);
chassis.pid_wait();

// New jhientryyyyyy
chassis.pid_turn_set(145_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(24_in, 110);
chassis.pid_wait();

chassis.pid_drive_set(28_in, 110);
chassis.pid_wait();

PistonB29.set(true);

chassis.pid_turn_set(81_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(53_in, 110);
chassis.pid_wait();

PistonB29.set(false);

Piston11.set(false);

chassis.pid_turn_set(189_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(-22_in, 110);
chassis.pid_wait();

Piston11.set(true);

chassis.pid_turn_set(88_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(28_in, 110);
chassis.pid_wait();

chassis.pid_drive_set(-52_in, 110);
chassis.pid_wait();
pros::delay(500);
intake2.move(0);

armPID.target_set(1050);

}//end


void awpstatefunworkPLANE(){
// Position: -285, -45, Angle: 117�
chassis.drive_imu_reset(117);

armPID.target_set(1200);

pros::delay(400);

armPID.target_set(10);

pros::delay(150);

chassis.pid_turn_set(164_deg, 127);
chassis.pid_wait();

chassis.pid_drive_set(-35_in, 127);
chassis.pid_wait_until(-14_in);
chassis.pid_speed_max_set(65);
chassis.pid_wait_until(-32_in);
Piston11.set(true);
chassis.pid_wait();

Piston11.set(true);
intake2.move(127);
chassis.pid_turn_set(270_deg, 127);
chassis.pid_wait();

chassis.pid_drive_set(25_in, 127);
chassis.pid_wait_quick();

chassis.pid_turn_set(204_deg, 127);
chassis.pid_wait_quick();

chassis.pid_drive_set(25_in, 127);
chassis.pid_wait_quick();

//pros::delay(250);

//chassis .pid_drive_set  (-14_in, 90);
//chassis.pid_wait_quick();

chassis.pid_turn_set(91_deg, 127);
chassis.pid_wait_quick();


chassis.pid_drive_set(79_in, 127);
chassis.pid_wait_until(25);
chassis.pid_speed_max_set(55);
//PistonB29.set(true);
chassis.pid_wait_until(70);
chassis.pid_speed_max_set(110);
chassis.pid_wait();
pros::delay(450);
PistonB29.set(false);
intake2.move(0);
Piston11.set(false);

pros::delay(250);

chassis.pid_turn_set(182_deg, 127);
chassis.pid_wait();

chassis.pid_drive_set(-30_in, 127);
chassis.pid_wait_until(-8_in);
chassis.pid_speed_max_set(25);
chassis.pid_wait_until(-27_in);
Piston11.set(true);
chassis.pid_wait();

intake2.move(127);

chassis.pid_turn_set(93_deg, 127);
chassis.pid_wait_quick();

chassis.pid_drive_set(25_in, 127);
chassis.pid_wait_quick();

armPID.target_set(550);

chassis.pid_turn_set(105_deg, 127);
chassis.pid_wait_quick();

chassis.pid_drive_set(-47_in, 127);
chassis.pid_wait_until(-30_in);
intake2.move(0);
chassis.pid_wait();


}//end


void awpstatefunworkPLANEBlue(){
chassis.drive_imu_reset(-117);
    //chassis.odom_x_flip();
    //chassis.odom_theta_flip();


armPID.target_set(1200);

pros::delay(400);

armPID.target_set(10);

pros::delay(150);

chassis.pid_turn_set(-164_deg, 127);
chassis.pid_wait();

chassis.pid_drive_set(-35_in, 127);
chassis.pid_wait_until(-14_in);
chassis.pid_speed_max_set(65);
chassis.pid_wait_until(-32_in);
Piston11.set(true);
chassis.pid_wait();

Piston11.set(true);
intake2.move(127);
chassis.pid_turn_set(-270_deg, 127);
chassis.pid_wait();

chassis.pid_drive_set(25_in, 127);
chassis.pid_wait_quick();

chassis.pid_turn_set(-204_deg, 127);
chassis.pid_wait_quick();

chassis.pid_drive_set(25_in, 127);
chassis.pid_wait_quick();

//pros::delay(250);

//chassis.pid_drive_set(-14_in, 90);
//chassis.pid_wait_quick();

chassis.pid_turn_set(-91_deg, 127);
chassis.pid_wait_quick();


chassis.pid_drive_set(79_in, 127);
chassis.pid_wait_until(25);
chassis.pid_speed_max_set(55);
//PistonB29.set(true);
chassis.pid_wait_until(70);
chassis.pid_speed_max_set(110);
chassis.pid_wait();
pros::delay(450);
PistonB29.set(false);
intake2.move(0);
Piston11.set(false);

pros::delay(250);

chassis.pid_turn_set(-182_deg, 127);
chassis.pid_wait();

chassis.pid_drive_set(-30_in, 127);
chassis.pid_wait_until(-8_in);
chassis.pid_speed_max_set(25);
chassis.pid_wait_until(-27_in);
Piston11.set(true);
chassis.pid_wait();

intake2.move(127);

chassis.pid_turn_set(-93_deg, 127);
chassis.pid_wait_quick();

chassis.pid_drive_set(25_in, 127);
chassis.pid_wait_quick();

armPID.target_set(550);

chassis.pid_turn_set(-105_deg, 127);
chassis.pid_wait_quick();

chassis.pid_drive_set(-47_in, 127);
chassis.pid_wait_until(-30_in);
intake2.move(0);
chassis.pid_wait();



}


void redsixplusoneblue(){
    
    chassis.odom_x_flip();
    chassis.odom_theta_flip();
    redsixplusone(); 
  
  }


void redqualbakerautonblue(){
  antijam = 1;
  pros::Task antijamtasko(antijamtask);
    
// Position: -285, -45, Angle: -243

chassis.drive_imu_reset(-243);

//pros::delay(2000);

armPID.target_set(1125);

pros::delay(450);

armPID.target_set(10);

pros::delay(200);

chassis.pid_turn_set(-200_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(-42_in, 110);
chassis.pid_wait_until(-16_in);
chassis.pid_speed_max_set(45);
chassis.pid_wait_until(-39_in);
Piston11.set(true);
chassis.pid_wait();

chassis.pid_turn_set(-300_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(4_in, 60);
chassis.pid_wait_quick_chain();

PistonB29.set(true);

chassis.pid_drive_set(8_in, 60);
chassis.pid_wait();

Piston22.set(true);
pros::delay(400);


chassis.pid_turn_set(-325_deg, 90, true);
chassis.pid_wait();

chassis.pid_drive_set(5_in, 110);
chassis.pid_wait();

Piston737.set(true);
pros::delay(300);

PistonB29.set(false);

//chassis.pid_tuuuuuuurn_set(330_deg, 90);
//chassis.pid_wait_quick();

chassis.pid_drive_set(-19_in, 127);
chassis.pid_wait();

chassis.pid_turn_set(-34_deg, 90, shortest, true);
chassis.pid_wait_quick_chain();

chassis.pid_turn_set(-105_deg, 90, shortest, true);
chassis.pid_wait_quick();

intake2.move(127);

Piston737.set(false);

pros::delay(200);

chassis.pid_turn_set(-95_deg, 110, shortest, true);
chassis.pid_wait();

chassis.pid_drive_set(32_in, 127);
chassis.pid_wait_until(2_in);
chassis.pid_speed_max_set(65);
chassis.pid_wait();


chassis.pid_turn_set(-295_deg, 110, shortest, true);
chassis.pid_wait();

Piston22.set(false);

pros::delay(350);

chassis.pid_turn_set(-305_deg, 110, shortest, true);
chassis.pid_wait();


//chassis.pid_drrrrrive_set(34_in, 127);
//chassis.pid_wait_quick();

pros::delay(250);

//chassis.pid_drrrrrrive_set(-10_in, 127);
//chassis.pid_wait();

chassis.pid_turn_set(-305_deg, 110, true);
chassis.pid_wait();

//pros::delay(250);

//Piston11.set(false);
//intake2.move(0);

chassis.pid_drive_set(30_in, 100);
//armPID.target_set(1000);
chassis.pid_wait();
  
  }

  void midle_ring_rushblue(){

//chassis.odom_x_flip();
//chassis.odom_theta_flip();
// Position: 161, 117, Angle: 0�

antijam = 1;
  pros::Task antijamtasko(antijamtask);

Piston22.set(true);
chassis.pid_drive_set(-26_in, 127);
chassis.pid_wait_until(-10_in);
chassis.pid_speed_max_set(45);
chassis.pid_wait_until(-24_in);
Piston22.set(false);
Piston11.set(true);
intake2.move(127);
chassis.pid_wait();

chassis.pid_turn_set(-135_deg, 90, true);
chassis.pid_wait();

intake2.move(0);

// New entry

chassis.pid_drive_set(10_in, 110);
chassis.pid_wait_quick_chain();

PistonB29.set(true);

chassis.pid_drive_set(6_in, 35);
chassis.pid_wait();


Piston22.set(true);

pros::delay(250);

chassis.pid_turn_set(-155_deg, 110, true);
chassis.pid_wait();

chassis.pid_drive_set(4_in, 110);
chassis.pid_wait();

Piston737.set(true);

pros::delay(450);

chassis.pid_drive_set(-18.5_in, 110);
chassis.pid_wait();

PistonB29.set(false);

intake2.move(0);
chassis.pid_turn_set(-200_deg, 100, true);
chassis.pid_wait_quick_chain();

chassis.pid_turn_set(-240_deg, 100, true);
chassis.pid_wait_quick_chain();


chassis.pid_turn_set(-283_deg, 100, true);
chassis.pid_wait();

intake2.move(127);

Piston737.set(false);

pros::delay(200);

chassis.pid_turn_set(-268_deg, 110, shortest, true);
chassis.pid_wait();

chassis.pid_drive_set(28_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(-320_deg, 110, true);
chassis.pid_wait();

Piston22.set(false);

pros::delay(250);


chassis.pid_turn_set(-330_deg, 100, true);
chassis.pid_wait();

chassis.pid_drive_set(45_in, 110, true);
chassis.pid_wait_until(30_in);
chassis.pid_speed_max_set(37);
antijam = 0;
chassis.pid_wait();

chassis.pid_drive_set(-5_in, 110);
chassis.pid_wait_quick_chain();

antijam = 1;


pros::delay(350);

chassis.pid_drive_set(-24_in, 127);
chassis.pid_wait_quick_chain();

chassis.pid_turn_set(-127_deg, 100, true);
chassis.pid_wait_quick_chain();

Piston11.set(false);

pros::delay(350);

chassis.pid_turn_set(-10_deg, 100, true);
chassis.pid_wait_quick_chain();

chassis.pid_drive_set(-12_in, 110);
chassis.pid_wait_quick_chain();


}//end

 
  

  void betternotawp(){
// Position: -293, 70, Angle: 255�
//set angle (255)
//set zero (111)
int i = 0;

armPID.target_set(1360);
while (i < 400){
//arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
//arm.move(armPID.compute(arm.get_position()));

chassis.pid_turn_set(-45_deg, TURN_SPEED);

i = 0;
armPID.target_set(10);
while (i < 300){
// arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
//arm.move(armPID.compute(arm.get_position()));

chassis.pid_wait();

chassis.pid_drive_set(-30_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-10_in, 80);
chassis.pid_wait();

Piston11.set(true);
pros::delay(100);

chassis.pid_turn_set( -20_deg, TURN_SPEED);
chassis.pid_wait();

intake2.move(127);
chassis.pid_turn_set(91_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(17_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(152_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(45_in, 110);
chassis.pid_wait();

chassis.pid_drive_set(23_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(267_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(54_in, 110);
chassis.pid_wait();

chassis.pid_turn_set(351_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(13_in, 110);
chassis.pid_wait();

}//end

  

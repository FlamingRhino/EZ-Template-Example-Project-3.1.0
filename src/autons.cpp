#include "autons.hpp"
#include <stdio.h>
#include "EZ-Template/piston.hpp"
#include "EZ-Template/util.hpp"
#include "arm.cpp"
#include "pros/rtos.hpp"
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

//overshoot turns by 12 inches

// These are out of 127


const int DRIVE_SPEED = 110;
const int TURN_SPEED = 70;
const int SWING_SPEED = 90;



// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(12.3, 0.6, 99);
  chassis.pid_turn_constants_set(3.4, 0.052, 22.5, 16); // 3.4 0.052 22.5 16.0
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(150_ms, 3_deg, 350_ms, 7_deg, 0_ms, 0_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

///
// Drive Example
///


void mogorushfun(){

  chassis.pid_drive_set(40_in, DRIVE_SPEED);
  Piston22.set(true);
  chassis.pid_wait_until(28_in);
  chassis.pid_speed_max_set(127);
  chassis.pid_wait_until(35_in);
  Piston737.set(true);
  chassis.pid_wait_quick_chain();

  chassis.pid_drive_set(-50_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston737.set(false);

  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  armPID.target_set(230);

  pros::delay(200);

  intake2.move(127);
  chassis.pid_wait();

  Piston22.set(false);

  chassis.pid_turn_set(12, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(6_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  armPID.target_set(1850);

  pros::delay(500);

  chassis.pid_turn_set(155, 60, right_turn, true);
  pros::delay(200);
  armPID.target_set(10);
  chassis.pid_wait();

  chassis.pid_drive_set(-40_in, DRIVE_SPEED);
  chassis.pid_wait_until(-18_in);
  chassis.pid_speed_max_set(60);
  chassis.pid_wait_until(-34_in);
  Piston11.set(true);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();

  pros::delay(100);

  chassis.pid_turn_set(85 , TURN_SPEED, shortest);
  intake2.move(127);
  chassis.pid_wait();

  chassis.pid_drive_set(32_in, DRIVE_SPEED);
  chassis.pid_wait();

  pros::delay(250);

  chassis.pid_drive_set(-32_in, DRIVE_SPEED);
  chassis.pid_wait();
  intake2.move(0);

  chassis.pid_turn_set(217, 50, shortest, true);
  chassis.pid_wait();

  armPID.target_set(1180);

  chassis.pid_drive_set(37_in, 90);
     intake2.move(50);
  chassis.pid_wait_until(12_in);
  chassis.pid_speed_max_set(30);
  chassis.pid_wait_until(26_in);
   intake2.move(40);
  armPID.target_set(230);
  chassis.pid_wait();

  intake2.move(127);

  pros::delay(1000);

  
  chassis.pid_turn_set(170 , TURN_SPEED, shortest, true);

  intake2.move(0);

  chassis.pid_wait_quick();

  armPID.target_set(1080);

  pros::delay(450);

  intake2.move(-127);

  chassis.pid_drive_set(8_in, 60);
  chassis.pid_wait();

  armPID.target_set(1850);

  pros::delay(350);

  chassis.pid_drive_set(-5_in, 60);
  chassis.pid_wait();

  chassis.pid_turn_set(90, 70, shortest, true);
  armPID.target_set(10);
  chassis.pid_wait();

  //chassis.pid_drive_set(62_in, 127);
  //intake2.move(127);
  //chassis.pid_wait();





}

void mogorushwallblue(){
  //start the rush
  chassis.pid_drive_set(40_in, DRIVE_SPEED);
  Piston22.set(true);
  chassis.pid_wait_until(28_in);
  chassis.pid_speed_max_set(127);
  chassis.pid_wait_until(35_in);
  Piston737.set(true);
  chassis.pid_wait_quick_chain();
  // backoff
  chassis.pid_drive_set(-45_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston737.set(false);
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  armPID.target_set(240);

  pros::delay(200);

  intake2.move(127);
  chassis.pid_wait();

  Piston22.set(false);

  chassis.pid_turn_set(12, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(7.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  armPID.target_set(1850);

  intake2.move(0);
  pros::delay(500);

  chassis.pid_turn_set(-140, TURN_SPEED,shortest);
  chassis.pid_wait();

  intake2.move(127);
  
  chassis.pid_drive_set(-40_in, DRIVE_SPEED);
  chassis.pid_wait_until(-18_in);
  chassis.pid_speed_max_set(60);
  chassis.pid_wait_until(-34_in);
  Piston11.set(true);
  chassis.pid_wait();

  chassis.pid_turn_set(-100, TURN_SPEED,shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(36_in, DRIVE_SPEED);
  chassis.pid_wait();

  pros::delay(500);

  chassis.pid_drive_set(-36_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-145, TURN_SPEED,shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait();

  armPID.target_set(1670);


}

void mogorushredplus(){
  
}

void mogorushblueplus(){
  
}

void sigawpmirrored(){
  chassis.odom_x_flip();
  chassis.odom_theta_flip();
  sigawp(); 

}

void ringrush(){
  Piston11.set(false);
  armPID.target_set(1845);

  pros::delay(600);
  armPID.target_set(40);

  chassis.pid_turn_set(45_deg, TURN_SPEED, shortest);

  armPID.target_set(40);

  chassis.pid_wait();

  chassis.pid_drive_set(-27_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-10_in, 80);
  chassis.pid_wait();

   Piston11.set(true);
   pros::delay(100);
   
  intake2.move(127);

  chassis.pid_turn_set( 180_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston22.set(true);
  pros::delay(150);

  chassis.pid_drive_set(14_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set( 220_deg, TURN_SPEED, shortest);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set( 180_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(-27_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set( 120_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

  Piston22.set(false);

  chassis.pid_turn_set( 150_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(33_in, 50);
  chassis.pid_wait();

  chassis.pid_turn_set( -2_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston22.set(true);
  armPID.target_set(1600);

  chassis.pid_drive_set(30_in, 70);
  chassis.pid_wait();

    Piston22.set(false);
  armPID.target_set(10);

  chassis.pid_turn_set( -20_deg, TURN_SPEED, shortest);
  chassis.pid_wait();


  chassis.pid_drive_set(60_in, 70);
  chassis.pid_wait();

  


}

void ringrushblue(){

  chassis.odom_x_flip();
  chassis.odom_theta_flip();
  ringrush(); 

}


void sigawp(){
  Piston11.set(false);
  armPID.target_set(1845);

  pros::delay(600);
  armPID.target_set(40);

  chassis.pid_turn_set(40_deg, TURN_SPEED, shortest);

  armPID.target_set(40);

  chassis.pid_wait();

  chassis.pid_drive_set(-27_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 80);
  chassis.pid_wait();

   Piston11.set(true);
   pros::delay(100);
   
  intake2.move(127);


     chassis.pid_turn_set( 150_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

    chassis.pid_drive_set(28_in, DRIVE_SPEED);
  chassis.pid_wait();


    chassis.pid_drive_set(-28_in, DRIVE_SPEED);
  chassis.pid_wait();


  chassis.pid_turn_set( 16_deg, TURN_SPEED, shortest);

  armPID.target_set(1700);

  Piston22.set(true);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, DRIVE_SPEED);
  chassis.pid_wait();

    chassis.pid_drive_set(14_in,40);
  chassis.pid_wait();


  pros::delay(250);
  
  chassis.pid_turn_set( 110_deg, TURN_SPEED, shortest);

    intake2.move(0);
  Piston11.set(false);
  chassis.pid_wait();

  chassis.pid_drive_set(-25_in, DRIVE_SPEED);

  chassis.pid_wait();

  
  chassis.pid_drive_set(-10_in, 60);

  chassis.pid_wait();

      Piston11.set(true);
  
  intake2.move(127);

 pros::delay(300);
 
  armPID.target_set(40);


  Piston22.set(false);

  chassis.pid_turn_set( -30_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

    chassis.pid_drive_set(32_in, DRIVE_SPEED);
  chassis.pid_wait();

    chassis.pid_drive_set(-36_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  
  chassis.pid_turn_set( -100_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

    chassis.pid_drive_set(20_in, DRIVE_SPEED);
  chassis.pid_wait();



  


  
}


 void goodskillcode(){

  chassis.drive_imu_reset(120);

    chassis.pid_turn_set(120_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

    Piston11.set(false);
  armPID.target_set(1360);

  pros::delay(600);
  armPID.target_set(40);

  chassis.pid_turn_set(130_deg, TURN_SPEED, shortest);
  chassis.pid_wait();

    chassis.pid_drive_set(-20,50);
    chassis.pid_wait();

        Piston11.set(true);


    pros::delay(100 );

    chassis.pid_drive_set(5,DRIVE_SPEED);
    chassis.pid_wait();

    chassis.pid_turn_set(0_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    intake2.move(127);

    chassis.pid_drive_set(29,DRIVE_SPEED);
    chassis.pid_wait();

        pros::delay(200 );


    chassis.pid_turn_set(-90_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(25,DRIVE_SPEED);
    chassis.pid_wait();

        chassis.pid_turn_set(-180_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

        chassis.pid_drive_set(34,DRIVE_SPEED);
    chassis.pid_wait();

        pros::delay(250);

    chassis.pid_turn_set(-50_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(16,DRIVE_SPEED);
    chassis.pid_wait();

        chassis.pid_drive_set(-9,DRIVE_SPEED);
    chassis.pid_wait();

        chassis.pid_turn_set(-315_deg,TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(-15,DRIVE_SPEED);
    chassis.pid_wait_quick_chain();

    chassis.pid_drive_set(15,DRIVE_SPEED);
    pros::delay(50);
    Piston11.set(false);
    chassis.pid_wait();

    chassis.pid_turn_set(270_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(-60,DRIVE_SPEED, true);
    chassis.pid_wait();

        chassis.pid_drive_set(-20,50);
    chassis.pid_wait();

        Piston11.set(true);


    pros::delay(100 );

        chassis.pid_drive_set(5,DRIVE_SPEED);
    chassis.pid_wait();

    Piston11.set(true);

   skillaurtopart2();
    


}

void skillaurtopart2(){
      Piston11.set(true);
      intake2.move(127);


    chassis.drive_imu_reset(270);

    chassis.pid_turn_set(270_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_turn_set(0_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    intake2.move(127);

    chassis.pid_drive_set(25,DRIVE_SPEED);
    chassis.pid_wait();


    chassis.pid_turn_set(90_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(25,DRIVE_SPEED);
    chassis.pid_wait();

        chassis.pid_turn_set(180_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

        chassis.pid_drive_set(34,DRIVE_SPEED);
    chassis.pid_wait();

    chassis.pid_turn_set(50_deg, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(16,DRIVE_SPEED);
    chassis.pid_wait();

        chassis.pid_drive_set(-9,DRIVE_SPEED);
    chassis.pid_wait();

    chassis.pid_turn_set(315_deg,TURN_SPEED, shortest);
    chassis.pid_wait_quick();

    chassis.pid_drive_set(-12,DRIVE_SPEED);
    chassis.pid_wait_quick_chain();

    chassis.pid_drive_set(10,DRIVE_SPEED);
    pros::delay(20);
    Piston11.set(false);
    chassis.pid_wait();

    chassis.pid_turn_set(5_deg,TURN_SPEED, shortest);
    chassis.pid_wait();

    armPID.target_set(255);

    chassis.pid_drive_set(42,DRIVE_SPEED);
    chassis.pid_wait_quick_chain();

        chassis.pid_drive_set(10,50);
    chassis.pid_wait();

    pros::delay(900);

    chassis.pid_turn_set(90_deg,TURN_SPEED, shortest);
    chassis.pid_wait();

    intake2.move(0);

    armPID.target_set(1170);

    chassis.pid_drive_set(7,DRIVE_SPEED);
    chassis.pid_wait();

    chassis.pid_drive_set(-13.5,DRIVE_SPEED);
    chassis.pid_wait();



  skillautonpart3();

}

void skillautonpart3(){
   intake2.move(40);
  armPID.target_set(10);
  chassis.drive_imu_reset(90);

    chassis.pid_turn_set(90, TURN_SPEED, shortest);
    chassis.pid_wait();


    chassis.pid_turn_set(0, TURN_SPEED, shortest);
    chassis.pid_wait();


    chassis.pid_drive_set(25,DRIVE_SPEED,true);
    chassis.pid_wait();

    chassis.pid_turn_set(270, TURN_SPEED, shortest);
    chassis.pid_wait();

   // armPID.target_set(730);

    //intake2.move(0);

    chassis.pid_drive_set(26,DRIVE_SPEED,true);
    pros::delay(175);
        intake2.move(30);
    chassis.pid_wait();

    chassis.pid_turn_set(135, DRIVE_SPEED, shortest);
    chassis.pid_wait();

    intake2.move(0);

    chassis.pid_drive_set(-17,DRIVE_SPEED, true);
    chassis.pid_wait_quick_chain();

    chassis.pid_drive_set(-18,DRIVE_SPEED,true);
    chassis.pid_wait();

    

    Piston11.set(true);
    intake2.move(127);
    pros::delay(150);

    chassis.pid_turn_set(220, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(36,DRIVE_SPEED,true);
    chassis.pid_wait();

    chassis.pid_turn_set(270, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(20 ,DRIVE_SPEED,true);
    chassis.pid_wait();
        pros::delay(100);
    chassis.pid_turn_set(220, TURN_SPEED, shortest);
    chassis.pid_wait();

    chassis.pid_drive_set(25 ,DRIVE_SPEED,true);  

    chassis.pid_wait();

        pros::delay(300);

    chassis.pid_drive_set(-0.5 ,DRIVE_SPEED);
    chassis.pid_wait_quick_chain();

   chassis.pid_turn_set(90, TURN_SPEED, shortest);
   chassis.pid_wait_quick_chain();

   chassis.pid_drive_set(5 ,DRIVE_SPEED);
    chassis.pid_wait_quick_chain();

    chassis.pid_turn_set(0, TURN_SPEED, shortest, true);
    chassis.pid_wait_quick_chain();

    chassis.pid_drive_set(60 ,DRIVE_SPEED,true);  
    chassis.pid_wait();

       chassis.pid_turn_set(115, TURN_SPEED, shortest);
chassis.pid_wait();


   Piston11.set(false);

   intake2.move(-127);

      chassis.pid_drive_set(5 ,DRIVE_SPEED);
 chassis.pid_wait();

   Piston11.set(true);



          chassis.pid_drive_set(-14 ,DRIVE_SPEED);
  chassis.pid_wait();

      chassis.pid_drive_set(10 ,30);
    chassis.pid_wait_quick_chain();

      chassis.pid_drive_set(26 ,DRIVE_SPEED);
    chassis.pid_wait_quick_chain();

      chassis.pid_turn_set(65, TURN_SPEED, shortest);
      chassis.pid_wait();

      chassis.pid_drive_set(80 ,DRIVE_SPEED);
    chassis.pid_wait_quick_chain();

      chassis.pid_drive_set(-18 ,DRIVE_SPEED);
      chassis.pid_wait();

        chassis.pid_turn_set(35, TURN_SPEED, shortest);
      chassis.pid_wait();

      chassis.pid_drive_set(-40 ,DRIVE_SPEED);

      armPID.target_set(1600);
      intake2.move(0); 


      chassis.pid_wait();

      chassis.pid_drive_set(-20 ,DRIVE_SPEED);
      chassis.pid_wait_quick_chain();

      chassis.pid_drive_set(10 ,DRIVE_SPEED);
      chassis.pid_wait();




      






}


void backup(){

  chassis.pid_drive_set(-5 ,DRIVE_SPEED);
      chassis.pid_wait_quick_chain();

}





void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater th   an the slew distance + a few inches

  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  //chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  //chassis.pid_wait();

  //chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  //chassis.pid_wait();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is the target in degrees
  // The second parameter is max speed the robot will drive at

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // pid_wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(24_in, 30, true);
  chassis.pid_wait_until(6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
  chassis.pid_drive_set(-24_in, 30, true);
  chassis.pid_wait_until(-6_in);
  chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
  chassis.pid_wait();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is the target in degrees
  // The third parameter is the speed of the moving side of the drive
  // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

  chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
  chassis.pid_wait();
}

///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backward
    printf("i - %i", i);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait();

    // If failsafed...
    if (chassis.interfered) {
      chassis.drive_sensor_reset();
      chassis.pid_drive_set(-2_in, 20);
      pros::delay(1000);
    }
    // If the robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, the robot will drive forward and turn 90 degrees.
// If interfered, the robot will drive forward and then attempt to drive backward.
void interfered_example() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}

// . . .
// Make your own autonomous functions here!

void red_right_corner(){

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

      chassis.pid_turn_set(155, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(65_in, DRIVE_SPEED);



  intake2.move(127);




  chassis.pid_wait();  

  chassis.pid_drive_set(2_in, DRIVE_SPEED);
  chassis.pid_wait();  
  
  pros::delay(350);


  armPID.target_set(10);

    chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();  


  
  
}



void red_right_awp(){
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


  
  











  





}



void blue_right_awp(){
  int i = 0;
  armPID.target_set(1360);
  while (i < 400){
  //  arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  //arm.move(armPID.compute(arm.get_position()));


    armPID.target_set(40);
  while (i < 800){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  //arm.move(armPID.compute(arm.get_position()));

  chassis.pid_turn_set(45_deg, TURN_SPEED);

  i = 0;
  armPID.target_set(10);
  while (i < 300){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  //arm.move(armPID.compute(arm.get_position()));

  chassis.pid_wait();

  chassis.pid_drive_set(-32_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 80);
  chassis.pid_wait();

   Piston11.set(true);
   pros::delay(100);

  chassis.pid_turn_set( 20_deg, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(34_in, 70);

  i = 0;
  armPID.target_set(1360);

    while (i < 300){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  //arm.move(armPID.compute(arm.get_position()));

  chassis.pid_wait();

  pros::delay(1000);

  chassis.pid_drive_set(-30_in, DRIVE_SPEED);
  chassis.pid_wait();

   i = 0;
  armPID.target_set(10);

    while (i < 350){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_turn_set( 150_deg, TURN_SPEED);
  chassis.pid_wait();

    chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();


    chassis.pid_drive_set(-36_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);
  chassis.pid_turn_set( - 20_deg, TURN_SPEED);
  chassis.pid_wait();

    chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();




  











  





}


void goalrushblue(){

  chassis.pid_drive_set(41_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45, TURN_SPEED);
  chassis.pid_wait();

  int i = 0;

  armPID.target_set(1300);
  while (i < 300){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(3_in, DRIVE_SPEED);
  chassis.pid_wait();

  i = 0;

  armPID.target_set(1600);
  while (i < 300){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(-18_in, 40);
  chassis.pid_wait();

  i = 0;

  armPID.target_set(40);
  while (i < 400){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_turn_set(135, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  

  armPID.target_set(1700);
  while (i < 400){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();

  
  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  armPID.target_set(40);

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  

  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-140, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(38_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  Piston22.set(true);

  chassis.pid_drive_set(6_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-100, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-36_in, DRIVE_SPEED);
  chassis.pid_wait();





}







void goalrush(){

  chassis.pid_drive_set(41_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45, TURN_SPEED);
  chassis.pid_wait();

  int i = 0;

  armPID.target_set(1300);
  while (i < 300){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(3_in, DRIVE_SPEED);
  chassis.pid_wait();

  i = 0;

  armPID.target_set(1600);
  while (i < 300){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(-28_in, 40);
  chassis.pid_wait();

    chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();

  i = 0;

  armPID.target_set(40);
  while (i < 400){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_turn_set(-135, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  

  armPID.target_set(1750);
  while (i < 400){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(30_in, 70);
  chassis.pid_wait();

  pros::delay(500);

  
  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  armPID.target_set(40);

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();

  

  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(140, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(38_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  Piston22.set(true);

  chassis.pid_drive_set(6_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(100, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-36_in, DRIVE_SPEED);
  chassis.pid_wait();





/*
  

  chassis.pid_drive_set(-4_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_turn_set(-25, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(false);

  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-55, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_turn_set(130, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

    i = 0;
  armPID.target_set(1700);

    while (i < 300){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(32_in, DRIVE_SPEED);
  chassis.pid_wait();



*/




}


void skillptwo(){
  int i = 0;
  chassis.pid_turn_set(165, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-60_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-32_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_drive_set(120_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(50, TURN_SPEED);
  chassis.pid_wait();

  i = 0;

  armPID.target_set(1600);
  while (i < 300){
    
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(-120_in, DRIVE_SPEED);
  chassis.pid_wait();






}


void scillsauto(){
  int i = 0;
  chassis.drive_imu_reset(-117);

  Piston11.set(false);


  i = 0;
  armPID.target_set(1850);
  while (i < 400){
    //arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_turn_set(-117, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-17_in, 127);
  i = 0;
  armPID.target_set(40);
  while (i < 300){
   // arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  chassis.pid_wait();

  Piston11.set(true);
  pros::delay(300);

    chassis.pid_drive_set(2_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(55, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(29_in, DRIVE_SPEED);

  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 70);
  chassis.pid_wait();


 /* pros::delay(1000);

  intake2.move(0);

  i = 0;
  armPID.target_set(1600);
  while (i < 300){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();

  
  chassis.pid_drive_set(-7_in, DRIVE_SPEED);
  chassis.pid_wait();

 // chassis.pid_drive_set(5_in, DRIVE_SPEED);
 // chassis.pid_wait();

    i = 0;
  armPID.target_set(40);
  while (i < 100){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  intake2.move(127);

  */

  chassis.pid_drive_set(-7_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(55_in, 70);
  chassis.pid_wait();

  pros::delay(500);

  chassis.pid_turn_set(65, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-45, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(false);

  chassis.pid_drive_set(15_in, 65);
  chassis.pid_wait();

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-60_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-15_in, 65);
  chassis.pid_wait();





  //second part of code second side


  Piston11.set(true);
  pros::delay(300);

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(29_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-55, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(28_in, DRIVE_SPEED);
/*
  i = 0;
  armPID.target_set(275);
  while (i < 275){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  */

  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 70);
  chassis.pid_wait();
 
  //arm.move(armPID.compute(arm.get_position()));

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  //pros::delay(600);

  intake2.move(0);

/*
  i = 0;
  armPID.target_set(1600);
  while (i < 300){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  
  chassis.pid_drive_set(8_in, DRIVE_SPEED);
  chassis.pid_wait();

  
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(3_in, DRIVE_SPEED);
  chassis.pid_wait();

    i = 0;
  armPID.target_set(40);
  while (i < 100){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  */

  intake2.move(127);

  chassis.pid_drive_set(-7_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-180, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(55_in, 70);
  chassis.pid_wait();

  pros::delay(500);

  chassis.pid_turn_set(-65, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(false);

  chassis.pid_drive_set(20_in, 65);
  chassis.pid_wait();
  //thrid part pain

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(48_in, DRIVE_SPEED);
  chassis.pid_wait();

  //chassis.pid_turn_set(-135, TURN_SPEED);
 // chassis.pid_wait();

 skillptwo();

}






void red_far_side(){
  Piston11.set(false);
  chassis.pid_drive_set(14.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-7_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(127);
  pros::delay(500);
  intake2.move(0);

  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(55_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-32_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-6_in, 80);
  pros::delay(150);
  Piston11.set(true);
  chassis.pid_wait();

  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(24_in, 70);
  chassis.pid_wait();

  chassis.pid_turn_set(270_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(250_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(6_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-6_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(280_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(6.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-9.5_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(36_in, DRIVE_SPEED);
  chassis.pid_wait();

  /**chassis.pid_turn_set(25_deg, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(36_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();


  intake2.move(0);

   arm.move_relative(360, 100);

  chassis.pid_drive_set(-16_in, 60);
  chassis.pid_wait();

  **/


  
  

  







}

void blue_far_side(){
  Piston11.set(false);
  chassis.pid_drive_set(14.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-7_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(127);
  pros::delay(500);
  intake2.move(0);

  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-55_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-32_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-6_in, 80);
  pros::delay(150);
  Piston11.set(true);
  chassis.pid_wait();

  chassis.pid_turn_set(-180_deg, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(24_in, 70);
  chassis.pid_wait();

  chassis.pid_turn_set(-270_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-250_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(6_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-6_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-280_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(6.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-9.5_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(36_in, DRIVE_SPEED);
  chassis.pid_wait();

  /**chassis.pid_turn_set(25_deg, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(36_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();


  intake2.move(0);

   arm.move_relative(360, 100);

  chassis.pid_drive_set(-16_in, 60);
  chassis.pid_wait();

  **/


  
  

  





}



void goforwardauton(){

  chassis.pid_drive_set(-34_in, 60);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_drive_set(-8_in, 60);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(28_in, 60);
  chassis.pid_wait();
/*
  Piston22.set(true);

  //intake2.move(0);

  chassis.pid_drive_set(41_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(25_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(25_deg, TURN_SPEED);
  chassis.pid_wait();

  Piston11.set(false);

  chassis.pid_drive_set(-4_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-44_in, DRIVE_SPEED);
  chassis.pid_wait(); 

*/
}







// . . .
void nick_is_testing(){

  //armPID.target_set(240);

  intake2.move(127);

  pros::delay(400);

  intake2.move(-2);

  //armPID.target_set(550);

  Piston22.set(true);

  intake2.move(62);

  chassis.pid_drive_set(39.0_in, 120);
  chassis.pid_wait();

  intake2.move(0);


  Piston737.set(true);

  chassis.pid_drive_set(-29_in, DRIVE_SPEED);
  chassis.pid_wait();
  
  Piston737.set(false);

  chassis.pid_drive_set(-5.0_in, 120);
  chassis.pid_wait();

  Piston22.set(false);




  chassis.pid_turn_set(-160_deg, TURN_SPEED, shortest, true);
  chassis.pid_wait();
  

  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait(); 

  chassis.pid_drive_set(-10_in, 45); 
  chassis.pid_wait(); 

  Piston11.set(true);

   intake2.move(127);

   chassis.pid_turn_set(-117_deg, 70, shortest, true);
  chassis.pid_wait();

  chassis.pid_drive_set(57_in, DRIVE_SPEED);
  chassis.pid_wait();

  //armPID.target_set(660);

  chassis.pid_turn_set(-60_deg, 70, shortest, true);
  chassis.pid_wait(); 

  chassis.pid_drive_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

   Piston11.set(false);

   intake2.move(-110);

   //armPID.target_set(0);

   chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(127);

    chassis.pid_turn_set(-150_deg, 70, shortest, true);
  chassis.pid_wait(); 

  chassis.pid_drive_set(-24_in, DRIVE_SPEED);
  chassis.pid_wait();

   chassis.pid_drive_set(-12_in, 60);
  chassis.pid_wait();

  Piston11.set(true);

  intake2.move(127);
//this is if we want to get the ring next to the allaince stake

chassis.pid_turn_set(-121_deg, 70, shortest, true);
  chassis.pid_wait();

   armPID.target_set(1750);

   chassis.pid_drive_set(40_in, DRIVE_SPEED);
  chassis.pid_wait();

//this is when we go to the center to get the ring 
  //chassis.pid_turn_set(-382_deg, 70, shortest, true);
  //chassis.pid_wait();


  //chassis.pid_drive_set(27_in, 110);
  //chassis.pid_wait();


  //Piston22.set(true);

  //pros::delay(400);

  //chassis.pid_drive_set(-33_in, 110);
  //chassis.pid_wait();

  //Piston22.set(false);

  //intake2.move(127);

  //chassis.pid_turn_set(-360_deg, 70, shortest, true);
  //chassis.pid_wait();

  //chassis.pid_drive_set(20_in, 127);
   //chassis.pid_wait(); 
//this is if we want to end in the corner, put this after we back up into mogo -24 in, -12 in
  //chassis.pid_turn_set(-208_deg, 70, shortest, true);
  //chassis.pid_wait(); 

  //chassis.pid_drive_set(46_in, DRIVE_SPEED);
  //chassis.pid_wait();

  //armPID.target_set(800 )
}



void mogorushfunnicktest(){
  armPID.target_set(245);
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


  




}


void bluesidefunmogorush(){
    armPID.target_set(245);
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

  chassis.pid_turn_set(15, TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(4_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  armPID.target_set(2100);

  pros::delay(500);
  armPID.target_set(10);
    pros::delay(200);
    chassis.pid_turn_set(-75, 60, shortest);
      pros::delay(200);
  armPID.target_set(10);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(220, 60, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(-28_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();

  Piston11.set(true);


pros::delay(200);
  

    chassis.pid_turn_set(195,  TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(48_in, DRIVE_SPEED);



  intake2.move(127);

  chassis.pid_wait();  
  
  
  pros::delay(350);

    chassis.pid_drive_set(-40_in, DRIVE_SPEED);
  chassis.pid_wait();  





}

void bluesidemogorushbutdiffrent(){
      armPID.target_set(245);
  intake2.move(127);
  chassis.pid_drive_set(36_in, DRIVE_SPEED);
  Piston22.set(true);
  chassis.pid_wait_until(34_in);
  Piston737.set(true);
  chassis.pid_wait_quick_chain();


  chassis.pid_drive_set(-40_in, DRIVE_SPEED);
  chassis.pid_wait();

      intake2.move(0);


  Piston737.set(false);

  armPID.target_set(500);

  Piston22.set(false);

  chassis.pid_turn_set(15, TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(4_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  armPID.target_set(2200);

  pros::delay(500);
  armPID.target_set(10);
    pros::delay(1200);
    chassis.pid_turn_set(-75, 60, shortest);
      pros::delay(200);
  armPID.target_set(10);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(220, 60, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(-28_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-4_in, 50);
  chassis.pid_wait();

  Piston11.set(true);


pros::delay(200);
  

    chassis.pid_turn_set(195, TURN_SPEED, shortest);
  chassis.pid_wait();

  chassis.pid_drive_set(48_in, DRIVE_SPEED);



  intake2.move(127);

  chassis.pid_wait();  
  
  
  pros::delay(350);


  chassis.pid_turn_set(270, TURN_SPEED, shortest);
  chassis.pid_wait();

    chassis.pid_drive_set(50_in, DRIVE_SPEED);
    chassis.pid_wait_until(24_in);
    chassis.pid_speed_max_set(35);
  chassis.pid_wait();  

  chassis.pid_drive_set(-12_in, 70);
  chassis.pid_wait();

  chassis.pid_drive_set(12_in, 40);
  chassis.pid_wait();

  
 

 



  
}
#include "main.h"
#include "arm.cpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 70;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(12.3, 0.6, 99);
  chassis.pid_turn_constants_set(2.8, 0.053, 21, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
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
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

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

  chassis.pid_turn_set(25_deg, TURN_SPEED);
  chassis.pid_wait();

  Piston22.set(true);

  //intake2.move(0);

  chassis.pid_drive_set(41_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-25_deg, TURN_SPEED);
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


}



void scillsauto(){
  Piston11.set(false);
  intake2.move(127);
  pros::delay(300);
  intake2.move(0);

  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, 70);
  chassis.pid_wait();

  Piston11.set(true);
  pros::delay(300);

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(127);

  chassis.pid_drive_set(24_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(55, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 70);
  chassis.pid_wait();

  int i = 0;
  armPID.target_set(400);
  while (i < 275){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  arm.move(armPID.compute(arm.get_position()));

  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();

  i = 0;
  armPID.target_set(1600);
  while (i < 300){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(3_in, DRIVE_SPEED);
  chassis.pid_wait();

    i = 0;
  armPID.target_set(300);
  while (i < 100){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  intake2.move(127);

  chassis.pid_drive_set(-13_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(55_in, 80);
  chassis.pid_wait();

  pros::delay(500);

  chassis.pid_turn_set(90, TURN_SPEED);
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

  chassis.pid_drive_set(24_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(-55, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(10_in, 70);
  chassis.pid_wait();

  i = 0;
  armPID.target_set(400);
  while (i < 275){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }
  arm.move(armPID.compute(arm.get_position()));

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();

  i = 0;
  armPID.target_set(1600);
  while (i < 300){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(3_in, DRIVE_SPEED);
  chassis.pid_wait();

    i = 0;
  armPID.target_set(200);
  while (i < 200){
    arm.move(armPID.compute(arm.get_position()));
    pros::delay(2);
    i++;
  }

  intake2.move(127);

  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(55_in, 80);
  chassis.pid_wait();

  pros::delay(500);

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(14_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait();

  Piston11.set(false);

  chassis.pid_drive_set(15_in, 65);
  chassis.pid_wait();

  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait();

  //thrid part pain

  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(48_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_turn_set(45, TURN_SPEED);
  chassis.pid_wait();

 intake2.move(127);
  
  chassis.pid_drive_set(32_in, DRIVE_SPEED);
  chassis.pid_wait();

 
  pros::delay(500);
  intake2.move(0);

  chassis.pid_turn_set(-135, TURN_SPEED);
  chassis.pid_wait();

   chassis.pid_drive_set(-32_in, 60);
  chassis.pid_wait();

  chassis.pid_drive_set(-6_in, 70);
  pros::delay(50);

  Piston11.set(true);

  intake2.move(127);

  chassis.pid_wait();

  chassis.pid_turn_set(-95, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-32_in, 60);
  chassis.pid_wait();

  Piston11.set(true);

  chassis.pid_turn_set(-120, TURN_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  chassis.pid_drive_set(-40_in, 80);
  chassis.pid_wait();

  Piston11.set(false);

  chassis.pid_turn_set(100, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-144_in, DRIVE_SPEED);
  chassis.pid_wait();







}





// . . .
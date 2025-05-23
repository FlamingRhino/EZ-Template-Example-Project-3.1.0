#include "main.h"
#include "autons.hpp"
#include <stdio.h>
#include "EZ-Template/piston.hpp"
#include "EZ-Template/util.hpp"
#include "arm.cpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

//overshoot turns by 12 inches

// These are out of 127


inline int DRIVE_SPEED = 110;
inline int TURN_SPEED = 70;
inline const int SWING_SPEED = 90;
inline int antijam = 0;



// Constants
///

inline void antijamtask(){
  int timerthing = 0;
  float intake2speed = intake2.get_target_velocity();
  while (true) {
  while(antijam == 1){
    if(intake2.get_actual_velocity() + 100 < intake2.get_target_velocity() && intake2.get_target_velocity() > 0 && false){
      intake2.move(127);
      timerthing++;
      if (timerthing > 15){
        intake2speed = intake2.get_target_velocity();
        //intake2.move(-127);
        pros::delay(150);
        if(intake2.get_target_velocity()< -110){
          intake2.move(intake2speed);
        }
          

          
      }
    }else{
      timerthing = 0;
    }
    pros::delay(20);
  }
  pros::delay(20);
}

}

static bool timer(int time) {
  pros::delay(time);
  return 1;
}

inline void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  //chassis.pid_drive_constants_set(28, 0.6, 150);
  chassis.pid_drive_constants_set(12.3, 0.6, 99);
  chassis.pid_turn_constants_set(3.4, 0.052, 22.5, 16); // 3.4 0.052 22.5 16.0
  chassis.pid_swing_constants_set(6, 0, 65);
  chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(1.1, 0, 30.5);  // Angular control for boomerang motions


  chassis.pid_turn_exit_condition_set(150_ms, 4_deg, 450_ms, 8_deg, 300_ms, 300_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(10_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there



}
#include "EZ-Template/util.hpp"
#include "constantsauton.cpp"
#include "pros/rtos.hpp"
#include "subsystems.hpp"
///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();
  
  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

void odom_red_rush(){
  armPID.target_set(290);
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

  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();

  intake2.move(0);

  armPID.target_set(1850);

  pros::delay(500);

  intake2.move(127);
  armPID.target_set(10);
    pros::delay(1200);

  armPID.target_set(290);

  chassis.pid_turn_set(-139_deg, 90);
  chassis.pid_wait();

  chassis.pid_odom_set({{-6.5_in, -12_in}, fwd, 90});
  chassis.pid_wait();

  chassis.pid_odom_set({{{-26.5_in, 4_in, -74.3_deg}, fwd, 90},
                                        {{-50.5_in, 4.4_in, -123.8_deg}, fwd, 90}
  });
  chassis.pid_wait();

  armPID.target_set(1520);
  intake2.move(0);
  pros::delay(600);

  chassis.pid_odom_set({{{-18.1_in, 19.8_in, -136.1_deg}, rev, 90},
    {{15.5_in, 19.5_in, -92_deg}, rev , 90}
});
 
  pros::delay(100);
  armPID.target_set(10);
  chassis.pid_wait_until({-26.5_in, 4_in});
  Piston11.set(true);
  chassis.pid_wait();
  chassis.pid_wait();













} 

void awpodomcode(){
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency



  chassis.pid_odom_set({{0_in, 10.6_in}, fwd, 110});
  pros::delay(225);
  chassis.pid_wait();

  armPID.target_set(1520);
  intake2.move(0);
  pros::delay(700);

  intake2.move(127);

  chassis.pid_odom_set({{0_in, -31.3_in, 6_deg}, rev, 80});
  pros::delay(200);
  armPID.target_set(10);
  chassis.pid_wait_until({0,-15});
  chassis.pid_speed_max_set(60); 
  chassis.pid_wait_until({0,-29});
  Piston11.set(true);
  chassis.pid_wait();



  chassis.pid_odom_set({{8.8_in, -4.9_in, 8_deg}, fwd, 80});
  chassis.pid_wait();

  chassis.pid_odom_set({{2.2_in, -30_in}, rev, 80});
  chassis.pid_wait();

  chassis.pid_turn_set(-70_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-120_deg, 90,true);
  chassis.pid_wait();

  chassis.pid_odom_set({{-26_in, -45_in}, fwd, 80});
  chassis.pid_wait();

  chassis.pid_odom_set({ {{2_in, -30_in, -120_deg}, rev, 80},
                                      {{10_in, -28_in, -200_deg}, rev, 80},
                          {{12_in, -42_in, -200_deg}, fwd, 80}},true);
  chassis.pid_wait();




  



}

void odomtestcool(){
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  chassis.pid_odom_set({{10_in, -15.5_in, 8_deg}, rev, 80},true);
  chassis.pid_wait();





}

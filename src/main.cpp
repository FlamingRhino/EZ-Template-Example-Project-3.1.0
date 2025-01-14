#include "main.h"
#include "arm.cpp"
#include "colors.cpp"


int time_form_op_start = 0;

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-10, 9, -17},     // Left Chassis Ports (negative port will reverse it!)
    {20, -19, 18},  // Right Chassis Ports (negative port will reverse it!)

    5,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::ez_template_print();

  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(false);  // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(2.1, 4.3);    // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
   chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
    Auton("mogorushfun mogorushfun mogorushfun", mogorushfun),
    Auton("Skills skills 3333333333333333333333333333333333333333333333", skillautonpart3),
      Auton("Skills skills jojooppopojojoppjojoppojojpjopojpopopojopjpopopjo", goodskillcode),
      Auton("Skills skills part 222222222222", skillaurtopart2),
    Auton("aawwwpppw", sigawp),
    Auton("BLUe RGIHT SIDE AWPAWPAWPAWPAWPAWPAWPAWP AWP you can also use this on the left red side", blue_right_awp),
    Auton("RED RIGHT SIDE AWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWP BLUEBLUEBLUEBLUEBLUEBLUEBLUEBLUEBLUE AWP you can also use this on the left blue side" , red_right_awp),
    Auton("goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush", goalrush),
    Auton("blue side goal rush This is the stake code for the blue side should work  ", goalrushblue),
     Auton("skills code which might work, SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS", scillsauto),
     Auton("thia will start skills at the back side, shoud work", skillptwo),
      Auton("red far side but also work with RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED RED ", red_far_side),
      Auton("Blue far side, get most of win point BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE BLUE", blue_far_side),
      Auton("go forward go forward go forward  go forward go forward go forward go forward go forward  go forward go forward go forward go forward go forward  go forward go forward go forward go forward go forward  go forward go forward", goforwardauton),
      Auton("PID loop test code to move up one foot and turn around and come back", drive_example),
      Auton("Example Turn\n\nTurn 3 times.", turn_example),
      Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
      Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
      Auton("Swing Example\n\nSwing in an 'S' curve", swing_example),
      Auton("Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining),
      Auton("Combine all 3 movements", combining_movements),
      Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");


  //my random stuff


//  armPID.exit_condition_set(80, 50, 300, 150, 500, 500);
 // arm.tare_position();
 // l_arm.tare_position();
//





}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency
  l_arm.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  r_arm.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  time_form_op_start = 0;
  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
  

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
//random funtions I will make becuese no one likes object oraented progarming

void nicksl2thing(){

  //the wierd toggle that nick wanted
  intake2.move(0);
  
  //this is how long you wait for the intake to revese
  pros::delay(120);
  if (master.get_digital(DIGITAL_L2) == 1){
      intake2.move(-127);
      bool nicktoggle = true;
      while (nicktoggle = true)
      {
        if(master.get_digital(DIGITAL_L2) == 0){
          intake2.move(0);

          break;
        }
        pros::delay(10);
      }
      
    }
}
//super abd code tht does not work

//NICKNICKNICKNICKNICKNICKNIKNICKNICK


void clockthing(){
    int timer = 0;
    while (true) {

      if (time_form_op_start == 87){
        master.rumble("-.--.");
      }
      


      pros::delay(1000);
        
  } 
}






void opcontrol() {
  // This is preference to what you like to drive on
   
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_HOLD;

  chassis.drive_brake_set(driver_preference_brake);

  int armcurrentpos = 0;

  //arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  float armspeed = 127;

  //armPID.target_set(60);

  double target = 0.0;
  double error = 0.0;
  rotation_sensor.set_position(0);

  int time_form_op_start = 0;
  pros::Task clockthingg(clockthing);

  int randomscare = 0;

  srand(static_cast<unsigned int>(time(0)));


  int count = 0;

  Color.set_led_pwm(100);

  pros::Task colorTASK(colortask);


  while (true) {
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    //left_wing.button_toggle(master.get_digital(DIGITAL_X));

    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_Y))
        chassis.pid_tuner_toggle();


      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }

    //chassis.opcontrol_tank();  // Tank control
    chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .


          error = target - rotation_sensor.get_angle();
     //arm.move(armPID.compute_error(error, arm.get_position()));
    //pistons-upersimple
    Piston11.buttons(master.get_digital(DIGITAL_R1), master.get_digital(DIGITAL_R2));
    Piston22.buttons(master.get_digital(DIGITAL_UP), master.get_digital(DIGITAL_DOWN));
   // Sorter.button_toggle(master.get_digital(DIGITAL_RIGHT));

    //intake code
        
    if (master.get_digital(DIGITAL_L1) == 1){
      intake2.move(127);
    }
    //intake revse
    if (master.get_digital(DIGITAL_L2) == 1){
      nicksl2thing();
    }
    //move arm to pos code
  
    if (master.get_digital_new_press(DIGITAL_X)){  
      //pos   
      
      //pos 2    
      if (armcurrentpos  ==  1){

        armPID.target_set(1600);
        target = 0;
        armcurrentpos = 0;
        

      }else if (armcurrentpos  == 0){

        armPID.target_set(275);
        target = -500;
        armcurrentpos = 1;

        
      }

    }
    //resting place for arm
    if (master.get_digital(DIGITAL_B)){

      armPID.target_set(20);
      target = 115;
      
      armcurrentpos = 0;

    }


    if (master.get_digital(DIGITAL_A)){

      armPID.target_set(1850);
    
    }

      

    


            //arm.move(armPID.compute(rotation_sensor.get_angle()));


            if (!pros::competition::is_connected()) {

              randomscare = rand() % 1000000 + 1;

              if (randomscare == 3){

                master.rumble("-");
                
              }
            }

    
    if (!(count % 25)) {
      // Only print every 50ms, the controller text update rate is slow
      //master.print(1, 0, "Heading: %f", chassis.drive_imu_get());
    }
    count++;

        if (ez::as::page_blank_is_on(0)) {
         ez::screen_print("facing: " + util::to_string_with_precision( chassis.drive_imu_get()), 1);
    }



    


    
  

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
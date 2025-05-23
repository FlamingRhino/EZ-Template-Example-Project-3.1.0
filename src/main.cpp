#include "main.h"
#include "EZ-Template/auton.hpp"
#include "EZ-Template/util.hpp"
#include "autons.hpp"
#include "colors.cpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "subsystems.hpp"

#include "constantsauton.cpp"


int time_form_op_start = 0;
static int intakespeed = 127;

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {2, -1, -5}, // Left Chassis Ports (negative port will reverse it!)
    {-9, 10, 7, }, 
 // Right Chassis Ports (negative port will reverse it!)
    3,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM

// Uncomment the trackers you're using here!
// - `8` and `9` are smart ports (making these negative will reverse the sensor)
//  - you should get positive values on the encoders going FORWARD and RIGHT
// - `2.75` is the wheel diameter
// - `4.0` is the distance from the center of the wheel to the center of the robot
ez::tracking_wheel horiz_tracker(1, 2, 3.55);  // This tracking wheel is perpendicular to the drive wheels
//ez::tracking_wheel vert_tracker(9, 2, 4.0);   // This tracking wheel is parallel to the drive wheels


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

    chassis.odom_enable(true);


    // Look at your horizontal tracking wheel and decide if it's in front of the midline of your robot or behind it
  //  - change `back` to `front` if the tracking wheel is in front of the midline
  //  - ignore this if you aren't using a horizontal tracker
  //chassis.odom_tracker_front_set(&horiz_tracker);
  // Look at your vertical tracking wheel and decide if it's to the left or right of the center of the robot
  //  - change `left` to `right` if the tracking wheel is to the right of the centerline
  //  - ignore this if you aren't using a vertical tracker
  //chassis.odom_tracker_left_set(&vert_tracker);

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
    {Auton("RED SIDE BAKER AUTON WITH WALL STAKE \n START THIS CODE ON THE RED POS A-STAKE \n RYAN DOES NOT BELIVE IN THIS CODE \n NICK ", redqualbakerauton)},
    Auton{"THIS IS THE FINALS CODE FOR RED THATS KIND OF IT", midle_ring_rush },
    Auton("THIS IS THE FINALS CODE FOR BLUE BLUE THATS KIND OF IT ", midle_ring_rushblue),
    Auton("RED SIDE STATE AWP \n START THIS CODE ON RED NEGTIVE A-STAKE \n YOU CAN ALSO START THIS CODE ON BLUE POS A-STAKE \n THIS CODE WILL GET THE MIN. FOR AWP AT STATES.", awpstatefunworkPLANE),
    {Auton("RED SIDE BAKER AUTON WITH WALL STAKE \n START THIS CODE ON THE RED POS A-STAKE \n RYAN DOES NOT BELIVE IN THIS CODE \n NICK ", redqualbakerauton)},
    Auton{"THIS IS THE FINALS CODE FOR RED THATS KIND OF IT", midle_ring_rush },
    Auton("THIS IS THE OLD NORMAL AWP CODE \n RYAAAAAAAN PLEASE FIX IF WE WANT TO USE" , red_right_awp),
    Auton("Skills skills jojooppopojojoppjojoppojojpjopojpopopojopjpopopjo", goodskillcode),
        {Auton("RED SIDE BAKER AUTON WITH WALL STAKE \n START THIS CODE ON THE RED POS A-STAKE \n RYAN DOES NOT BELIVE IN THIS CODE \n NICK ", redqualbakerauton)},
    Auton("MOGO RUSH RED ANICNECE STAKE", mogorushwallblue),
    Auton("MOGO RUSH RED ANICNECE STAKE", mogorushfun),
    Auton("BLUe RGIHT SIDE AWPAWPAWPAWPAWPAWPAWPAWP AWP you can also use this on the left red side", blue_right_awp),
    Auton("RED RIGHT SIDE AWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWPAWP BLUEBLUEBLUEBLUEBLUEBLUEBLUEBLUEBLUE AWP you can also use this on the left blue side" , red_right_awp),
      Auton("RED RIGHT SIDE CORNER CODE THIS IS LIKE THE AWP CODE BUT GETS THE CORNER" , red_right_corner),
    Auton("sig awp red side left side and also blue lrft  side RED SIG AWP RED SIG AWP RED SGI AWP", sigawp),
    Auton("sig awp blue side right side and also red right side BLUE SIG AWP BLUE SIG AWP BLUE SIG AWP BLUE SIG AWP", sigawpmirrored),
    Auton("ringrush starts negtive side BLUEBLUELBUELBUEBLUE BLUEBLue", ringrushblue),
      Auton("ringrush stars negtive side red REDREDRED", ringrush),
      Auton("sig awp red side left side and also blue lrft  side RED SIG AWP RED SIG AWP RED SGI AWP", sigawp),
    Auton("sig awp blue side right side and also red right side BLUE SIG AWP BLUE SIG AWP BLUE SIG AWP BLUE SIG AWP", sigawpmirrored),
    Auton("mogorushfun mogorushfun mogorushfun", mogorushfun),
    Auton("Skills skills jojooppopojojoppjojoppojojpjopojpopopojopjpopopjo", goodskillcode),
    Auton("Skills skills 3333333333333333333333333333333333333333333333", skillautonpart3),
      Auton("Skills skills part 222222222222", skillaurtopart2),
    Auton("goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush goal rush", goalrush),
    Auton("blue side goal rush This is the stake code for the blue side should work  ", goalrushblue),
     Auton("skills code which might work, SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS SKILLS SKILL SKILLS", scillsauto),
     Auton("thia will start skills at the back side, shoud work", skillptwo),
      Auton("Example Turn\n\nTurn 3 times.", turn_example),
      Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
      Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
      Auton("Swing Example\n\nSwing in an 'S' curve", swing_example),
      Auton("Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining),
      Auton("Combine all 3 movements", combining_movements),
      Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
      Auton("nick is testing code", nick_is_testing),
      Auton("3 top ring, goal rush ", nick_is_testing),
      Auton("1 top ring, 2 ring, goal rush BLUE SIDE BLUE SIDE MOGO RUSH ends at ladder", bluesidemogorushbutdiffrent),
            Auton("1 top ring, 2 ring, goal rush BLUE SIDE BLUE SIDE MOGO RUSH", bluesidefunmogorush),
      Auton("1 top ring, 2 ring, goal rush ",mogorushfunnicktest),
      Auton("thing", backup),
      Auton{"test to see the pos of odom pods or something", measure_offsets},
      {Auton("RED SIDE BAKER AUTON WITH WALL STAKE \n START THIS CODE ON THE RED POS A-STAKE \n RYAN DOES NOT BELIVE IN THIS CODE \n THIS IS RED RED RED RED RED ", redqualbakerauton)},
      Auton{"THIS IS THE FINALS CODE FOR BLUE BLUE THATS KIND OF IT", midle_ring_rush },
      Auton("THIS IS THE OLD NORMAL AWP CODE BUT BLUE \n RYAAAAAAAN PLEASE FIX IF WE WANT TO USE" , blue_right_awp),
          Auton("BLUE SIDE BAKER AUTON WITH WALL STAKE \n START THIS CODE ON THE BLUE POS A-STAKE \n RYAN REALY DOES NOT BELIVE IN THIS CODE \n NICK ", redqualbakerautonblue),
          Auton("BLUE SIDE STATE AWP \n START THIS CODE ON BLUE NEGTIVE A-STAKE \n YOU CAN ALSO START THIS CODE ON RED BLUE POS A-STAKE \n THIS CODE WILL GET THE MIN. FOR AWP AT STATES.", awpstatefunworkPLANEBlue),
          
    
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");

  Color.set_led_pwm(100);

  pros::Task colorTASK(colortask);


  l_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  r_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);




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
  colordisable = true;
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
  colordisable = false;
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency
  l_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  r_arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
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
      intake2.move(-intakespeed);
      bool nicktoggle = true;
      while (nicktoggle == true)
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

/**
 * Simplifies printing tracker values to the brain screen
 */
void screen_print_tracker(ez::tracking_wheel *tracker, std::string name, int line) {
  std::string tracker_value = "", tracker_width = "";
  // Check if the tracker exists
  if (tracker != nullptr) {
    tracker_value = name + " tracker: " + util::to_string_with_precision(tracker->get());             // Make text for the tracker value
    tracker_width = "  width: " + util::to_string_with_precision(tracker->distance_to_center_get());  // Make text for the distance to center
  }
  ez::screen_print(tracker_value + tracker_width, line);  // Print final tracker text
}

/**
 * Ez screen task
 * Adding new pages here will let you view them during user control or autonomous
 * and will help you debug problems you're having
 */
void ez_screen_task() {
  while (1==0) {
    // Only run this when not connected to a competition switch
    if (!pros::competition::is_connected()) {
      // Blank page for odom debugging
      if (chassis.odom_enabled() && !chassis.pid_tuner_enabled()) {
        // If we're on the first blank page...
        if (ez::as::page_blank_is_on(0)) {
          // Display X, Y, and Theta
          ez::screen_print("x: " + util::to_string_with_precision(chassis.odom_x_get()) +
                               "\ny: " + util::to_string_with_precision(chassis.odom_y_get()) +
                               "\na: " + util::to_string_with_precision(chassis.odom_theta_get()) +
                               "\nmotor temp left" + util::to_string_with_precision(chassis.left_motors[0].get_temperature()) + util::to_string_with_precision(chassis.left_motors[1].get_temperature()) +util::to_string_with_precision(chassis.left_motors[2].get_temperature()) +
                               "\nmotor temp right" + util::to_string_with_precision(chassis.right_motors[0].get_temperature()) + util::to_string_with_precision(chassis.right_motors[1].get_temperature()) + util::to_string_with_precision(chassis.right_motors[2].get_temperature()),
                           1);  // Don't override the top Page line

          // Display all trackers that are being used
          screen_print_tracker(chassis.odom_tracker_left, "l", 4);
          screen_print_tracker(chassis.odom_tracker_right, "r", 5);
          screen_print_tracker(chassis.odom_tracker_back, "b", 6);
          screen_print_tracker(chassis.odom_tracker_front, "f", 7);
        }
      }
    }

    // Remove all blank pages when connected to a comp switch
    else {
      if (ez::as::page_blank_amount() > 0)
        ez::as::page_blank_remove_all();
    }

    pros::delay(ez::util::DELAY_TIME);
  }
}
pros::Task ezScreenTask(ez_screen_task);






void opcontrol() {

  
  // This is preference to what you like to drive on
  antijam = 0;

   
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

  bool manualarm = false;

  colordisable = false;

  bool fristtier = false;



  
  while (true) {
    antijam = 0;

    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    //left_wing.button_toggle(master.get_digital(DIGITAL_X));



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
    if (manualarm == false){
          Piston22.button_toggle(master.get_digital(DIGITAL_LEFT));
         Piston11.button_toggle(master.get_digital(DIGITAL_R1));
    Piston737.button_toggle(master.get_digital(DIGITAL_RIGHT));
    }else{
      PTO.button_toggle(master.get_digital(DIGITAL_RIGHT));
      hangthing.button_toggle(master.get_digital(DIGITAL_LEFT));
      if (master.get_digital(DIGITAL_R1) == 1){
        //chassis.drive_set(127,  127);
      }else if (master.get_digital(DIGITAL_R2) == 1){
      //chassis.drive_set(-127,  -127);
      }else{
      //chassis.drive_set(0,  0);
      }
      if(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) > 40){
        armPID.target_set(l_arm.get_position() + 40 );
       // l_arm.move(70);
       // r_arm.move(70);
      }else if(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) < -40){
        armPID.target_set(l_arm.get_position() - 40 );
       // l_arm.move(-70);
      //  r_arm.move(-70);
      }else {
       // l_arm.move(0);
       // r_arm.move(0);
       //armPID.target_set(l_arm.get_position() );
      //  l_arm.brake();
      //  r_arm.brake();
      }
      if (!fristtier){
      if(l_arm.get_position() < 250){
        hangthing.set(0);
        fristtier = true;
      }
      }else{
        if(l_arm.get_position() < 580){
          hangthing.set(0);
          fristtier = true;
        }
      }
      if(l_arm.get_position() > 800){
        hangthing.set(1);
      }
  
}

    //PistonB29.button_toggle(master.get_digital(DIGITAL_R2));

   // Sorter.button_toggle(master.get_digital(DIGITAL_RIGHT));

    //intake code 

    if (master.get_digital(DIGITAL_L1) == 1){
      intake2.move(intakespeed);
    }
    //intake revse
    if (master.get_digital(DIGITAL_L2) == 1){
      nicksl2thing();
    }
    //move arm to pos code
    if (master.get_digital_new_press(DIGITAL_Y)){
      if(manualarm == true){
        manualarm = false;
        armPID.target_set(10);
        PTO.set(0);
        hangthing.set(0);

      }else{
        manualarm = true;
        chassis.pid_targets_reset();                // Resets PID targets to 0
        chassis.drive_imu_reset();                  // Reset gyro position to 0
        chassis.drive_sensor_reset();               // Reset drive sensors to 0
        chassis.pid_drive_set(4_in, 100);
        chassis.pid_wait();
        master.rumble("-");
        armPID.target_set(590);
        while (l_arm.get_position() < 580){
          pros::delay(10);
        }
        hangthing.set(1);
        chassis.drive_set(-30, -30);
        PTO.set(1);
        pros::delay(500);
        chassis.drive_set(0, 0);
        
      }
    }

    if (master.get_digital_new_press(DIGITAL_R2)){
      if (intakespeed == 127){
        intakespeed = 50;
    }else{
      intakespeed = 127;
    }
  }



    if (manualarm == false){
  
      if (master.get_digital_new_press(DIGITAL_X)){  
      //pos   
      
      //pos 2    
         if (armcurrentpos  ==  1){

          armPID.target_set(1200);
          target = 0;
          armcurrentpos = 0;
        

        }else if (armcurrentpos  == 0){

          armPID.target_set(255);
          armcurrentpos = 1;

        
      }

      }
     //resting place for arm
     if (master.get_digital(DIGITAL_B)){

      armPID.target_set(20);
      target = 115;

      armcurrentpos = 0;

       }


      if (master.get_digital(DIGITAL_A )){

        armPID.target_set(980);
    
     }
    } else{
      if( armPID.target_get() <= 2200000){
      if(master.get_digital(DIGITAL_X)){
        armPID.target_set(armPID.target_get() + 6);
      }

      }
      if(armPID.target_get() >= -50000){
      if(master.get_digital(DIGITAL_B)){
        armPID.target_set(armPID.target_get() - 6);
      }
      }

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
          ez::screen_print("x: " + util::to_string_with_precision(chassis.odom_x_get()) +
                               "\ny: " + util::to_string_with_precision(chassis.odom_y_get()) +
                               "\na: " + util::to_string_with_precision(chassis.odom_theta_get()) +
                               "\nmotor temp left" + util::to_string_with_precision(chassis.left_motors[0].get_temperature()) + util::to_string_with_precision(chassis.left_motors[1].get_temperature()) +util::to_string_with_precision(chassis.left_motors[2].get_temperature()) +
                               "\nmotor temp right" + util::to_string_with_precision(chassis.right_motors[0].get_temperature()) + util::to_string_with_precision(chassis.right_motors[1].get_temperature()) + util::to_string_with_precision(chassis.right_motors[2].get_temperature())+
                               "\n temp intake" + util::to_string_with_precision(intake2.get_temperature()),
                           1);  // Don't override the top Page line

    } 


    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X)){
        chassis.pid_tuner_toggle();

      }
      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(MOTOR_BRAKE_HOLD);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }

      



    


    
  

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
  }
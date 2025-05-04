#include "main.h"
#include "subsystems.hpp"
 
 inline ez::PID armPID{0.45, 0, 0, 0, "armp"};

static bool armPIDactive = true;
 
inline void set_lift(int input) {
  if(armPIDactive){
  l_arm.move(input);
  r_arm.move(input);
  }
}

    

 inline void armtask(){

    pros::delay(2000);  // Set EZ-Template calibrate before this function starts running
   while (true) {

    if (armPIDactive) {
      set_lift(armPID.compute(l_arm.get_position()));
    }

      pros::delay(ez::util::DELAY_TIME);
    }

}
 inline   pros::Task armpidtask(armtask);

#include "main.h"
#include "subsystems.hpp"

 inline ez::PID armPID{0.45, 0, 0, 0, "armp"};

 inline void armtask(){

    pros::delay(2000);  // Set EZ-Template calibrate before this function starts running
   while (true) {
      set_lift(armPID.compute(l_arm.get_position()));

      pros::delay(ez::util::DELAY_TIME);
    }

}


inline void set_lift(int input) {
  l_arm.move(input);
  r_arm.move(input);
}





 inline pros::Task Aarmtask(armtask);




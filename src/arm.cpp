#include "main.h"
#include "subsystems.hpp"

 inline ez::PID armPID{0.1, 0.004, 4, 100, "armp"};
 inline void armtask(){

    
    while (true) {
        //arm.move(armPID.compute(rotation_sensor.get_angle()));


        

        l_arm.move(armPID.compute(l_arm.get_position()));
        r_arm.move(armPID.compute(l_arm.get_position()));


        pros::delay(20);
        
  } 
}




 inline pros::Task Aarmtask(armtask);




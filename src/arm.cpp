#include "main.h"
#include "subsystems.hpp"

inline ez::PID armPID{0.45, 0.003, 4, 100, "armp"};

inline void armtask(){
    while (true) {
        //arm.move(armPID.compute(rotation_sensor.get_angle()));


        pros::delay(20);
        
  } 
}

inline pros::Task Armtask(armtask);




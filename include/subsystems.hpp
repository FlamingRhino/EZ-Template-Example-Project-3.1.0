#pragma once

#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples

ez::Piston Piston11('A');
ez::Piston Piston22('B');
//{port1,port2} put a - to revese 
pros::MotorGroup intake2({7,-17});



// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
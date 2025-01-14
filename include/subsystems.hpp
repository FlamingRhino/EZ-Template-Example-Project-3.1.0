#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples

//ez::Piston Piston11('A');
//ez::Piston Piston22('B');
//{port1,port2} put a - to revese 
//pros::MotorGroup intake2({7,-17});


  inline pros::Rotation rotation_sensor(15);

  inline ez::Piston Piston11('A');
  inline ez::Piston Piston22('B');
  inline ez::Piston Sorter('H');

  //{port1,port2} put a - to revese 
  //INLINE
  inline pros::Motor intake2(7);
  inline pros::Motor l_arm(8);
  inline pros::Motor r_arm(-3);

  inline pros::Optical Color(21);


// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples

//ez::Piston Piston11('A');
//ez::Piston Piston22('B');
//{port1,port2} put a - to revese 
//pros::MotorGroup intake2({7,-17});


  inline pros::Rotation rotation_sensor(15);

  inline ez::Piston Piston11('E',true);
  inline ez::Piston Piston22('F');
  inline ez::Piston Piston737('G');
  inline ez::Piston Sorter('H');
  inline ez::Piston PistonB29('D');

  //NICK IF YOU SEE THIS IT WORKS :) o(*￣▽￣*)ブ

  //{port1,port2} put a - to revese 
  //INLINE
  inline pros::MotorGroup intake2({10});
  inline pros::Motor r_arm(4);
  inline pros::Motor l_arm(-18);

  inline pros::Optical Color(11);





// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
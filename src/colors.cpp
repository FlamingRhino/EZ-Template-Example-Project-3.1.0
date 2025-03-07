#include "main.h"
#include "pros/misc.h"
#include "subsystems.hpp"
inline bool colordisable = false;



      
inline void colortask(){

  bool onred = false;
  int count = 0;
  bool ison = true;
  int onoff = 0;
  master.print(1, 0, "on RED");
  master.print(1, 10, "ON  ");
    while (true) {
      
    if(master.get_digital_new_press(DIGITAL_UP)){
      if(onred == true){
        onred = false;
        master.print(1, 0, "on RED");
      }else{
        onred = true;
        master.print(1, 0, "on BLUE");
      }
    }
    

    if(master.get_digital_new_press(DIGITAL_DOWN)){
      if(ison){
        ison = false;
        master.print(1, 10, "OFF  ");
      }else{
        ison = true;
        master.print(1, 10, "ON  ");
      }
    }
      if(intake2.get_actual_velocity() > 2){
      if(ison == true){
      if(onred == true){
       if ((Color.get_hue() <= 345 && Color.get_hue() >= 361 && Color.get_proximity() > 230)   or  (Color.get_hue() <= 15 && Color.get_hue() >= 0 && Color.get_proximity() > 230)){
          Sorter.set(true);
         pros::delay(500);
         Sorter.set(false);
        }

      }else{


       if (Color.get_hue() <= 235 && Color.get_hue() >= 200 && Color.get_proximity() > 230){
          Sorter.set(true);
         pros::delay(500);
          Sorter.set(false);
          master.print(1, 0, "on RED");
         }


      }
      }

     if (!(count % 6)) {
       //Only print every 50ms, the controller text update rate is slow
       if(onoff == 0){
        if(onred){
          master.print(1, 0, "on BLUE");
        }else{
          master.print(1, 0, "on RED ");
        }

        onoff = 1;
       }else{
          if(ison){
          master.print(1, 10, "ON  ");
        }else{
          master.print(1, 10, "OFF");
        }
          onoff = 0;

       }
      

    }
    //count++;



      }




        pros::delay(20);

  } 

  master.print(1, 0, "on red? =AAAAAA: %f");
}









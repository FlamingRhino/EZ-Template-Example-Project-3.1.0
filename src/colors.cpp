#include "main.h"
#include "subsystems.hpp"



      
inline void colortask(){

  bool onred = false;
  int count = 0;
  bool ison = true;
  int onoff = 0;
    while (true) {

      if(ison == true){
      if(onred == true){
       if (Color.get_hue() >= 0 and Color.get_hue() <= 5){
          Sorter.set(true);
         pros::delay(500);
         Sorter.set(false);
        }

      }else{


       if (Color.get_hue() <= 230 && Color.get_hue() >= 150 && Color.get_proximity() > 215){
          Sorter.set(true);
         pros::delay(500);
          Sorter.set(false);
          master.print(1, 0, "on RED");
         }


      }
      }

      if(master.get_digital_new_press(DIGITAL_LEFT)){
        if(onred == true){
          onred = false;
          master.print(1, 0, "on RED");
        }else{
          onred = true;
          master.print(1, 0, "on BLUE");
        }
      }
      

      if(master.get_digital_new_press(DIGITAL_RIGHT)){
        if(ison){
          ison = false;
          master.print(1, 10, "OFF  ");
        }else{
          ison = true;
          master.print(1, 10, "ON  ");
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



    




        pros::delay(20);
        
  } 

  master.print(1, 0, "on red? =AAAAAA: %f");
}









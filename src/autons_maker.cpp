#include "constantsauton.cpp"



void mogorushfunnicktest(){

armPID.target_set(245);
// Position: -248, 269, Angle: 335�
//set angle (335)
intake2.move(127);
chassis.pid_drive_set(38_in, DRIVE_SPEED);
Piston22.set(true);
chassis.pid_wait_until(35_in);
Piston737.set(true);
chassis.pid_wait_quick_chain();


chassis.pid_drive_set(-38_in, DRIVE_SPEED);
chassis.pid_wait();

intake2.move(0);


Piston737.set(false);

armPID.target_set(500);

Piston22.set(false);

chassis.pid_turn_set( 15_deg, TURN_SPEED, shortest);
chassis.pid_wait();

chassis.pid_drive_set(4_in, DRIVE_SPEED);
chassis.pid_wait();

intake2.move(0);

armPID.target_set(2100);

pros::delay(500);
armPID.target_set(10);
pros::delay(200);
chassis.pid_turn_set(75, 60, shortest);
pros::delay(200);
armPID.target_set(10);
chassis.pid_wait_quick_chain();


chassis.pid_turn_set(110, 60, shortest);
chassis.pid_wait_quick_chain();

chassis.pid_turn_set(140, 70, shortest);
chassis.pid_wait_quick();

chassis.pid_drive_set(-38_in, DRIVE_SPEED);
chassis.pid_wait();

chassis.pid_drive_set(-4_in, 50);
chassis.pid_wait();

Piston11.set(true);


pros::delay(200);


chassis.pid_turn_set(155, TURN_SPEED, shortest);
chassis.pid_wait();

chassis.pid_drive_set(60_in, 110);

intake2.move(127);

chassis.pid_wait_until(30_in);
chassis.pid_speed_max_set(30);

chassis.pid_wait();

pros::delay(350);


chassis.pid_drive_set(-15_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(15_in, 40);
chassis.pid_wait();

chassis.pid_drive_set(-15_in, DRIVE_SPEED);
chassis.pid_wait();




}//end



    void testawp(){
// Position: -293, 70, Angle: 255�
//set angle (255)
//set zero (111)
int i = 0;

armPID.target_set(1360);
while (i < 400){
//arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
//arm.move(armPID.compute(arm.get_position()));

chassis.pid_turn_set(-45_deg, TURN_SPEED);

i = 0;
armPID.target_set(10);
while (i < 300){
// arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
//arm.move(armPID.compute(arm.get_position()));

chassis.pid_wait();

chassis.pid_drive_set(-30_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-10_in, 80);
chassis.pid_wait();

Piston11.set(true);
pros::delay(100);

chassis.pid_turn_set( -20_deg, TURN_SPEED);
chassis.pid_wait();

intake2.move(127);

chassis.pid_drive_set(30_in, 80);

i = 0;
armPID.target_set(1360);

while (i < 300){
//arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}
// arm.move(armPID.compute(arm.get_position()));

chassis.pid_wait();

pros::delay(500);

chassis.pid_drive_set(-30_in, DRIVE_SPEED);
chassis.pid_wait();

i = 0;
armPID.target_set(10);

while (i < 300){
// arm.move(armPID.compute(arm.get_position()));
pros::delay(2);
i++;
}

chassis.pid_turn_set(-150_deg, 50,  shortest);
chassis.pid_wait();

chassis.pid_drive_set(28_in, DRIVE_SPEED);
chassis.pid_wait();


chassis.pid_drive_set(-20_in, DRIVE_SPEED);
chassis.pid_wait();

chassis.pid_turn_set( 20_deg, TURN_SPEED);
chassis.pid_wait();

intake2.move(0);

chassis.pid_drive_set(15_in, DRIVE_SPEED);
chassis.pid_wait_quick_chain();

chassis.pid_drive_set(15_in, 60);
chassis.pid_wait();





}//end
    void testsave(){
// Position: 204, -25, Angle: 64�
// the angle to ofset set zero (64)
armPID.target_set(1850);

chassis.pid_turn_set(24_deg, 90);
chassis.pid_wait();

chassis.pid_turn_set(24_deg, 90);
chassis.pid_wait();

chassis.pid_turn_set(260_deg, 90);
chassis.pid_wait();

intake2.move(127);

chassis.pid_drive_set(-23_in, 110);
chassis.pid_wait();

chassis.pid_drive_set(12_in, 110);
chassis.pid_wait();

}//end
void testthinge(){
// Position: -255, 113, Angle: 182�
chassis.pid_turn_set(182_deg, 90);
chassis.pid_wait();

Piston11.set(true);
chassis.pid_turn_set(88_deg, 90);
chassis.pid_wait();

chassis.pid_drive_set(-19_in, 110);
chassis.pid_wait();

chassis.pid_drive_set(28_in, 110);
chassis.pid_wait();

}//end

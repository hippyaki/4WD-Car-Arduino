
#include <MotorL298NRobotCar.h>

Motors myMotors;

void setup() {
  
 /* Motor digital pins are hardcoded in the library, for your reference pins connections is the next:
    Motor 1: enA = 5, in1 = 2, in2 = 8
    Motor 2: enB = 3, in3 = 11, in4 = 10 */
  
 myMotors.attach();
}
int speed = 0; 
void loop() {
  
 /* How program runs:
    Motors are rotating forward during 5 seconds on maximum possible speed 255
    Motors are rotating backward during 5 seconds on maximum possible speed --255 */
  
 for (speed; speed < 255; speed++)
 {
   myMotors.write(speed, speed); 
   delay(15); 
 }
 delay(5000);
 for (speed; speed > -255; speed--)
 {
   myMotors.write(speed, speed); 
   delay(15);
 }
 delay(5000); 
}

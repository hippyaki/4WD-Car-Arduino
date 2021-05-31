/* Program for the robot RoboRover M1 test motors forward backward
  If motors are rotating wrong swipe wires connected to the L298N motordriver
*/
//Include all necessary libraries to control motoriver L298N
#include <MotorL298NRobotCar.h>
//Create class instances for the motordriver L298N
Motors myMotors;
//Setup all class instances and attach them to the necessary ports
void setup() {
 /* Motor digital pins are hardcoded in the library, for your reference pins connections is the next:
    Motor 1: enA = 5, in1 = 2, in2 = 8
    Motor 2: enB = 3, in3 = 11, in4 = 10 */
 myMotors.attach();
}
int speed = 0; //variable to make accleration smoothly
void loop() {
 /* How program runs:
    Motors are rotating forward during 5 seconds on maximum possible speed 255
    Motors are rotating backward during 5 seconds on maximum possible speed --255 */
 for (speed; speed < 255; speed++)
 {
   myMotors.write(speed, speed); // Rotate motors forward and gain speed smoothly using for
   delay(15); // delay to make accleration smoothly
 }
 delay(5000); //delay 5 seconds
 for (speed; speed > -255; speed--)
 {
   myMotors.write(speed, speed); // Rotate motors forward and gain speed smoothly using for
   delay(15); // delay to make accleration smoothly
 }
 delay(5000); //delay 5 seconds
}

#include <LineSensorRobotCar.h>
#include <MotorL298NRobotCar.h>
//Create class instances for the line sensors and motordriver
LineSensor myLineSensorA3;
LineSensor myLineSensorA4;
LineSensor myLineSensorA5;
Motors myMotors;
//Setup all class instances and attach them to the necessary ports
void setup() {
 //Serial port attach on the speed 9600
 Serial.begin(9600);
 //You can choose pins from A0 to A5 for the Arduino Uno and add more sensors
 myLineSensorA3.attach(A3);
 myLineSensorA4.attach(A4);
 myLineSensorA5.attach(A5);
 /* Motor digital pins are hardcoded in the library, for your reference pins connections is the next:
   Motor 1: enA = 5, in1 = 2, in2 = 8
   Motor 2: enB = 3, in3 = 11, in4 = 10 */
myMotors.attach();
}
void loop() {
 /* How program runs:
    If value from the center sensor (A4) is 0,
    it means black line, robot is going forward.
    Else, if value from the left sensor (A3) is 0 (black line detected),
    while center sensor is on white surface, robot turns left.
    Else, if value from the right sensor (A5) is 0 (black line detected),
    while center sensor is on white surface, robot turns right. */
 if (myLineSensorA4.read() == 0) {
   myMotors.write(120, 120); //Robot is going forward
 } else {
   if (myLineSensorA3.read() == 0) {
     while (myLineSensorA4.read() == 1) {
       myMotors.write(-180, 180);  //Robot turns left
     }
   } else {
     if (myLineSensorA5.read() == 0) {
       while (myLineSensorA4.read() == 1) {
         myMotors.write(180, -180); //Robot turns right
       }
     }
   }
 }
}

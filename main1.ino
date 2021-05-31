#include <SharpA21RobotCar.h>
#include <MotorL298NRobotCar.h>
//Create class instances for the Sharp distance sensors and motordriver L298N
Sharp mySharpA0;
Sharp mySharpA1;
Motors myMotors;
//Setup all class instances and attach them to the necessary ports
void setup() {
Serial.begin(9600);
//You can choose pins from A0 to A5 for the Arduino Uno and add more distance sensors
mySharpA0.attach(A0);
mySharpA1.attach(A1);
/* Motor digital pins are hardcoded in the library, for your reference pins connections is the next:
   Motor 1: enA = 5, in1 = 2, in2 = 8
   Motor 2: enB = 3, in3 = 11, in4 = 10 */
myMotors.attach();
}
void loop() {
/* How program runs:
   If distance from the left sensor less than 60cm (true)
   or distance from the right sensor less than 60cm (true), 
   we are going to the next enclosured "if" conditional statement.
   If distance from both sensors is less than 35cm (true), robot is going backward.
   Else we are going to the next enclosured "if" conditional statement.
   If distance from the left sensor is less or equal to the distance from the right sensor, 
   robot turns to the right.
   If distance from the left sensor is bigger than right sensor, robot turns left.
   If distance from the both sensors more than 60cm, robot is running straight forward. */
if (mySharpA0.read() <= 60 || mySharpA1.read() <= 60) {
  if (mySharpA0.read() <= 35 && mySharpA1.read() <= 35) {
    //Robot is going backward myMotors.write(LEFT MOTOR, RIGHT MOTOR)
    myMotors.write(-220, -220); 
  } else {
    if (mySharpA0.read() <= mySharpA1.read()) {
      myMotors.write(255, -100); //Robot turns right
    }
    if (mySharpA0.read() > mySharpA1.read()) {
      myMotors.write(-100, 255); //Robot turns left
    }
  }
} else {
  myMotors.write(220, 220); //Robot is running straight forward
}

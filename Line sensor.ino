#include <LineSensorRobotCar.h>
//Create class instances for the line sensors
LineSensor myLineSensorA3;
LineSensor myLineSensorA4;
LineSensor myLineSensorA5;
//Setup all class instances and attach them to the necessary ports
void setup() {
 //Serial port attach on the speed 9600
 Serial.begin(9600);
 //You can choose pins from A0 to A5 for the Arduino Uno and add more sensors
 myLineSensorA3.attach(A3);
 myLineSensorA4.attach(A4);
 myLineSensorA5.attach(A5);
}
void loop() {
 Serial.print("Line sensor left: ");
 Serial.println(myLineSensorA3.read());
 Serial.print("Line sensor center: ");
 Serial.println(myLineSensorA4.read());
 Serial.print("Line sensor right: ");
 Serial.println(myLineSensorA5.read());
 Serial.println("");
 delay(500);
}

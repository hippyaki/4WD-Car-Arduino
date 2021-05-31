#include <SharpA21RobotCar.h>
//Create class instances for the Sharp distance sensors
Sharp mySharpA0;
Sharp mySharpA1;
//Setup all class instances and attach them to the necessary ports
void setup() {
 //Serial port attach on the speed 9600
 Serial.begin(9600);
 //You can choose pins from A0 to A5 for the Arduino Uno and add more distance sensors
 mySharpA0.attach(A0);
 mySharpA1.attach(A1);
}
void loop() {
 Serial.print("Infrared sensor left: ");
 Serial.println(mySharpA0.read());
 Serial.print("Infrared sensor right: ");
 Serial.println(mySharpA1.read());
 Serial.println("");
 delay(500);

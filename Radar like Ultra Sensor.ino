#include <HCSR04RobotCar.h>
#include <ServoRobotCar.h>
//Create class instance for the ultrasonic distance sensor
Ultrasonic myUltrasonic;
//Create class instance for the servo
ServoMotor myServo;
//Setup all class instances and attach them to the necessary ports
void setup() {
 //Serial port attach on the speed 9600
 Serial.begin(9600);
 //Attach sensor and servo
 //Pins for the ultrasonic sensor and servo are hardcoded in the library
 myUltrasonic.attach();
 myServo.attach();
 //Set servo in the middle position
 myServo.write(90);
 //Wait 2 seconds before program starts
 delay(2000);
}
void loop() {
 myServo.write(90); //Set servo in the middle position
 Serial.print("Distance center ");
 Serial.println(myUltrasonic.read());
 delay(1000); //Wait 1 second
 myServo.write(130);  //Turn servo left
 Serial.print("Distance left ");
 Serial.println(myUltrasonic.read());
 delay(1000); //Wait 1 second
 myServo.write(50); //Turn servo right
 Serial.print("Distance right ");
 Serial.println(myUltrasonic.read());
 delay(1000); //Wait 1 second
}

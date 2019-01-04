/* ---------------------------------------------------------------------------
* Example of an arcade drive robot being controlled by the GO BLE app
* using both the RomeoJoystick and RomeoMotor Libraries.
* 
* Author: Mr. Joel Andrew Bianchi
* Date: 1/4/2019
* ---------------------------------------------------------------------------
*/

#include <RomeoMotor.h>
#include <RomeoJoystick.h>

RomeoMotor rightMotor(1);
RomeoMotor leftMotor(2);
RomeoJoystick myPhone(GOBLE);

void setup() {
  Serial.begin(115200);  //initialize the Serial monitor
  myPhone.printJoy(true); //print out Joystick values to serial monitor
  //rightMotor.flip(true);  //does your robot need this?
}

void loop() {
  
  //Get values from the axes on your phone
  int fwd = myPhone.axis(LY);
  int turn = myPhone.axis(LX);
  
  //ARCADE-STYLE DRIVING
  rightMotor.move(fwd + turn);
  leftMotor.move(fwd - turn);
  
}

/* ---------------------------------------------------------------------------
* Example of an arcade drive robot being controlled by the GO BLE app
* using both the RomeoJoystick and RomeoMotor Libraries.
* The Joystick class is constructed separately.
* 
* Author: Mr. Joel Andrew Bianchi
* Date: 1/4/2019
* ---------------------------------------------------------------------------
*/

#include <RomeoDrive.h>
#include <RomeoJoystick.h>

RomeoDrive myDrive;
RomeoJoystick myPhone(GOBLE);

void setup() {
  Serial.begin(115200);
  myPhone.printJoy(true); //print out Joystick values to serial monitor
}

void loop() {
 
  int turn = myPhone.axis(LX);
  int fwd = myPhone.axis(LY);

  myDrive.arcade(fwd, turn);
  
}

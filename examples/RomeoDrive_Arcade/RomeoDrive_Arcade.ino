/* ---------------------------------------------------------------------------
* Example of an arcade drive robot being controlled by the GO BLE app
* using both the RomeoJoystick and RomeoMotor Libraries.
* 
* Author: Mr. Joel Andrew Bianchi
* Date: 12/26/2018
* ---------------------------------------------------------------------------
*/

#include <RomeoDrive.h>

RomeoDrive myDrive(GOBLE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  myDrive.arcade();
  
}

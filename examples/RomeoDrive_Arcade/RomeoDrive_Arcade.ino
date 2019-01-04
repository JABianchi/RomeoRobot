/* ---------------------------------------------------------------------------
* Example of an arcade drive robot being controlled by the GO BLE app
* using both the RomeoJoystick and RomeoMotor Libraries.
* 
* Author: Mr. Joel Andrew Bianchi
* Date: 1/4/2019
* ---------------------------------------------------------------------------
*/

//#include <RomeoDrive.h>
#include "RomeoDrive.h"

RomeoDrive myDrive(GOBLE);

void setup() {
  Serial.begin(115200);
}

void loop() {

  myDrive.arcade();
  
}

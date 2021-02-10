/* ---------------------------------------------------------------------------
* Example of an arcade drive robot being controlled by the GO BLE app
* using both the RomeoJoystick and RomeoMotor Libraries.
* The Joystick class is constructed separately.
* 
* Author: Mr. Joel Andrew Bianchi
* Date: 2/10/2021
* ---------------------------------------------------------------------------
*/

#include "RomeoMotor.h"
#include "RomeoJoystick.h"

RomeoMotor rightMotor(1);
RomeoMotor leftMotor(2);
RomeoJoystick myPhone(GOBLE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  int x = myPhone.axis(LX); //can also use RX
  int y = myPhone.axis(LY); //can also use RY

  //ARCADE-STYLE DRIVING
  rightMotor.move(y+x);
  leftMotor.move(y-x);
  
}

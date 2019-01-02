/* ---------------------------------------------------------------------------
* Example of an arcade drive robot being controlled by the GO BLE app
* using both the RomeoJoystick and RomeoMotor Libraries.
* 
* Author: Mr. Joel Andrew Bianchi
* Date: 12/24/2018
* ---------------------------------------------------------------------------
*/

#include <RomeoMotor.h>
#include <RomeoJoystick.h>

RomeoMotor rightMotor(1);
RomeoMotor leftMotor(2);
RomeoJoystick myPhone(GOBLE);

void setup() {
  Serial.begin(115200);  //initial the Serial
  myPhone.printJoy(true); //print out Joystick values to serial monitor
}

void loop() {
  
  //Get values of x-axis & y-axis from phone
  int leftX = myPhone.axis(LX);
  int leftY = myPhone.axis(LY);

  //ARCADE-STYLE DRIVING
  rightMotor.move(leftY + leftX);
  leftMotor.move(leftY - leftX);
  
}

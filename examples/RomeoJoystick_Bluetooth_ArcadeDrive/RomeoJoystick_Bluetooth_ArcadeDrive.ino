/* ---------------------------------------------------------------------------
* Example of an arcade drive robot being controlled by the GO BLE app
* using both the RomeoJoystick and RomeoMotor Libraries.
* 
* Author: Mr. Joel Bianchi
* Date: 12/24/2018
* ---------------------------------------------------------------------------
*/

#include <RomeoMotor.h>
#include <RomeoJoystick.h>

RomeoMotor rightMotor(1);
RomeoMotor leftMotor(2);
RomeoJoystick myPhone(IPHONE);

void setup() {
  Serial.begin(115200);  //initial the Serial
  myPhone.printJoy(true); //print out Joystick values to serial monitor
}

void loop() {
  
  //Get values of x-axis & y-axis from phone
  int x = myPhone.axis(X);
  int y = myPhone.axis(Y);

  //ARCADE-STYLE DRIVING
  rightMotor.move(y+x);
  leftMotor.move(y-x);
  
}

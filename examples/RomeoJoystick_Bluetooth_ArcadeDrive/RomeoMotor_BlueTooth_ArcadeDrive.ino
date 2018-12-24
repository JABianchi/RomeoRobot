#include "RomeoMotor.h"
#include "RomeoJoystick.h"

RomeoMotor rightMotor(1);
RomeoMotor leftMotor(2);
RomeoJoystick myPhone(IPHONE);

void setup() {
  Serial.begin(115200);  //initial the Serial
}

void loop() {
  
  int x = myPhone.axis(X);
  int y = myPhone.axis(Y);

  //ARCADE-STYLE DRIVING
  rightMotor.move(y+x);
  leftMotor.move(y-x);
  
}

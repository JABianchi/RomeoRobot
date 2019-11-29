/* ---------------------------------------------------------------------------
* Example of a Servobot that drives forward.
* 
* Author: Mr. Joel Andrew Bianchi
* Date: 11/29/2019
* ---------------------------------------------------------------------------
*/

#include "RomeoServobot.h"

RomeoServobot bot(9,10);

void setup(){  
  Serial.begin(9600);
}

void loop() {

  //go forward
  bot.goForward();
  Serial.println("Forward");
  delay(2000);

  //go back
  bot.goBack();
  Serial.println("Back");
  delay(2000);

  //disable the motors
  bot.off();
  Serial.println("Stop");
  delay(2000);
}


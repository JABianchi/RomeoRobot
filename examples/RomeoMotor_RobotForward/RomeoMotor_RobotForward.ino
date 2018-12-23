/* ---------------------------------------------------------------------------
* Example of a tank drive robot using the RomeoMotor Library.
* 
* Author: Mr. Joel Bianchi
* Date: 12/3/2018
* ---------------------------------------------------------------------------
*/

#include <RomeoMotor.h>

RomeoMotor right(1);
RomeoMotor left(2);

void setup(){  

  left.flip(true);   //make sure both sides make the robot move forward

}

void loop() {

  //go forward
  right.move(100);
  left.move(100);
  delay(2000);

  //go back
  right.move(-100);
  left.move(-100);
  delay(2000);

  //disable the motors
  right.shutDown();
  left.shutDown();
  
}


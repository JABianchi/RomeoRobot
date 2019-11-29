/*
  RomeoServobot.cpp - Library for using RomeoBLE with 2 Servo motors.
  Created by Mr. Joel Andrew Bianchi, November 29, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
//#include "Servo.h"
#include <Servo.h>


//default constructor assigns pins 9 & 10 to be used by the Servo bot
RomeoServobot::RomeoServobot() :
  _rightServoMotor,
  _leftServoMotor
{
  rPin = 9;
  lPin = 10;
  _rightServomotor.attach(rPin);
  _leftServomotor.attach(lPin);

  _centerSpeed = 95;
  _maxSpeed = 180;
  _minSpeed = 0;

}

//alternate constructor allows the user to manually assign the pins used for the bot
//*Note that only pins 3,5,6,9,10,11 are allowable servo motor pins
RomeoServobot::RomeoServobot(int rightServomotorPin, int leftServomotorPin) :
  _rightServoMotor,
  _leftServoMotor
{
  rPin = rightServomotorPin;
  lPin = leftServomotorPin;
  _rightServomotor.attach(rPin);
  _leftServomotor.attach(lPin);

  _centerSpeed = 95;
  _fwdSpeed = 180;
  _backSpeed = 0;

}


//function to make the servobot move forward
void RomeoServobot::goForward()
{
  _rightServomotor.write(backSpeed);
  _leftServomotor.write(fwdSpeed);
}

//function to make the servobot move backwards
void RomeoServobot::goBack()
{
  _rightServomotor.write(fwdSpeed);
  _leftServomotor.write(backSpeed);
}

//function to make the servobot turn to the right
void RomeoServobot::turnRight()
{
  _rightServomotor.write(fwdSpeed);
  _leftServomotor.write(fwdSpeed);
}

//function to make the servobot turn to the left
void RomeoServobot::turnLeft()
{
  _rightServomotor.write(backSpeed);
  _leftServomotor.write(backSpeed);
}

//function to make the servobot swing turn to the right
void RomeoServobot::swingTurnRight()
{
  _rightServomotor.write(centerSpeed);
  _leftServomotor.write(fwdSpeed);
}

//function to make the servobot swing turn to the left
void RomeoServobot::swingTurnLeft()
{
  _rightServomotor.write(backSpeed);
  _leftServomotor.write(centerSpeed);
}

//function to make the servobot stop! (using detach)
void RomeoServobot::off()
{
  _rightServomotor.detach();
  _leftServomotor.detach();
  delay(50);
  _rightServomotor.attach(rPin);
  _leftServomotor.attach(lPin);

}

//function to convert a -100 to 100 range of values to the Servo range of 0 to 180
int RomeoServobot::speed(int input){

  int thresh = 10;

  if(input > 0){
    return constrain(map(input,0,100,centerSpeed,fwdSpeed),centerSpeed+thresh,fwdSpeed);
  } else if (input < 0){
    return constrain(map(input,-100,0,backSpeed,centerSpeed),backSpeed-thresh,centerSpeed);
  } else {
    return centerSpeed;
  }

}



}
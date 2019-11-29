/*
  RomeoServobot.cpp - Library for using RomeoBLE with 2 Servo motors.
  Created by Mr. Joel Andrew Bianchi, November 29, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
//#include "Servo.h"
#include <Servo.h>
#include "RomeoServobot.h"


//default constructor assigns pins 9 & 10 to be used by the Servo bot
RomeoServobot::RomeoServobot()
  :_rightServomotor(), _leftServomotor()
{
  _rPin = 9;
  _lPin = 10;
  _rightServomotor->attach(_rPin);
  _leftServomotor->attach(_lPin);

  _centerSpeed = 95;
  _fwdSpeed = 180;
  _backSpeed = 0;

}

//alternate constructor allows the user to manually assign the pins used for the bot
//*Note that only pins 3,5,6,9,10,11 are allowable servo motor pins
RomeoServobot::RomeoServobot(int rightServomotorPin, int leftServomotorPin)
 : _rightServomotor(), _leftServomotor()
{
  _rPin = rightServomotorPin;
  _lPin = leftServomotorPin;
  _rightServomotor->attach(rightServomotorPin);
  _leftServomotor->attach(leftServomotorPin);

  _centerSpeed = 95;
  _fwdSpeed = 180;
  _backSpeed = 0;

}


//function to make the servobot move forward
void RomeoServobot::goForward()
{
  _rightServomotor->write(_backSpeed);
  _leftServomotor->write(_fwdSpeed);
}

//function to make the servobot move backwards
void RomeoServobot::goBack()
{
  _rightServomotor->write(_fwdSpeed);
  _leftServomotor->write(_backSpeed);
}

//function to make the servobot turn to the right
void RomeoServobot::turnRight()
{
  _rightServomotor->write(_fwdSpeed);
  _leftServomotor->write(_fwdSpeed);
}

//function to make the servobot turn to the left
void RomeoServobot::turnLeft()
{
  _rightServomotor->write(_backSpeed);
  _leftServomotor->write(_backSpeed);
}

//function to make the servobot swing turn to the right
void RomeoServobot::swingTurnRight()
{
  _rightServomotor->write(_centerSpeed);
  _leftServomotor->write(_fwdSpeed);
}

//function to make the servobot swing turn to the left
void RomeoServobot::swingTurnLeft()
{
  _rightServomotor->write(_backSpeed);
  _leftServomotor->write(_centerSpeed);
}

//function to make the servobot stop! (using detach)
void RomeoServobot::off()
{
  _rightServomotor->detach();
  _leftServomotor->detach();
  delay(50);
  _rightServomotor->attach(_rPin);
  _leftServomotor->attach(_lPin);

}

//function to convert a -100 to 100 range of values to the Servo range of 0 to 180
int RomeoServobot::speed(int input){

  int thresh = 10;

  if(input > 0){
    return constrain(map(input,0,100,_centerSpeed,_fwdSpeed),_centerSpeed+thresh,_fwdSpeed);
  } else if (input < 0){
    return constrain(map(input,-100,0,_backSpeed,_centerSpeed),_backSpeed-thresh,_centerSpeed);
  } else {
    return _centerSpeed;
  }

}

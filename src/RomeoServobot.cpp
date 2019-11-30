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
  _rightServomotor.attach(_rPin);
  _leftServomotor.attach(_lPin);

  _centerSpeed = 1519; //microseconds
  _fwdSpeed = 2000;
  _backSpeed = 1000;

}

//alternate constructor allows the user to manually assign the pins used for the bot
//*Note that only pins 3,5,6,9,10,11 are allowable servo motor pins
RomeoServobot::RomeoServobot(int rightServomotorPin, int leftServomotorPin)
 : _rightServomotor(), _leftServomotor()
{
  _rPin = rightServomotorPin;
  _lPin = leftServomotorPin;
  _rightServomotor.attach(rightServomotorPin);
  _leftServomotor.attach(leftServomotorPin);

  _centerSpeed = 1519;
  _fwdSpeed = 2000;
  _backSpeed = 1000;

}


//function to make the servobot move forward
void RomeoServobot::goForward()
{
  _rightServomotor.writeMicroseconds(_backSpeed);
  _leftServomotor.writeMicroseconds(_fwdSpeed);
}

//function to make the servobot move forward at a certain speed
void RomeoServobot::goForward(int newSpeed)
{
  _rightServomotor.writeMicroseconds(microSpeed(-newSpeed));
  _leftServomotor.writeMicroseconds(microSpeed(newSpeed));
}

//function to make the servobot move backwards
void RomeoServobot::goBack()
{
  _rightServomotor.writeMicroseconds(_fwdSpeed);
  _leftServomotor.writeMicroseconds(_backSpeed);
}

//function to make the servobot move backwards at a certain speed
void RomeoServobot::goBack(int newSpeed)
{
  _rightServomotor.writeMicroseconds(microSpeed(newSpeed));
  _leftServomotor.writeMicroseconds(microSpeed(-newSpeed));
}

//function to make the servobot turn to the right
void RomeoServobot::turnRight()
{
  _rightServomotor.writeMicroseconds(_fwdSpeed);
  _leftServomotor.writeMicroseconds(_fwdSpeed);
}

//function to make the servobot turn to the left
void RomeoServobot::turnLeft()
{
  _rightServomotor.writeMicroseconds(_backSpeed);
  _leftServomotor.writeMicroseconds(_backSpeed);
}

//function to make the servobot swing turn to the right
void RomeoServobot::swingTurnRight()
{
  _rightServomotor.writeMicroseconds(_centerSpeed);
  _leftServomotor.writeMicroseconds(_fwdSpeed);
}

//function to make the servobot swing turn to the left
void RomeoServobot::swingTurnLeft()
{
  _rightServomotor.writeMicroseconds(_backSpeed);
  _leftServomotor.writeMicroseconds(_centerSpeed);
}

//function to make the servobot stop! (using detach)
void RomeoServobot::off()
{
  _rightServomotor.writeMicroseconds(_centerSpeed);
  _leftServomotor.writeMicroseconds(_centerSpeed);
  _rightServomotor.detach();
  _leftServomotor.detach();
  delay(50);
  _rightServomotor.attach(_rPin);
  _leftServomotor.attach(_lPin);

}

//function to adjust the non-moving speed of the servo motors
void RomeoServobot::setOffSpeed(int newOffSpeed){
  _centerSpeed = newOffSpeed;
}

//function to convert an input value to a microseconds speed for a Servo:
//input = should be a value between -100 and 100
//return = a value between 1000 and 2000
int RomeoServobot::microSpeed(int input){

  int thresh = 100;

  if(input > 0){
    return constrain(map(input,0,100,_centerSpeed,_fwdSpeed),_centerSpeed+thresh,_fwdSpeed);
  } else if (input < 0){
    return constrain(map(input,-100,0,_backSpeed,_centerSpeed),_backSpeed,_centerSpeed-thresh);
  } else {
    return _centerSpeed;
  }

}




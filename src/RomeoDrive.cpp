/*
  RomeoDrive.cpp - Library for using RomeoBLE.
  Created by Mr. Joel Andrew Bianchi, December 26, 2018.
  Released into the public domain.
*/

#include "RomeoDrive.h"
#include "RomeoMotor.h"
#include "RomeoJoystick.h"


RomeoDrive::RomeoDrive(AppType appName)
{
  _rightMotor = new RomeoMotor(1);
  _leftMotor = new RomeoMotor(2);
  _phone = new RomeoJoystick(appName);
  
}

RomeoDrive::RomeoDrive()
{
  _rightMotor = new RomeoMotor(1);
  _leftMotor = new RomeoMotor(2);  
  
}


void RomeoDrive::arcade(){
  
  int turnSpeed = _phone.axis(X);
  int moveSpeed = _phone.axis(Y);

  _rightMotor.move(moveSpeed - turnSpeed);
  _leftMotor.move(moveSpeed + turnSpeed);
  
}

void RomeoDrive::arcade(int moveSpeed, int turnSpeed){
  
  _rightMotor.move(moveSpeed - turnSpeed);
  _leftMotor.move(moveSpeed + turnSpeed);
  
}


void RomeoDrive::tank(){
  
  int moveRightSpeed = _phone.axis(Y);
  int moveLeftSpeed = _phone.axis(Y);   //new axis needs to be added when double joystick app is functional

  _rightMotor.move(moveRightSpeed);
  _leftMotor.move(moveLeftSpeed);
  
}

void RomeoDrive::tank(int moveRightSpeed, int moveLeftSpeed){

  _rightMotor.move(moveRightSpeed);
  _leftMotor.move(moveLeftSpeed);

}


void RomeoDrive::end(){

  _rightMotor.end();
  _leftMotor.end();

}


    
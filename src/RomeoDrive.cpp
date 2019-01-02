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
  RomeoMotor r = new RomeoMotor(1);
  RomeoMotor l = new RomeoMotor(2);
  RomeoJoystick j(appName);

  _rightMotor = &r;
  _leftMotor = &l;
  _phone = &j;
  
  _phone->printJoy(true, false);

}

RomeoDrive::RomeoDrive()
{
  RomeoMotor r = new RomeoMotor(1);
  RomeoMotor l = new RomeoMotor(2);

  _rightMotor = &r;
  _leftMotor = &l;

}


void RomeoDrive::arcade(){
  
  int turnSpeed = _phone->axis(LX);
  int moveSpeed = _phone->axis(LY);

  _rightMotor->move(moveSpeed - turnSpeed);
  _leftMotor->move(moveSpeed + turnSpeed);
  
}

void RomeoDrive::arcade(int moveSpeed, int turnSpeed){
  
  _rightMotor->move(moveSpeed - turnSpeed);
  _leftMotor->move(moveSpeed + turnSpeed);
  
}


void RomeoDrive::tank(){
  
  int moveRightSpeed = _phone->axis(LY);
  int moveLeftSpeed = _phone->axis(LY);   //new axis needs to be added when double joystick app is functional

  _rightMotor->move(moveRightSpeed);
  _leftMotor->move(moveLeftSpeed);
  
}

void RomeoDrive::tank(int moveRightSpeed, int moveLeftSpeed){

  _rightMotor->move(moveRightSpeed);
  _leftMotor->move(moveLeftSpeed);

}


void RomeoDrive::end(){

  _rightMotor->end();
  _leftMotor->end();

}


    
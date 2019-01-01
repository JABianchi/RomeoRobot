/*
  RomeoDrive.cpp - Library for using RomeoBLE.
  Created by Mr. Joel Andrew Bianchi, December 26, 2018.
  Released into the public domain.
*/

#include "RomeoDrive.h"
#include "RomeoMotor.h"
#include "RomeoJoystick.h"


RomeoDrive::RomeoDrive()
{
  RomeoMotor rightMotor(1);
  RomeoMotor leftMotor(2);

  _rightMotor = rightMotor;
  _leftMotor = leftMotor;
  
}

RomeoDrive::RomeoDrive(AppType appName)
{
  RomeoMotor rightMotor(1);
  RomeoMotor leftMotor(2);
  RomeoJoystick myPhone(appName);

  _rightMotor = rightMotor;
  _leftMotor = leftMotor;
  _myPhone = myPhone;
  
}


void RomeoDrive::arcade(){
  
  int turnSpeed = _myPhone.axis(X);
  int moveSpeed = _myPhone.axis(Y);

  _rightMotor.move(moveSpeed - turnSpeed);
  _leftMotor.move(moveSpeed + turnSpeed);
  
}

void RomeoDrive::arcade(int moveSpeed, int turnSpeed){
  
  _rightMotor.move(moveSpeed - turnSpeed);
  _leftMotor.move(moveSpeed + turnSpeed);
  
}

void RomeoDrive::tank(){
  
  int moveRightSpeed = _myPhone.axis(Y);
  int moveLeftSpeed = _myPhone.axis(Y);   //new axis needs to be added when double joystick app is functional

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


    
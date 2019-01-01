/*
  RomeoDrive.h - Library for using RomeoBLE.
  Created by Mr. Joel Andrew Bianchi, December 26, 2018.
  Released into the public domain.
*/

#ifndef RomeoDrive_h
#define RomeoDrive_h

#include "Arduino.h"
#include "RomeoMotor.h"
#include "RomeoJoystick.h"


class RomeoDrive
{
  public:
   // RomeoDrive;
    RomeoDrive(AppType appName);
    void arcade();
    void arcade(int moveSpeed, int turnSpeed);
    void tank();
    void tank(int moveRightSpeed, int moveLeftSpeed);
    void end();

  private:
    RomeoMotor _rightMotor(1);
    RomeoMotor _leftMotor(2);
    RomeoJoystick _phone;

};

#endif
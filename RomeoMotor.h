/*
  RomeoMotor.h - Library for using RomeoBLE.
  Created by Malachi Patrick & Mr. Bianchi, November 30, 2018.
  Released into the public domain.
*/

#ifndef RomeoMotor_h
#define RomeoMotor_h

#include "Arduino.h"

class RomeoMotor
{
  public:
    RomeoMotor(int motor);
    void move(int speed);
    void flip(boolean isFlipped);
    void end();
  private:
    int _motor;
    boolean _isFlipped;

};

#endif
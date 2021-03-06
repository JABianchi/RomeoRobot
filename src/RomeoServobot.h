/*
  RomeoServobot.h - Library for using RomeoBLE with 2 Servo motors.
  Created by Mr. Joel Andrew Bianchi, November 29, 2019.
  Released into the public domain.
*/

#ifndef RomeoServobot_h
#define RomeoServobot_h

#include "Arduino.h"
#include <Servo.h>


class RomeoServobot
{
  public:
    RomeoServobot();
    RomeoServobot(int rightServomotorPin, int leftServomotorPin);
    void goForward();
    void goForward(int newSpeed);
    void goBack();
    void goBack(int newSpeed);
    void turnRight();
    void turnLeft();
    void swingTurnRight();
    void swingTurnLeft();
    void off();
    void setOffSpeed(int newOffSpeed);

  private:
    Servo _rightServomotor;
    Servo _leftServomotor;
    int _rPin;
    int _lPin;
    int _centerSpeed;
    int _fwdSpeed;
    int _backSpeed;
    int microSpeed(int input);
};

#endif
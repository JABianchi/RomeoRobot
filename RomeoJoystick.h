/*
  RomeoJoystick.h - Library for using RomeoBLE.
  Created by Mr. Joel Bianchi & Allans Silfa, December 22, 2018.
  Released into the public domain.
*/

#ifndef RomeoJoystick_h
#define RomeoJoystick_h

#include "Arduino.h"

enum ButtonType {
  UP,
  DOWN,
  RIGHT,
  LEFT,
  TOP,
  BOTTOM
};

enum AxisType {
  X,
  Y
};

enum PhoneType{
  ANDROID,
  IPHONE
};



class RomeoJoystick
{
  public:
    RomeoJoystick(PhoneType phoneName);
    boolean button(ButtonType buttonName);
    int axis(AxisType axisName);
    void updateLoop();

    
  private:
    PhoneType _phoneName;

    int _X_VAL;
    int _Y_VAL;
    boolean _UP_VAL;
    boolean _DOWN_VAL;
    boolean _RIGHT_VAL;
    boolean _LEFT_VAL;
    boolean _TOP_VAL;
    boolean _BOTTOM_VAL;
    
    byte _byteNum;
    boolean _isCounting;
    boolean _buttonFlag;
    boolean _joyFlag;

};

#endif
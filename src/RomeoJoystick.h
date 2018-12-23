/*
  RomeoJoystick.h - Library for using RomeoBLE.
  Created by Mr. Joel Bianchi & Allans Silfa, December 22, 2018.
  Released into the public domain.
*/

#ifndef RomeoJoystick_h
#define RomeoJoystick_h

#include "Arduino.h"

class RomeoJoystick
{
  public:
    RomeoJoystick(String type);
    boolean button(String buttonName);
    int joypad(String axis);
    String UP;
    String DOWN;
    String RIGHT;
    String LEFT;
    String TOP;
    String BOTTOM;
    String X;
    String Y;
    String ANDROID;
    String IPHONE;
    
  private:
    String _type;
    String _buttonName;
    String _axis;
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
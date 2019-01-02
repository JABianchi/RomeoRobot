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
  LX,
  LY,
  RX,
  RY 
};

enum AppType{
  GOBLE,
  BLYNK,
  OTHER
};



class RomeoJoystick
{
  public:
    RomeoJoystick(AppType appName);
    boolean button(ButtonType buttonName);
    int axis(AxisType axisName);
    void printJoy(boolean isPrint);
    void printJoy(boolean isPrint, boolean isPrintRaw);
    
  private:
    AppType _appName;
    void updateLoop();
    void updateGOBLE();
    void prints();

    int _LX_VAL;
    int _LY_VAL;
    int _RX_VAL;
    int _RY_VAL;
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
    boolean _isPrint;
    boolean _isPrintRaw;

};

#endif
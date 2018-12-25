/*
  RomeoJoystick.cpp - Library for using RomeoBLE.
  Created by Mr. Joel Bianchi & Allans Silfa, December 22, 2018.
  Released into the public domain.
*/


#include "Arduino.h"
#include "RomeoJoystick.h"


static const byte UP_BUTTON = 1;
static const byte RIGHT_BUTTON = 2;
static const byte DOWN_BUTTON = 3;
static const byte LEFT_BUTTON = 4;
static const byte TOP_BUTTON = 5;
static const byte BOTTOM_BUTTON = 6;

#define HBYTE0 85
#define HBYTE1 170
#define HBYTE2 17

#define BUTTON_CHECK_BYTE 4
#define BUTTON_VAL_BYTE 6
#define AXIS_CHECK_BYTE 5
#define X_JOY_BYTE 7
#define Y_JOY_BYTE 6
#define END_BYTE 8

RomeoJoystick::RomeoJoystick(PhoneType phoneName)
{
  _phoneName = phoneName;
  Serial.begin(115200);
  Serial.println("Starting serial monitor at 115200 for bluetooth joysticks");

  _X_VAL = 0;
  _Y_VAL = 0;
  _UP_VAL = false;
  _DOWN_VAL = false;
  _RIGHT_VAL = false;
  _LEFT_VAL = false;
  _TOP_VAL = false;
  _BOTTOM_VAL = false;

  _byteNum = 0;
  _isCounting = false;
  _buttonFlag = false;
  _joyFlag = false;

}


boolean RomeoJoystick::button(ButtonType buttonName)
{
  updateLoop();

  if(buttonName == UP){
    return _UP_VAL;
  } else if(buttonName == DOWN){
    return _DOWN_VAL;
  } else if(buttonName == RIGHT){
    return _RIGHT_VAL;
  } else if(buttonName == LEFT){
    return _LEFT_VAL;
  } else if(buttonName == TOP){
    return _TOP_VAL;
  } else if(buttonName == BOTTOM){
    return _BOTTOM_VAL;
  } else {
    Serial.println("Incorrect button name.");
    return false;
  }

}


int RomeoJoystick::axis(AxisType axisName)
{

  updateLoop();

  if(axisName == Y){
    return _Y_VAL;
  } else if (axisName == X){
    return _X_VAL;
  } else {
    Serial.println("Incorrect axis name.");
    return 0;
  }

}


//update values based on particular phone & app
private void RomeoJoystick::updateLoop()
{
  if(_phoneName == IPHONE){
    updateGOBLE();
  } else if (_phoneName == ANDROID){
    updateGOBLE();
  } else {
    Serial.println ("Wrong phone type entered.");
  }


}


/*--------Update for GOBLE on IPHONE & ANDROID -------------------------------------------------------------- */
private void RomeoJoystick::updateGOBLE(){

if (Serial.available())  {

  //Get a new byte
  byte inByte = Serial.read();
  
  //Check if a new frame has started
  if(inByte == HBYTE0 && !_buttonFlag && !_joyFlag){
    _byteNum = 1;
    _isCounting = true;
  }

  //Count the bytes in each frame
  if(_isCounting){
      _byteNum++;
  }

  //Reset the counter after 8 bytes
  if(_byteNum == END_BYTE){
    _isCounting = false;
    _buttonFlag = false;
    _joyFlag = false;
  }

  //GET BUTTON VALUES
  if(_byteNum == BUTTON_CHECK_BYTE && inByte == 1){
    //Serial.println("A BUTTON WAS PUSHED!");
    _buttonFlag = true;
  }

  if(_buttonFlag && _byteNum == BUTTON_VAL_BYTE){
    
    //flip all buttons to false
    _UP_VAL = false;
    _DOWN_VAL = false;
    _RIGHT_VAL = false;
    _LEFT_VAL = false;
    _TOP_VAL = false;
    _BOTTOM_VAL = false;

    //flip back only pressed button
    if(inByte == UP_BUTTON){
      _UP_VAL = true;
    } else if(inByte == RIGHT_BUTTON){
      _RIGHT_VAL = true;
    } else if(inByte == DOWN_BUTTON){
      _DOWN_VAL = true;
    } else if(inByte == LEFT_BUTTON){
      _LEFT_VAL = true;
    } else if(inByte == TOP_BUTTON){
      _TOP_VAL = true;
    } else if(inByte == BOTTOM_BUTTON){
      _BOTTOM_VAL = true;
    } else {
      //something wrong happened...
    }
    
  }
    
  //GET JOYPAD VALUES
  if(_byteNum == AXIS_CHECK_BYTE && inByte == 3 && !_buttonFlag){
    //Serial.println("JOYPAD WAS TOUCHED!");
    _joyFlag = true;
  }
  
  if(_joyFlag && _byteNum == Y_JOY_BYTE){
    _Y_VAL = inByte;
  
  } else if(_joyFlag && _byteNum == X_JOY_BYTE){
  
    _X_VAL = inByte;
    _joyFlag = false;
    
    //map values
    _X_VAL = constrain(map(_X_VAL,1,255,-127,127),-127,127);
    _Y_VAL = constrain(map(_Y_VAL,1,255,-127,127),-127,127);

  }      

  //Raw Values Print
  //Serial.print(_byteNum);
  //Serial.print("\t");
  //Serial.print("inByte ");
  //Serial.println(inByte, DEC);

   
}


//Print out All Values Function
RomeoJoystick::printJoy(boolean isPrint){

  if(isPrint){

    Serial.print("Buttons: ");
    Serial.print("UP: ");
    Serial.print(_UP_VAL);
    Serial.print(", DOWN: ");
    Serial.print(_DOWN_VAL);
    Serial.print(", LEFT: ");
    Serial.print(_LEFT_VAL);
    Serial.print(", RIGHT: ");
    Serial.print(_RIGHT_VAL);
    Serial.print(", TOP: ");
    Serial.print(_TOP_VAL);
    Serial.print(", BOTTOM: ");
    Serial.print(_BOTTOM_VAL);
    Serial.print(",     ");      
    Serial.print("Joy: ");
    Serial.print(_X_VAL);
    Serial.print(", ");
    Serial.print(_Y_VAL);
    Serial.print(" )");
    Serial.println();
  }
}    


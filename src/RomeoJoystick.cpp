/*
  RomeoJoystick.cpp - Library for using RomeoBLE.
  Created by Mr. Joel Bianchi & Allans Silfa, December 22, 2018.
  Released into the public domain.
*/


#include "Arduino.h"
#include "RomeoJoystick.h"


ANDROID = "ANDROID";
IPHONE = "IPHONE";
UP = "UP";
DOWN = "DOWN";
RIGHT = "RIGHT";
LEFT = "LEFT";
TOP = "TOP";
BOTTOM = "BOTTOM";
X = "X";
Y = "Y";

byte UP_BUTTON = 1;
byte RIGHT_BUTTON = 2;
byte DOWN_BUTTON = 3;
byte LEFT_BUTTON = 4;
byte HIGH_BUTTON = 5;
byte LOW_BUTTON = 6;

RomeoJoystick::RomeoJoystick(String type)
{
  _type = type;
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


boolean RomeoJoystick::button(String buttonName)
{
  updateLoop();

  if(buttonName.equals(UP)){
    return _UP_VAL;
  } else if(buttonName.equals(DOWN)){
    return _DOWN_VAL;
  } else if(buttonName.equals(RIGHT)){
    return _RIGHT_VAL;
  } else if(buttonName.equals(LEFT)){
    return _LEFT_VAL;
  } else if(buttonName.equals(TOP)){
    return _TOP_VAL;
  } else if(buttonName.equals(BOTTOM)){
    return _BOTTOM_VAL;
  } else {
    Serial.println("Incorrect button name.");
    return false;
  }

}


int RomeoJoystick::joypad(String axis)
{

  updateLoop();

  if(axis.equals(Y)){
    return _Y_VAL;
  } else if (axis.equals(X)){
    return _X_VAL;
  } else {
    Serial.println("Incorrect axis name.");
    return 0;
  }

}


void RomeoJoystick::updateLoop()
{

  //LOOP
  if (Serial.available())  {
    
    byte incomingByte = Serial.read();
    
    if(_type.equals(IPHONE)){

      if(incomingByte == 85){
        _byteNum = 0;
        _isCounting = true;
      }
      
      if(_isCounting){
        _byteNum++;
      }
      
      //BUTTONS
      if(_byteNum == 4 && incomingByte == 1){
        //Serial.println("A BUTTON WAS PUSHED!");
        _buttonFlag = true;
      } else if (_byteNum == 4){
        _buttonFlag = false;
      }
      
      if(_buttonFlag && _byteNum == 6){
        
        //flip all buttons to false
        _UP_VAL = false;
        _DOWN_VAL = false;
        _RIGHT_VAL = false;
        _LEFT_VAL = false;
        _TOP_VAL = false;
        _BOTTOM_VAL = false;

        //flip back only pressed button
        if(incomingByte == UP_BUTTON){
          _UP_VAL = true;
        } else if(incomingByte == RIGHT_BUTTON){
          _RIGHT_VAL = true;
        } else if(incomingByte == DOWN_BUTTON){
          _DOWN_VAL = true;
        } else if(incomingByte == LEFT_BUTTON){
          _LEFT_VAL = true;
        } else if(incomingByte == TOP_BUTTON){
          _TOP_VAL = true;
        } else if(incomingByte == BOTTOM_BUTTON){
          _BOTTOM_VAL = true;
        } else {
          //something wrong happened...
        }
        
      }
      
      
      //JOYPAD
      if(_byteNum == 5 && incomingByte == 3){
        //Serial.println("JOYPAD WAS TOUCHED!");
        _joyFlag = true;
      } else if (_byteNum == 5){
        _joyFlag = false;
      }
      
      if(_joyFlag && _byteNum == 6){
        _Y_VAL = incomingByte;
      
      } else if(_joyFlag && _byteNum == 7){
      
        _X_VAL = incomingByte;
        _joyFlag = false;
        
        //map values
        _X_VAL = map(_X_VAL,1,255,-127,127);
        _Y_VAL = map(_Y_VAL,1,255,-127,127);

      }      
    }

    else if(_type.equals(ANDROID)){
      Serial.println("Android not supported yet...");
    }


    //PRINT OUT
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
    

    //RAW DATA PRINT
    /*
    Serial.print(byteNum);
    Serial.print(":  value = ");
    Serial.print(incomingByte);
    Serial.println();   //print line feed character
    */
    
  }
}

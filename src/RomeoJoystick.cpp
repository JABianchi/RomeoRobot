/*
  RomeoJoystick.cpp - Library for using RomeoBLE.
  Created by Mr. Joel Bianchi & Allans Silfa, December 22, 2018.
  Released into the public domain.
*/


#include "Arduino.h"
#include "RomeoJoystick.h"


#define UP_BUTTON 1
#define RIGHT_BUTTON 2
#define DOWN_BUTTON 3
#define LEFT_BUTTON 4
#define TOP_BUTTON 5
#define BOTTOM_BUTTON 6

#define GOBLE_HBYTE1 85
#define GOBLE_HBYTE2 170
//#define GOBLE_HBYTE3 17
#define GOBLE_BUTTON_CHECK_BYTE 4
#define GOBLE_BUTTON_VAL_BYTE 6
#define GOBLE_AXIS_CHECK_BYTE 5
#define GOBLE_X_JOY_BYTE 7
#define GOBLE_Y_JOY_BYTE 6
#define GOBLE_END_BYTE 8

RomeoJoystick::RomeoJoystick(AppType appName)
{
  _appName = appName;
  Serial.begin(115200);
  Serial.println("Starting serial monitor at 115200 for bluetooth joysticks");

  _LX_VAL = 0;
  _LY_VAL = 0;
  _RX_VAL = 0;
  _RY_VAL = 0;
  _UP_VAL = false;
  _DOWN_VAL = false;
  _RIGHT_VAL = false;
  _LEFT_VAL = false;
  _TOP_VAL = false;
  _BOTTOM_VAL = false;

  _byteNum = -1;
  _isCounting = false;
  _buttonFlag = false;
  _joyFlag = false;
  _isPrint = false;
  _isPrintRaw = false;

}


int RomeoJoystick::axis(AxisType axisName)
{

  updateLoop();

  if(axisName == LY){
    return _LY_VAL;
  } else if (axisName == LX){
    return _LX_VAL;
  } else if (axisName == RY){
    return _RY_VAL;
  } else if (axisName == RX){
    return _RX_VAL;
  } else {
    Serial.println("Incorrect axis name.");
    return 0;
  }

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


//update values based on particular phone & app
void RomeoJoystick::updateLoop()
{
  if(_appName == GOBLE){
    updateGOBLE();
  } else if (_appName == BLYNK){
    //updateBLYNK();            //new method to be added later
  } else {
    Serial.println ("Wrong app type entered.");
  }


}


/*--------Update for GOBLE on IPHONE & ANDROID -------------------------------------------------------------- */
void RomeoJoystick::updateGOBLE(){

  if (Serial.available())  {

    //Get a new byte
    byte inByte = Serial.read();
    
    //Check if a new frame has started
    if(inByte == GOBLE_HBYTE1 && !_buttonFlag && !_joyFlag){
      _byteNum = 0;
      _isCounting = true;
    }

    //Count the bytes in each frame
    if(_isCounting){
        _byteNum++;
    }

    //Reset early if second byte doesn't fit 
    if(_byteNum == 2 && inByte != GOBLE_HBYTE2){
      _isCounting = false;
      _byteNum = -1;
    }

    //Reset the counter after 8 bytes
    if(_byteNum == GOBLE_END_BYTE){
      _isCounting = false;
      _buttonFlag = false;
      _joyFlag = false;
      _byteNum = -1;
    }

    //GET BUTTON VALUES
    if(_byteNum == GOBLE_BUTTON_CHECK_BYTE && inByte == 1){
      //Serial.println("A BUTTON WAS PUSHED!");
      _buttonFlag = true;
    }

    if(_buttonFlag && _byteNum == GOBLE_BUTTON_VAL_BYTE){
      
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
    if(_byteNum == GOBLE_AXIS_CHECK_BYTE && inByte == 3 && !_buttonFlag){
      //Serial.println("JOYPAD WAS TOUCHED!");
      _joyFlag = true;
    }
    
    if(_joyFlag && _byteNum == GOBLE_Y_JOY_BYTE){
      _LY_VAL = inByte;
    
    } else if(_joyFlag && _byteNum == GOBLE_X_JOY_BYTE){
    
      _LX_VAL = inByte;
      _joyFlag = false;
      
      //map values
      _LX_VAL = constrain(map(_LX_VAL,1,255,-127,127),-127,127);
      _LY_VAL = constrain(map(_LY_VAL,1,255,-127,127),-127,127);

    }

    prints();

    //Print Raw Values
    if(_isPrintRaw){
      Serial.print(_byteNum);
      Serial.print("\t");
      Serial.print("inByte ");
      Serial.println(inByte, DEC);
    }

  }   
}


//Print out all values function
void RomeoJoystick::prints(){

    //Print Values
    if(_isPrint){

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
      Serial.print("LJoy: (");
      Serial.print(_LX_VAL);
      Serial.print(", ");
      Serial.print(_LY_VAL);
      Serial.print(" ), ");
      Serial.print("RJoy: (");
      Serial.print(_RX_VAL);
      Serial.print(", ");
      Serial.print(_RY_VAL);
      Serial.print(" )");
      
      Serial.println();
    }

}

//Check if print out All Values Function
void RomeoJoystick::printJoy(boolean isPrint){
  _isPrint = isPrint;
}

//Check if print out All Values Function including frame data
void RomeoJoystick::printJoy(boolean isPrint, boolean isPrintRaw){
  _isPrint = isPrint;
  _isPrintRaw = isPrintRaw;
}
    
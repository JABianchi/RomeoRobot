/*
  RomeoMotor.cpp - Library for using RomeoBLE.
  Created by Malachi Patrick & Mr. Bianchi, November 30, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RomeoMotor.h"


RomeoMotor::RomeoMotor(int motor)
{
  _motor = motor;
  _isFlipped = false;
}


void RomeoMotor::move(int speed)
{
  int E1 = 5; //M1 Speed Control
  int E2 = 6; //M2 Speed Control
  int M1 = 4; //M1 Direction Control
  int M2 = 7; //M1 Direction Control
 
  boolean isFwd = true;
  
  if(speed < 0){
    speed = -speed;
    isFwd = false;
  }
  
  if(_isFlipped){
    isFwd = !isFwd;
  }
  
  if(speed > 127){
    speed = 100;
  }
 
  if(speed < 20){
    speed = 0;
  }
  
  speed = map(speed,0,127,0,255); 
 
  if(_motor == 1){
    
    analogWrite(E1, speed);
    if(isFwd)
      digitalWrite(M1,HIGH);
    else
      digitalWrite(M1,LOW);
  }
  else if(_motor == 2){
    
    analogWrite(E2, speed);
    if(isFwd)
      digitalWrite(M2,HIGH);
    else
      digitalWrite(M2,LOW);
  } 
}


void RomeoMotor::flip(boolean isFlipped)
{
    _isFlipped = isFlipped;
}


void RomeoMotor::end()
{
  int E1 = 5; //M1 Speed Control
  int E2 = 6; //M2 Speed Control
  
  if(_motor == 1){
    analogWrite(E1, 0);
  } else if(_motor == 2){
    analogWrite(E2, 0);
  }

  _motor = 0;

}

//function deprecated
void RomeoMotor::shutDown()
{
  ::end();
}
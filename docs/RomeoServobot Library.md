# RomeoServobot Library v1.40
11/29/2019

This library provides functions to control an Arduino robot using the DFRobot Romeo BLE board.
It was inspired by Carnegie Mellon's Robotics Academy's work on RobotC for the VEX Controls system.
This library in particular can easily be used with a robot chassis base like the BOE BOT which controls the wheels with two Servo motors.

Links to other Libraries:
* Go to the [RomeoMotor Library](RomeoMotor%20Library.md)
* Go to the [RomeoJoystick Library](RomeoJoystick%20Library.md)
* Go to the [RomeoDrive Library](RomeoDrive%20Library.md)

<br/><br/>

# RomeoServobot()
### description:
* A RomeoServobot object must be constructed to use the RomeoServobot functions
* By default, the right motor should be plugged into port 9 and the left motor into port 10.
### syntax:
```c
RomeoServobot botName()
```
### variable names:
* botName = the name of your RomeoServobot

<br/><br/>

# RomeoServobot(int rightServomotorPin, int leftServomotorPin)
### description:
* A RomeoServobot object must be constructed to use the RomeoServobot functions
* This version of the constructor allows you to use non-default pins
* Note that the only allowable analog pins on Romeo board are: 3,5,6,9,10,11
### syntax:
```c
RomeoServobot botName(rightServomotorPin, leftServomotorPin)
```
### variable names:
* botName = the name of your RomeoServobot
### parameters:
* rightServomotorPin = the digital port that you plug the right Servomotor into
* leftServomotorPin = the digital port that you plug the left Servomotor into

<br/><br/>

# goForward()
### description:
* Makes the servobot move foward at a specified speed.
* There is a dead range of +-20 where the motor won't move.
* If a value greater than +127 or less than -127 is passed in, then they will be reduced to 100 or -100.
### syntax:
```c
goForward(speed)
```
### parameters:
* speed = an integer from -127 to +127 to make the motor move
  * ```127``` is full speed forward
  * ```0``` is not moving
  * ```-127``` is full speed backwards
### returns:
* none

<br/><br/>

# off()
### description:
* The off() method stops the servobot from moving.
* If having trouble restrating, try resetting the Arduino.
### syntax:
```c
off()
```
 ### parameters:
 * none
 ### returns:
 * none

 
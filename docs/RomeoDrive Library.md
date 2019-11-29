# RomeoDrive Library v1.40
11/29/2019

This library provides functions to control an Arduino robot using the DFRobot Romeo BLE board.
It was inspired by Carnegie Mellon's Robotics Academy's work on RobotC for the VEX Controls system.

Links to other Libraries:
* Go to the [RomeoMotor Library](RomeoMotor%20Library.md)
* Go to the [RomeoJoystick Library](RomeoJoystick%20Library.md)
* Go to the [RomeoServobot Library](RomeoServobot%20Library.md)


# RomeoDrive()
### description:
* A RomeoDrive object can be simply constructed to connect to both motors with the Right motor connected to M1 and the left motor connected to M2.  If using a smartphone app, you will need to manually construct a RomeoJoystick object if using this constructor.
### syntax:
```c
RomeoDrive robotName()
```
### variable names:
* robotName = the name of your RomeoDrive variable
### parameters:
* none



# RomeoDrive()
### description:
* This version of a RomeoDrive constructor will take in the name of the smartphone app you are using and automatically setup the RomeoJoystick for you.
### syntax:
```c
RomeoDrive robotName(appName)
```
### variable names:
* robotName = the name of your RomeoDrive variable
### parameters:
* appName = ```GOBLE``` or ```BLYNK``` or ```OTHER```, the name of the smartphone app you are using to control your robot.

### note:
* When pairing your phone with the Romeo board, the Android password for the "Go BLE" app is ```000000```

<br/><br/>

# arcade()
### description:
* Allows for arcade-style control of a robot:
  * Forward & backward are controlled by pushing your left thumb forward or backward (LEFT Y_AXIS)
  * Turning is controlled by pushing your left thumb to the right or left (LEFT X_AXIS)
* This version of arcade() should be used if you already set the appName in your RomeoDrive constructor.
### syntax:
```c
arcade()
```
### parameters:
* none
### returns:
* none



# arcade()
### description:
* Allows for arcade-style control of a robot.
* This version of arcade() should be used if you want to manually determine which axes are used for 
  * forward/backward and 
  * turning.
### syntax:
```c
arcade(moveSpeed, turnSpeed)
```
### parameters:
* moveSpeed = an integer from -127 to +127 to make the robot move:
  * ```127``` is full speed forward
  * ```0``` is not moving
  * ```-127``` is full speed reverse
    *
* turnSpeed = an integer from -127 to +127 to make the robot turn:
  * ```127``` is full speed turning right
  * ```0``` is not moving
  * ```-127``` is full speed turning left
### returns:
* none

<br/><br/>

# off()
### description:
* The end() method in RomeoDrive stops BOTH motors from moving the rest of the program.
* The only way to regain functionality of the motor is to reset the Arduino.
* (This method calls on the end() method in the RomeoMotor class for both motors.)
### syntax:
```c
off()
```
 ### parameters:
 * none
 ### returns:
 * none

 
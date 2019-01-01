# RomeoRobot Libraries v1.30
1/1/2019

RomeoRobot describes a set of libraries designed to control an Arduino robot using the DFRobot Romeo BLE board.
It was inspired by Carnegie Mellon's Robotics Academy's work on RobotC for the VEX Controls system.

The following libraries are included:

## RomeoMotor
* Control individual motors using a single integer for its speed

## RomeoJoystick
* Control the robot using the GO BLE app on iPhone or Android smartphone

## RomeoDrive
* Choose a drive system (arcade drive, tank drive, mecanum drive, etc) to remotely control your robot


## Future Work
* Integration of the configurable BLYNK app (when BLYNK revises their BLE plugin)
* Include tank-drive methods for BLYNK app
* RomeoMotor methods to control motors beyond the M1 and M2 ports (that use a VEX MC-29 on Arduino pins 3,5,6,9,10,11)
* Include mecanum-drive methods

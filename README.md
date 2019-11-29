# RomeoRobot Libraries v1.4
11/29/2019

RomeoRobot describes a set of libraries designed to control an Arduino robot using the DFRobot Romeo BLE board.
It was inspired by Carnegie Mellon's Robotics Academy's work on RobotC for the VEX Controls system.

The following libraries are included:

## [RomeMotor Library](docs/RomeoMotor%20Library.md)
* Control individual motors using a single integer for its speed
* Go to the [RomeMotor Library](docs/RomeoMotor%20Library.md)

## [RomeoJoystick Library](docs/RomeoJoystick%20Library.md)
* Control the robot using the GO BLE app on iPhone or Android smartphone
* Go to the [RomeoJoystick Library](docs/RomeoJoystick%20Library.md)

## [RomeoDrive Library](docs/RomeoDrive%20Library.md)
* Choose a drive system (arcade drive, tank drive, mecanum drive, etc) to remotely control your robot
* Go to the [RomeoDrive Library](docs/RomeoDrive%20Library.md)

## [RomeoServobot Library](docs/RomeoServobot%20Library.md)
* Control a robot using 2 servo motors.
* Go to the [RomeoServobot Library](docs/RomeoServobot%20Library.md)

 <br/><br/>

## Current Bugs
* 1.3.1 Bug in RomeoJoystick constructor used in RomeoDrive class, appName param being passed as 512.  Temporarily, this param is bypassed to always use the GOBLE app.

## Future Work
* Integration of the configurable [BLYNK app](https://github.com/blynkkk/blynk-library) (when BLYNK revises their BLE plugin)
* Include tank-drive methods for [BLYNK app](https://github.com/blynkkk/blynk-library)
* RomeoMotor methods to control motors beyond the M1 and M2 ports
  * Could use a [VEX MC-29](https://www.vexrobotics.com/276-2193.html) on Arduino pins 3,5,6,9,10,11
  * Could use [dfRobot's Cherokey pcb](https://www.dfrobot.com/wiki/index.php/Cherokey_4WD_Mobile_Platform_(SKU:ROB0102)#Microcontroller_Compatibility) 
* Include mecanum-drive methods

# RomeoJoystick Library v1.30
1/1/2019

This library provides functions to read the values from a BLE smartphone app
in order to remotely control an Arduino robot using the DFRobot Romeo BLE board.
The "GO BLE" app is officially supported by dfRobot, and provides a 2-axis joystick and 6 buttons of feedback.
This library follows similar conventions to Carnegie Mellon's Robotics Academy's work on RobotC for the VEX Controls system.

Links to other Libraries:
* Go to the [RomeMotor Library](RomeoMotor%20Library.md)
* Go to the [RomeoDrive Library](RomeoDrive%20Library.md)



# RomeoJoystick()
### description:
* A RomeoJoystick object must be constructed to use one of the two motor ports provided on the DFRobot Romeo board.
### syntax:
```c
RomeoJoystick phoneName(appName)
```
### variable names:
* phoneName = the name of your RomeoJoystick variable
### parameters:
* appName = ```GOBLE``` or ```BLYNK``` or ```OTHER```, the name of the smartphone app you are using to control your robot.
### note:
* When pairing your phone with the Romeo board, the Android password for the "Go BLE" app is ```000000```


# axis()
### description:
* Reads the values of the analog joysticks in your smartphone app and returns the integer value
### syntax:
```c
axis(axisName)
```
### parameters:
* axisName = ```LY``` or ```LX``` or ```RY``` or ```RX```
  * ```LY``` = Left joystick, Y-axis
  * ```LY``` = Left joystick, X-axis
  * ```RY``` = Right joystick, Y-axis
  * ```RX``` = Right joystick, X-axis
  
  ### returns:
* an integer from -127 to +127
  * ```127``` is all the way up or all the way right
  * ```0``` is when the joystck is not being touched
  * ```-127``` is all the way down or all the way left


# button()
### description:
* Reads the values of a button in your smartphone app and returns the boolean value
### syntax:
```c
button(buttonName)
```
### parameters:
* buttonName = ```UP``` , ```DOWN``` , ```RIGHT``` , ```LEFT``` , ```TOP``` , ```BOTTOM```
  * Each button corresponds to its location on the controller
  * For the iPHONE GO BLE app: ```TOP``` and ```BOTTOM``` refer to the two buttons located in the center of the screen
  * For the ANDROID GOBLE app: ```UP```=1, ```DOWN```=2, ```RIGHT```=3, ```LEFT```=4, ```TOP```=5, ```BOTTOM```=6
### returns:
* ```TRUE``` or ```FALSE``` depending if the button is pressed or not
  * ```TRUE``` corresponds to 1
  * ```FALSE``` corresponds to 0
  
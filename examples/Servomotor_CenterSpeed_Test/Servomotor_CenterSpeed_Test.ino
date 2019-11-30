#include <Servo.h>
Servo motor;

void setup() {
  motor.attach(9);
  Serial.begin(9600);
}

void loop() {
  
  for(int i = 1000; i<2000; i+=50){
    motor.writeMicroseconds(i);
    Serial.println(i);
    delay(500);
  }
  
}

/*Servo motor + joystick program
 The goal of this program is to control a servo with the use
 of a joystick
 */
#include <Servo.h>//add servo library
 
Servo myservo;  // create servo object to control a servo
 
int joypin = 0;  // analog pin used to connect the joystick
int val;    // variable to read the value from the analog pin
 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
 
void loop() {
  val = analogRead(joypin);            // reads the value of the joystick (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

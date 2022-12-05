/* Arduino joystick and DC motor speed and direction
 *  This program is meant to change the speed and direction by 
 *  the amount the joystick is tilted(speed)
 *  and the side it is tilted to(direction) by changing it's output side
 */
#define joystick     A0//pin for joystick
#define pwm1          9//pin for motor
#define pwm2         10//pin for motor
 
int motor_control;// variable to control motor
 
void setup() {
  pinMode(pwm1,   OUTPUT);//setting the pins for motor
  pinMode(pwm2,   OUTPUT);//setting the pins for motor
}
 
void loop() {
  motor_control = analogRead(joystick); //storing joystick value in a variable
  motor_control >>= 1; //bitchshifts the value right by 1 to change the range from 10bit to 9 bit
  if(motor_control > 255){ //if the value from joystick is greater than 255
    digitalWrite(pwm2, 0);// turns off pin 10
    analogWrite(pwm1, (motor_control - 256));// turns on pin 9 at the speed motor_control - 256
  }
  else
    if(motor_control < 255){//if the value from joystick is less than 255
      digitalWrite(pwm1, 0);// turns off pin 9
      analogWrite(pwm2, (255 - motor_control));// turns on pin 10 at the speed 255 - motor_control
    }
    else{//else, in the middle the speed of the dc and direction are zero
      digitalWrite(pwm1, 0);// turns off pin 9
      digitalWrite(pwm2, 0);// turns off pin 10
    }
}

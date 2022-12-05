/*Servo motor + LDR program
 The goal of this program is to print LDR values on 
 */
#include <Servo.h>//add servo library
 
Servo myservo;  // create servo object to control a servo
 
int ldr_pin = 0;  // analog pin used to connect the LDR
int val;    // variable to read the value from the analog pin
 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}
 int servo_move;// variable for servo movement
 float voltage; // variable for voltage
 float resistance; // variable for resistance
void loop() {
  val = analogRead(ldr_pin);            // reads the value of the LDR (value between 0 and 1023)
  servo_move = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  voltage = map(val, 0, 1023, 0, 5000);     // scale it to voltage (value between 0 and 5000)
  votlage = voltage/1000;                   //dividing it to get a value between 0 and 5
  resistance = map(val, 0, 1023, 0, 100 000);     // scale it to resistance (value between 0 and 100 000)
  resistance = (-1*resistance) + 100 000;     //inversing the value    
  Serial.print(val);//prints on serial bit value      
  Serial.print(" bits ");//prints on serial text
  Serial.print(voltage);//prints on serial voltage value      
  Serial.print(" volts ");//prints on serial text 
  Serial.print(resistance);//prints on serial resitance value      
  Serial.println("bits");//prints on serial text   
  myservo.write(servo_move);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

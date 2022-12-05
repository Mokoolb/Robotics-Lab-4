/*stepper motor + infrared remote (control direction, control speed is optional)
 * This program is meant to have a stepper motor controlled by an infrared remote
 */

#include "Stepper.h"//including the stepper library
#include "IRremote.h"//including the Ir remote library

/*----- Variables, Pins -----*/
#define STEPS  32   // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 steps = 1 Revolution
int receiver = 6; // Signal Pin of IR receiver to Arduino Digital Pin 6
 int direct = 0; // indicated the 2 directions of the stepper motor, 0 and 1 (direction 2 would be none at all, so stopped)
 int sped = 500; // this indicates the speed at which the motor rotates
/*-----( Declare objects )-----*/
// Setup of proper sequencing for Motor Driver Pins
// In1, In2, In3, In4 in the sequence 1-3-2-4

Stepper small_stepper(STEPS, 7, 10, 9, 11);// uses the stepper library to set all the pins
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

void setup()// this code runs once
{ 
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600); // begin recording values sent to the serial to read the ir values
}

void loop()// this code runs forever
{
if (irrecv.decode(&results)) // have we received an IR signal?

  {
    switch(results.value)// takes the values from results.value and goes to the corresponding case

    {
      case 16736925: // VOL+ button pressed
      if(sped <2000){ // if speed is less then 2000 which is the max
      sped += 50;// increases the speed of the stepper
      }
                      
                      
                      break; //leaves the switch loop
      case 16754775: // VOL- button pressed
      sped -= 50;// decreases the speed of the stepper
                      
                      
                      break; //leaves the switch loop
      case 16769055: // UP button pressed
      direct = 1; //changes the direction of stepper
                      
                      
                      break; //leaves the switch loop

      case 16748655: // DOWN button pressed
      direct = 0;//changes the direction of stepper
                      
                      
                      break; //leaves the switch loop
      case 16753245: // POWER button pressed
      direct = 2; //turns off the stepper since it doesnt have 3 directions
                      
                      
                      break; //leaves the switch loop
                      
    }
      Serial.println(results.value);//prints values to use in the switch loop in serial monitor
      irrecv.resume(); // receive the next value
  }  

  if(direct == 0){// if direction is 0 it does this code
    small_stepper.setSpeed(sped);//takes the steps at speed "sped"
    Steps2Take  =  -10;  // Rotate 
    small_stepper.step(Steps2Take); // 2048 steps = 1 Revolution
  }
  else if(direct == 1){// else if direction is 1 it does this code
    small_stepper.setSpeed(sped);//takes the steps at speed "sped"
    Steps2Take  =  10;  // Rotate 
    small_stepper.step(Steps2Take);// 2048 steps = 1 Revolution
  }
  else{// else the stepper turns off
        digitalWrite(11, LOW);// turns off pin 11
    digitalWrite(10, LOW);// turns off pin 10
    digitalWrite(9, LOW);// turns off pin 9
    digitalWrite(7, LOW); // turns off pin 7
  }

}/* --end main loop -- */

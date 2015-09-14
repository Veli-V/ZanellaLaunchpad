/*
  objects.h - external code for the Zanella Launchpad 
  Created by Lucas Zanella, April 06, 2014.
  Released into the public domain.
  http://lucaszanella.com
*/

//Types of table objects
#define LAUNCHPAD 0 //Launchpad object has number 0
#define PIANO 1 //Piano object has number 1 

//Types of buttons
#define HIT 0 //Buttons that you HIT and then the sound is played
#define HOLD 1 //Buttons that play the sound while you're holding it
#define KNOB 2 //Buttons that have variation, like a KNOB (potentiometer)

//Other definitions
#define SERIAL_BPS 115200 //Serial Data Rate
#define NOTHING -1

//Choose the multiplexer chips you want to use. Uncomment '#define normalAnalogPort' if you want to directly use an analog pin 
//without a multiplexer board. You can uncomment all of these options at the same time.


//#define chipCD74HC4067 1 //this is just a number to identify the sparkfun board
#define chip74HC4051 2 //this number identifies the other board 74HC4051
#define chip74HC4051_KEYSIZE 8
//you can use both the options at the same time or just one of the two

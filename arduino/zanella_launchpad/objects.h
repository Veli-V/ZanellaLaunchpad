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

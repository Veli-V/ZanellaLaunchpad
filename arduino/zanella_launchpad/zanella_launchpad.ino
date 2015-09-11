/*
  zanella_launchpad.ino - The Launchpad Project.
  Created by Lucas Zanella, March 24, 2014.
  Released into the public domain.
  http://lucaszanella.com
*/


#include "analogMultiplexer.h"
#include "objects.cpp"

//Choose the multiplexer chips you want to use. Uncomment '#define normalAnalogPort' if you want to directly use an analog pin 
//without a multiplexer board. You can uncomment all of these options at the same time.


//#define chipCD74HC4067 1 //this is just a number to identify the sparkfun board
#define chip74HC4051 2 //this number identifies the other board 74HC4051


//you can use both the options at the same time or just one of the two

//USER CUSTOMIZABLE PART
//*********************************************************************
//Here you define what you'll have on your table, how many keys, etc...
//This is my configuration, you can create your own:
//Define here how many multiplexer boars you have
char quantityOfBoards = 4;//Defines the quantity of multiplexer boards you're gonna use (sum of them, no matter if mixed types of boards)
analogMultiplexer board[quantityOfBoards];//Creates 4 multiplexer boards
//*********************************************************************
//END



void setup()
{
  int controlpins[] = {2, 3, 4};//the pins of the arduino that you will use to control the board
//board[n].Begin(h, controlpins, name_of_the_chip); where n is the number of the board in the array 'board', h is the analog pin that this board will use, name_of_the_chip is the name of the multiplexer
  board[0].Begin(0, controlpins, chip74HC4051);  //Defines the analog pin 0 to control board[0] using chip 74HC4051, where 'controlpins' are the pins going to control it
  board[1].Begin(1, controlpins, chip74HC4051);  //Same but assigns analog pin 1 to control board[1] using chip 74HC4051... 
  board[2].Begin(2, controlpins, chip74HC4051);  //...
  board[3].Begin(3, controlpins, chip74HC4051);
  Serial.begin(SERIAL_BPS);
}

void loop()
{
  for (char i = 0; i<=quantityOfBoards; i++) {
    char numberOfPinsInTheBoard = board[i].numberOfPins
    for (char k = 0; k<numberOfPinsInTheBoard;k++) { 
      Serial.write(0xFF);//packet header
      Serial.write(board[0].Read(0));
      Serial.write(0xFF);//packet footer
    }
  }
}


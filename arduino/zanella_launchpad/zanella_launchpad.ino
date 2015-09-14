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

#define SERIAL_BPS 115200 //Serial Data Rate
void setup()
{
  //USER CUSTOMIZABLE PART
  //*********************************************************************
  
  //Here you define what you'll have on your table, how many keys, etc...
  //This is my configuration, you can create your own:
  //Define here how many multiplexer boars you have
  int controlpins[] = {2, 3, 4};
  #define quantityOfBoards 4//Defines the quantity of multiplexer boards you're gonna use (sum of them, no matter if mixed types of boards)
  analogMultiplexer board[quantityOfBoards](controlpins, chip74HC4051);//Creates 4 multiplexer boards
  
  //*********************************************************************
  //END
  
  Serial.begin(SERIAL_BPS);
}

void loop()
{
  for (char i = 0; i<=quantityOfBoards; i++) {
    char numberOfPinsInTheBoard = board[i].numberOfPins;
    for (char k = 0; k<numberOfPinsInTheBoard;k++) { 
      //Serial.write(0xFF);//packet header
      //Serial.write(board[0].Read(0,chip74HC4051));
      int a = board[0].Read(0,chip74HC4051);
      delay(1000);
      //Serial.println(board[0].Read(1,chip74HC4051));
      int b = board[0].Read(1,chip74HC4051);
      delay(1000);
      //Serial.write(0xFF);//packet footer
    }
  }
}


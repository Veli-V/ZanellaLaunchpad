/*
  zanella_launchpad.ino - The Launchpad Project.
  Created by Lucas Zanella, March 24, 2014.
  Released into the public domain.
  http://lucaszanella.com
*/

#include "definitions.h"
#include "analogMultiplexer.h"


//USER CUSTOMIZABLE PART
//*********************************************************************

//Here you define what you'll have on your table, how many keys, etc...
//This is my configuration, you can create your own:
//Define here how many multiplexer boars you have
#define quantityOfBoards 4//Defines the quantity of multiplexer boards you're gonna use (sum of them, no matter if mixed types of boards)
analogMultiplexer board[quantityOfBoards];//Creates 4 multiplexer boards
//*********************************************************************
//END



void setup()
{
  Serial.begin(SERIAL_BPS);//Begins serial with SERIAL_BPS that is defined at definitions.h
  int controlpins[] = {2, 3, 4};//Pins you're going to use for control a board. Here I use the same pins for all boards (doesn't matter, you can do it)
  int numberOfControlPins = sizeof(controlpins)/sizeof(controlpins[0]);//Just calculate the size of the controlpins array to pass in the board.Begin() method.
//Create your boards here
//board[n].Begin(h, controlpins, numberOfControlPins, name_of_the_chip); where n is the number of the board in the array 'board', h is the analog pin that this board will use, name_of_the_chip is the name of the multiplexer
  board[0].Begin(0, controlpins, numberOfControlPins, chip74HC4051);  //Defines the analog pin 0 to control board[0] using chip 74HC4051, where 'controlpins' are the pins going to control it
  board[1].Begin(1, controlpins, numberOfControlPins, chip74HC4051);  //Same but assigns analog pin 1 to control board[1] using chip 74HC4051... 
  board[2].Begin(2, controlpins, numberOfControlPins, chip74HC4051);  //...
  board[3].Begin(3, controlpins, numberOfControlPins, chip74HC4051);
}

void loop()
{
  //for (char i = 0; i<=quantityOfBoards; i++) {
    //char numberOfPinsInTheBoard = board[i].numberOfPins;
    char numberOfPinsInTheBoard = board[0].numberOfPins;
    Serial.println(numberOfPinsInTheBoard);
    for (char k = 0; k<numberOfPinsInTheBoard;k++) { 
      //Serial.write(0xFF);//packet header
      //Serial.write(board[0].Read(0,chip74HC4051));
      int a = board[0].Read(k,chip74HC4051);
      delay(1000);
      //Serial.write(0xFF);//packet footer
    }
 // }
}


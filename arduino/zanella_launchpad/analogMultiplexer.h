/*
  Multiplexer.h - Library for the multiplexer chip CD74HC4067 
  Created by Lucas Zanella, March 24, 2014.
  Released into the public domain.
  http://lucaszanella.com

  This library allows the creation of multiple multiplexer objects, each one
  to control a specific multiplexer board in your project, so you can use multiple
  boards just by creating objects for this.
  I recommend using the same S0, S1, S2, S3 pins to all the boards in the project,
  if you're gonna read them at the same time, so you don't need to spend a lot of
  digital pins just to control the boards.
*/


#ifndef analogMultiplexer_h
#define analogMultiplexer_h
#include "Arduino.h"

class analogMultiplexer
{
  public:
    analogMultiplexer();
    int type;
    bool pinsToNotRead;
    int Read(int pin, int type); //The function that reads an specific pin of the board.
    void Begin(int analogpin, int pinage[], int boardType);//This function sets up the board configurations
    int numberOfPins;
    int key_size;
    typedef struct {
      int value;
      int type;
    }key;
  protected:
    int SIG; //The analog pin of the arduino that the board is gonna use
    #if defined (chipCD74HC4067)
      int pins_chipCD74HC4067[4];//pins for chipCD74HC4067
    #endif
    #if defined (chip74HC4051)
      int pins_chip74HC4051[3];//pins for chip74HC4051
    #endif
};

#endif

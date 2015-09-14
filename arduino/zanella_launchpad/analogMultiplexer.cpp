/*
  multiplexer.cpp - Library for the multiplexer chip CD74HC4067 (and maybe others)
  Created by Lucas Zanella, March 24, 2014.
  Released into the public domain.
  http://lucaszanella.com
*/

#include "analogMultiplexer.h"
#include "Arduino.h"


//Configs for CD74HC4067 chip
//#define chipCD74HC4067 1 //This is the sparkfun multiplexer board I use in my projects.
//#define chipCD74HC4067_KEYSIZE 16

//Configs for 74HC4051 chip
#define chip74HC4051 2 //this is the multiplexer I'm using in my projects
#define chip74HC4051_KEYSIZE 8

int pins_chip74HC4051[3];
int SIG;
int numberOfPins;
int type;

#if defined (chip74HC4051)
  bool pinsToNotReadFromCD74HC4067[chip74HC4051_KEYSIZE];
#endif

analogMultiplexer::analogMultiplexer() {
}

void analogMultiplexer::Begin(int analogpin, int pinage[], int boardType) {
  SIG = analogpin;
  numberOfPins = sizeof(pinage)/sizeof(pinage[0]);
  type = boardType;
  
  //Declares the pins that will control the S0, S1, S2, S3, ... pins of the board, as output 
  for (int h=0; h<numberOfPins; h++) {
    pinMode(pinage[h], OUTPUT);
  }
  
  #if defined (chipCD74HC4067)
    pins_chipCD74HC4067[] = {pinage[0], pinage[1], pinage[2],pinage[3]}; 
  #endif
  
  #if defined (chip74HC4051)
    pins_chip74HC4051[0] = pinage[0];
    pins_chip74HC4051[1] = pinage[1];
    pins_chip74HC4051[2] = pinage[2];
  #endif
}

int analogMultiplexer::Read(int pin, int type) {//The method that reads a specific analog input of the board. For example Read(3) will read the fourth port (the port named 3, counting from 0 to 3).
   #if defined (chipCD74HC4067)
   if (type==chipCD74HC4067){
     for(int i = 0; i < chipCD74HC4067_KEYSIZE; i++)
     {
       digitalWrite(pins_chipCD74HC4067[i], bitRead(pin, i));
     }
     return analogRead(SIG);
   }
   #endif
   
   #if defined (chip74HC4051)
    if (type==chip74HC4051){//even if there's minor difference between these two boards, i prefer to write a separate case for each one, because other boards may be a lot different
      for(int i = 0; i < chip74HC4051_KEYSIZE; i++)
      {
        digitalWrite(pins_chip74HC4051[i], bitRead(pin, i));
        Serial.println("dW("+String(pins_chip74HC4051[i])+","+String(bitRead(pin, i)));
      }
      return analogRead(SIG);
    }
   #endif
}

void doNotReadThisPin (char pin) {//Specify a pin that you dan't want to be read
  //pinsToNotRead[pin] = 1;
}

void doNotReadThesePins (char pins[]) {//Specify a set of pins that you don't want to be read
  char numberOfPinsToNotRead = sizeof(pins)/sizeof(pins[0]);
  for (char i = 0; i<=numberOfPinsToNotRead; i++) {
    doNotReadThisPin(pins[i]);
  }
}




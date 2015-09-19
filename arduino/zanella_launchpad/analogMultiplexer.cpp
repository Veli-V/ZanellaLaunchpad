/*
  analogMultiplexer.cpp - Library for the multiplexer chip CD74HC4067 and chip 74HC4051
  Created by Lucas Zanella, March 24, 2014.
  Released into the public domain.
  http://lucaszanella.com
*/
#include "analogMultiplexer.h"
#include "Arduino.h"

//If you want to use this class alone for other projects, here's the definitions that are already included by definition.h (not a part of this class)
//Check the analogMultiplexer class here: ADDRESS_HERE
//#define chipCD74HC4067 1 //this is just a number to identify the sparkfun board
//#define chipCD74HC4067_KEYSIZE 16
//#define chip74HC4051 2 //this number identifies the other board 74HC4051
//#define chip74HC4051_KEYSIZE 8


int pins_chip74HC4051[3];
int _analogPin;
int _numberOfControlPins;
int _boardType;

#if defined (chip74HC4051)
  bool pinsToNotReadFromCD74HC4067[chip74HC4051_KEYSIZE];
#endif

analogMultiplexer::analogMultiplexer() {
  
}

void analogMultiplexer::Begin(int analogPin, int pinage[], int numberOfControlPins, int boardType) {
  //delay(1000); //DEBUG
  _analogPin = analogPin;
  _numberOfControlPins = numberOfControlPins;
  _boardType = boardType;
  Serial.println("number of pins :"+String(_numberOfControlPins));//DEBUG
  //Declares the pins that will control the S0, S1, S2, S3, ... pins of the board, as output 
  for (int h=0; h<_numberOfControlPins; h++) {
    pinMode(pinage[h], OUTPUT);
    //Serial.println("pin: "+String(pinage[h])+" OUTPUT");//DEBUG
  }
  
  #if defined (chipCD74HC4067)
    pins_chipCD74HC4067[0] = pinage[0];
    pins_chipCD74HC4067[1] = pinage[1];
    pins_chipCD74HC4067[2] = pinage[2];
    pins_chipCD74HC4067[3] = pinage[3];
    numberOfPins = chipCD74HC4067_KEYSIZE;
  #endif
  
  #if defined (chip74HC4051)
    pins_chip74HC4051[0] = pinage[0];
    pins_chip74HC4051[1] = pinage[1];
    pins_chip74HC4051[2] = pinage[2];
    numberOfPins = chip74HC4051_KEYSIZE;
  #endif
}

int analogMultiplexer::Read(int pin, int type) {//The method that reads a specific analog input of the board. For example Read(3) will read the fourth port (the port named 3, counting from 0 to 3).
   #if defined (chipCD74HC4067)
     if (type==chipCD74HC4067){
      for (int k=0; k<_numberOfControlPins; k++) {
        digitalWrite(pins_chipCD74HC4067[k], bitRead(pin, k));
        //Serial.println("dW(pin: "+String(pins_chipCD74HC4067[k])+","+String(bitRead(pin, k))+")");//DEBUG
      }
     return analogRead(_analogPin);
     }
   #endif
   
   #if defined (chip74HC4051)
    if (type==chip74HC4051){//even if there's minor difference between these two boards, i prefer to write a separate case for each one, because other boards may be a lot different
      Serial.println("startshere");//DEBUG
      for (int k=0; k<_numberOfControlPins; k++) {
        digitalWrite(pins_chip74HC4051[k], bitRead(pin, k));
        //Serial.println("diditalWrite(pin: "+String(pins_chip74HC4051[k])+","+String(bitRead(pin, k))+")");//DEBUG
      }
      return analogRead(_analogPin);
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




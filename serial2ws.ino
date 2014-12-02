///////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2012-2014 Tavendo GmbH
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

const int ledPin = 3;
const int ledPin2 = 13;
const int pot1Pin = 0;
const int pot2Pin = 1;

const int minVal = 0;
const int maxVal = 400;

int last1 = 0;
int last2 = 0;

HardwareSerial *port;


void setup() {

// We need to use different serial ports on different Arduinos
//
// See:
//   - Arduino/hardware/tools/avr/avr/include/avr/io.h
//   - http://electronics4dogs.blogspot.de/2011/01/arduino-predefined-constants.html
//
#ifdef __AVR_ATmega32U4__
   port = &Serial1; // Arduino Yun
#else
   port = &Serial;  // Arduino Mega and others
#endif

   port->begin(9600);

   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, LOW);
   pinMode(ledPin2, OUTPUT);
   digitalWrite(ledPin2, LOW);
}


void loop() {

   // control LED via commands read from serial
   if (port->available()) {
      int inByte = port->read();
      if (inByte == '0') {
         digitalWrite(ledPin, LOW);
      } else if (inByte == '1') {
         digitalWrite(ledPin, HIGH);
      }else if (inByte == '3') {
         digitalWrite(ledPin2, HIGH);
      }else if (inByte == '4') {
         digitalWrite(ledPin2, HIGH);
      }
   }
   // limit update frequency to 50Hz
   delay(20);
}

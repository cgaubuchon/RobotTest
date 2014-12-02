#include <Servo.h>

const int ledPin = 13;
Servo servo1; // Create a servo object
Servo servo2; // Create a servo object
Servo servo3; // Create a servo object

HardwareSerial *port;


void setup() {

   servo1.attach(9); // Attaches the servo on Pin 5
   servo2.attach(10); // Attaches the servo on Pin 6
   servo3.attach(11);

   #ifdef __AVR_ATmega32U4__
      port = &Serial1; // Arduino Yun
   #else
      port = &Serial;  // Arduino Mega and others
   #endif

   port->begin(9600);

   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, LOW);

   //Reset Servo positions
   servo1.write(0);
   servo2.write(0);
   servo3.write(0);

}


void loop() {

   if (port->available()) {
      int inByte = port->read();

      if (inByte == '0') {
         digitalWrite(ledPin, HIGH);
         servo1.write(140);
         servo2.write(180);
         servo3.write(90);
         digitalWrite(ledPin, LOW);
      } else if (inByte == '1') {
         digitalWrite(ledPin, HIGH);
         servo1.write(10);
         servo2.write(20);
         servo3.write(10);
         digitalWrite(ledPin, LOW);
      }else if (inByte == '2') {
         digitalWrite(ledPin, HIGH);
         servo1.write(30);
         servo2.write(10);
         servo3.write(30);
         digitalWrite(ledPin, LOW);
      }else if (inByte == '3') {
         digitalWrite(ledPin, HIGH);
         servo1.write(80);
         servo2.write(80);
         servo3.write(10);
         digitalWrite(ledPin, LOW);
      }
   }

   // limit update frequency to 50Hz
   delay(20);
}

const int ledPin = 3;

HardwareSerial *port;


void setup() {

#ifdef __AVR_ATmega32U4__
   port = &Serial1; // Arduino Yun
#else
   port = &Serial;  // Arduino Mega and others
#endif

   port->begin(9600);

   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, LOW);
}


void loop() {

   if (port->available()) {
      int inByte = port->read();

      if (inByte == '0') {
         digitalWrite(ledPin, LOW);
      } else if (inByte == '1') {
         digitalWrite(ledPin, HIGH);
      }else if (inByte == '3') {
         digitalWrite(ledPin, HIGH);
      }else if (inByte == '4') {
         digitalWrite(ledPin, LOW);
      }
   }

   // limit update frequency to 50Hz
   delay(20);
}

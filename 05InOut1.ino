#include <Servo.h>

// kita buat variabel untuk nomor pin supaya lebih mudah merujuknya
Servo myservo;        // buat object servo
int inPin = 2;        // pushbutton connected to digital pin 7 from RF

// variabel untuk menyimpan nilai input pin button
int nilaiButton = 0;
int pos = 0;          // variable to store the servo position

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // sets the LED board as output
  pinMode(inPin, INPUT);    // sets the digital pin 7 as input
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // baca nilai pin untuk button
  nilaiButton = digitalRead(inPin);
  digitalWrite(LED_BUILTIN, nilaiButton);  // sets the LED to the button's value
  // Serial.println(nilaiButton);           // debug status button
  if (nilaiButton == 0) {
    for (pos = 0; pos <= 45; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 45; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
  }
}

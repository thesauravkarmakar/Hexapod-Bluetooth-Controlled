#include <SoftwareSerial.h>
#include <Servo.h>

Servo middle;
Servo front;
Servo rear:

void setup() {
  Serial.begin (9600);
  middle.attach();
  rear.attach();
  front.attach();

  rear.write(90);
  front.write(90);
  middle.write(90);
  delay(2000);
}

void loop() {
  front.write(90);
  middle.write(90);
  rear.write(90);
  delay(100);
}

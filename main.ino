#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(12,13);

Servo middle;
Servo front;
Servo rear;
char currstatus;


void setup() {
  Serial.begin(9600);
  BT.begin (9600);

  middle.attach(10);
  rear.attach(9);
  front.attach(11);

  rear.write(90);
  front.write(90);
  middle.write(90);
  delay(2000);
  currstatus = 's';
}

void forward(){ //Forward Motion of Hexapod
  middle.write(120);
  delay(500);
  front.write(60);
  rear.write(60);
  delay(500);
  middle.write(90);
  delay(500);
  middle.write(60);
  delay(500);
  front.write(90);
  rear.write(90);
  delay(500);
  middle.write(90);
  delay(500);
}

void backward(){ // Backward Motion of Hexapod
  middle.write(120);
  delay(500);
  front.write(120);
  rear.write(120);
  delay(500);
  middle.write(90);
  delay(500);
  middle.write(60);
  delay(500);
  front.write(90);
  rear.write(90);
  delay(500);
  middle.write(90);
  delay(500);
  }

 void stop() { //Stop Motion of Hexapod
  front.write(90);
  middle.write(90);
  rear.write(90);
  delay(500);
 }

  
void loop() {//Interfacing 
  while(BT.available())
  {
    currstatus=BT.read();
    Serial.println(String(currstatus));
  }
   if(currstatus=='w')
  {
    forward();
   }
   if(currstatus=='b')
   {
    backward();
   }
  if(currstatus=='s')
  {
    stop();
  }
}

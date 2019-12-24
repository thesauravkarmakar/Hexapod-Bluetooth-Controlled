#include <Servo.h>

Servo front; //Change 'front' to rear,middle accordingly when setting 

void setup() {

 front.attach(11);
 front.write(90);
 delay(1000);
}

void loop() {

}

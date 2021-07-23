#include <Servo.h>
Servo myServo;
const int button = 5;
int state = 0;

void setup() {
  myServo.attach(9);
  myServo.write(0);
  pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button) > 0){
    state = 1 - state;
  }
  if(state == 1) {
     myServo.write(90);
    delay(100);
  }
  else {
    myServo.write(0);
    delay(100);
  }
  delay(1);
}

#include <Servo.h>
int pin_1 = 13;//left motor
int pin_2 = 8;

int pin_3 = 12;//right motor
int pin_4 = 11;
int Servo_pin1 = 10;//verticalServo
int Servo_pin2 = 9;//horizontalServo
int position_1 = 0;
Servo gripper_motor_1;
Servo gripper_motor_2;


int delayTime = 700;

//for Joystick and related stuff
const int inX = A0; // analog input for x-axis
const int inY = A1; // analog input for y-axis
const int inPressed = 2; // input for detecting whether the joystick/button is pressed

int xValue = 0; // variable to store x value
int yValue = 0; // variable to store y value
int notPressed = 0; // variable to store the button's state => 1 if not pressed



void setup() {
  
  pinMode(pin_1,OUTPUT);
  pinMode(pin_2,OUTPUT);
  pinMode(pin_3,OUTPUT);
  pinMode(pin_4,OUTPUT);
  gripper_motor_1.attach(Servo_pin1);
  gripper_motor_2.attach(Servo_pin2);
  
    pinMode(7, INPUT_PULLUP); //set pin 7 as an input and enable the internal pull-up resistor
  Serial.begin(9600);

//Setup for Joycon and its inbuilt switch
  pinMode(inX, INPUT); // setup x input
  pinMode(inY, INPUT); // setup y input
  pinMode(inPressed, INPUT_PULLUP); // we use a pullup-resistor for the button functionality
  
}

void loop() {
  //DC Motor 1
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);
  delay(delayTime); 
  
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, HIGH);
  delay(delayTime);
  
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, HIGH);
  delay(delayTime);
  
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  delay(delayTime); 
  
  //DC Motor 2
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, HIGH);
  delay(delayTime);
  
  digitalWrite(pin_3, HIGH);
  digitalWrite(pin_4, HIGH);
  delay(delayTime);
  
  digitalWrite(pin_3, HIGH);
  digitalWrite(pin_4, LOW);
  delay(delayTime);
  
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
  delay(delayTime);
  
  //Servo 1
  for (position_1 = 0; position_1 <= 180; position_1 += 90) { 
    gripper_motor_1.write(position_1);              
    delay(delayTime);                       
  }
  for (position_1 = 180; position_1 >= 0; position_1 -= 90) { 
    gripper_motor_1.write(position_1);              
    delay(delayTime);                      
  }
  //Servo 2
  for (position_1 = 0; position_1 <= 180; position_1 += 90) { 
    gripper_motor_2.write(position_1);              
    delay(delayTime);                       
  }
  for (position_1 = 180; position_1 >= 0; position_1 -= 90) { 
    gripper_motor_2.write(position_1);              
    delay(delayTime);                      
  }
  
}

#include <Servo.h>
int pin_1 = 13;//left motor forward
int pin_2 = 8;//left motor backward

int pin_3 = 12;//right motor forward
int pin_4 = 11;//right motor backward

int Servo_pin1 = 10;//verticalServo
int Servo_pin2 = 9;//horizontalServo
int position_1 = 0;
Servo gripper_motor_1;
Servo gripper_motor_2;


int delayTime = 700;

//for Joystick and related stuff
//JoyCon1
const int inX = A0; // analog input for x-axis
const int inY = A1; // analog input for y-axis
const int inPressed = 2; // input for detecting whether the joystick/button is pressed
int xValue = 0; // variable to store x value
int yValue = 0; // variable to store y value
int notPressed = 0; // variable to store the button's state => 1 if not pressed

//JoyCon2
const int inX2 = A3; // analog input for x-axis
const int inY2 = A4; // analog input for y-axis
const int inPressed2 = 3; // input for detecting whether the joystick/button is pressed
int xValue2 = 0; // variable to store x value
int yValue2 = 0; // variable to store y value
int notPressed2 = 0; // variable to store the button's state => 1 if not pressed

void forward()
{
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, HIGH);
  digitalWrite(pin_4, LOW);
 
}
void backward()
{
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, HIGH);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, HIGH);
 
}
void rightTurn()
{
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);      //MAKING LEFT MOTORS WORK TO TURN RIGHT
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
 
}
void leftTurn()
{
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);      //MAKING RIGHT MOTORS WORK TO TURN LEFT
  digitalWrite(pin_3, HIGH);
  digitalWrite(pin_4, LOW);
 
}


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
  pinMode(inX2, INPUT); // setup x input
  pinMode(inY2, INPUT); // setup y input
  pinMode(inPressed2, INPUT_PULLUP); // we use a pullup-resistor for the button functionality
  //wE COULD USE THIS BUTTON FOR STARTING THE DC MOTOR FOR CLIMBER
}

void loop() {
  //DC Motor 1
    if(inX>800)
    {
      forward();
    }
    else if(inX<100)
    {
      backward();
    }
  
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



#include <Servo.h>
int pin_1 = 8;//left motor forward
int pin_2 = 9;//left motor backward
int Yval;
int Xval;
int Yval2;
int Xval2;
int pin_3 = 10;//right motor forward
int pin_4 = 11;//right motor backward

int Servo_pin1 = 2;//verticalServo
int Servo_pin2 = 3;//horizontalServo
int position_1 = 45;
Servo gripper_motor_1;
Servo gripper_motor_2;


int delayTime = 700;

//for Joystick and related stuff
//JoyCon1
const int inX = A0; // analog input for x-axis
const int inY = A1; // analog input for y-axis
const int inPressed = 7; // input for detecting whether the joystick/button is pressed
int xValue = 506; // variable to store x value
int yValue = 506; // variable to store y value
int notPressed = 0; // variable to store the button's state => 1 if not pressed

//JoyCon2
const int inX2 = A4; // analog input for x-axis
const int inY2 = A5; // analog input for y-axis
const int inPressed2 = 6; // input for detecting whether the joystick/button is pressed
int xValue2 = 506; // variable to store x value
int yValue2 = 506; // variable to store y value
int notPressed2 = 0; // variable to store the button's state => 1 if not pressed

void forward()
{
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, HIGH);
  digitalWrite(pin_4, LOW);

}
void stopmot()
{
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
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
  digitalWrite(pin_1, 0);
  digitalWrite(pin_2, 1);      //MAKING LEFT MOTORS WORK TO TURN RIGHT
  digitalWrite(pin_3, 1);
  digitalWrite(pin_4, LOW);

}
void leftTurn()
{
  digitalWrite(pin_1, 1);
  digitalWrite(pin_2, LOW);      //MAKING RIGHT MOTORS WORK TO TURN LEFT
  digitalWrite(pin_3, 0);
  digitalWrite(pin_4, 1);

}


void setup() {
  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, OUTPUT);
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
  //need to discuss this partttttttt
  Yval2 = analogRead(inY2);
  Xval2 = analogRead(inX2);
  Yval = analogRead(inY);
  Xval = analogRead(inX);
  Serial.print("X: ");
  Serial.print(Xval);
  Serial.print(" ");
  Serial.print("Y: ");
  Serial.println(Yval);
  if (Yval > 800 || Yval < 100 || Xval > 800 || Xval < 100)
  {
    if (Yval > 800) //JoyCon1
    {
      forward();
      Serial.println("Forward.");

    }
    else if (Yval < 100)
    {
      backward();
      Serial.println("Backward.");
    }
    if (Xval > 800 && (Yval > 100 && Yval < 800))
    {
      rightTurn();
      Serial.println("Right Turn");
    }
    else if (Xval < 100 && (Yval > 100 && Yval < 800))
    {
      leftTurn();
      Serial.println("Left Turn");
    }
  }
  else
  {
    stopmot();
    Serial.println("Stopped");
  }

  if (Xval2 > 800)    //Joycon2 for Servo
  {
    //Servo1 Pos1
    Serial.println("Servo1 moved.");
    gripper_motor_1.write(45);
    delay(delayTime);
  }
  else if (Xval2 < 100)
  {
    //Servo1 Pos 0
  }

  if (Yval2 > 800)
  {
    //Servo2 Pos1
    Serial.println("Servo2 moved.");
    gripper_motor_2.write(45);
    delay(delayTime);
  }
  else if (Yval2 < 100)
  {
    //Servo2 Pos0
  }

  /*if (inPressed == 0 && inPressed2 == 0)
    {
    //ropeclimber not Working
    }
    else if (inPressed == 1 && inPressed2 == 0)
    {
    //ropeclimbs upppp
    }
    else if (inPressed == 1 && inPressed2 == 1)
    {
    //ropeclimbs down
    }*/

  //Servo 1

  /*gripper_motor_1.write(45);
    delay(delayTime);


    //Servo 2

    gripper_motor_2.write(45);
    delay(delayTime);*/



}

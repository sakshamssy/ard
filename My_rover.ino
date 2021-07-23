//int ENA = 9;
//int ENB = 10;
int IN1 = 8;//Right motor
int IN2 = 9;//Right motor
int IN3 = 5;//Left motor
int IN4 = 4;//Left motor

//void setspeed(int s){
  //analogWrite(ENA, s);
  //analogWrite(ENB, s);
//}
void Stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void rightturn(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void leftturn(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void setup()
{
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


  void loop() {
while(Serial.available()>0){
  data= Serial.read();
  Serial.println(c);
  if (data=='a'){
  Serial.println("forward");
  forward();
  }
  else if (data=='b'){
  Serial.println("reverse");
  back();
  } 
  else if (data=='c'){
  Serial.println("right");
  rightturn();
  }
  else if(data=='d')
  {
    Serial.println("left turn");
    
  }
}
  setspeed(200);
  switch(select){
    case 1 : forward(); delay(1000); break;
    case 2 : back(); delay(1000); break;
    case 3 : leftturn(); delay(1000); break;
    case 4 : rightturn(); delay(1000); break;
    case 5 : Stop(); delay(1000); break;
  }
}

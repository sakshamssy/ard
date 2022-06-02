

unsigned int previousMillis = 0;
unsigned int interval = 2000;
#define GC A0
void setup() {

pinMode(GC,INPUT);

digitalWrite(GC,HIGH);
}

void loop() {
if ( GC==HIGH)
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    digitalWrite(A0,LOW);
  }

}
}
  

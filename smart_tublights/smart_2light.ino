int tb1 = 3;
int tb2 = 6;
void setup()
{
  Serial.begin(9600);
  pinMode(tb1,OUTPUT);
  pinMode(tb2,OUTPUT);
}

void loop()
{
  unsigned int AnalogValue;
  AnalogValue = analogRead(0);
  Serial.println(AnalogValue);  
  if (AnalogValue<180){
    digitalWrite(tb1,LOW);
    digitalWrite(tb2,LOW);
  }
  else if(AnalogValue>=180 and AnalogValue<=240){
    digitalWrite(tb1,HIGH);
    digitalWrite(tb2,LOW);
    delay(2000);
  }
  else{
    digitalWrite(tb1,HIGH);
    digitalWrite(tb2,HIGH);
    delay(2000);
  }
}

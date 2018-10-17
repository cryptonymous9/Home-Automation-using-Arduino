int tb1 = 3;
int tb2 = 6;
int pir = 30;
int val;
char sleep = 's';
char awake='a';
char term ;
int value=1;
void setup(){
  Serial1.begin(9600);
  pinMode(tb1,OUTPUT);
  pinMode(tb2,OUTPUT);
  pinMode(pir,INPUT);
}

void loop(){
  if (Serial1.available()){
    term = Serial1.read();
    if (term==sleep){
      value=0;
    }
    else if(term==awake){
      value=1;
    }
  }
  if(value==1){
    val = digitalRead(pir);
    if (val==HIGH){
      unsigned int AnalogValue;
      AnalogValue = analogRead(0);
      Serial1.println(AnalogValue);  
      if (AnalogValue<180){
        digitalWrite(tb1,LOW);
        digitalWrite(tb2,LOW);
      }
      else if(AnalogValue>=180 and AnalogValue<=240){
        digitalWrite(tb1,HIGH);
        digitalWrite(tb2,LOW);
      }
      else{
        digitalWrite(tb1,HIGH);
        digitalWrite(tb2,HIGH);
      } 
    }
  }
  
}

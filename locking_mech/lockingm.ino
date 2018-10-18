char password = 'a';
char terminal;
void setup() 
{
pinMode(9, OUTPUT);
Serial1.begin(9600);
digitalWrite(9, HIGH);  //By default, lock is active(locked)


}

void loop() {
  if(Serial1.available()>0) 
  {terminal = Serial1.read();
  Serial1.println(terminal);
  if(terminal == password){
  digitalWrite(9,LOW);
  Serial1.println("open");
  }
  }

}

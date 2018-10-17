int lock = 9;          //pin 9 on Arduino
char final;         //Characters the Arduino will receive
char correct ='A';    //User-Defined Password
int pass_correct = 0;          //Does Password match, 0=false 1=true

void setup()
{
pinMode(lock, OUTPUT);
Serial1.begin(9600);
digitalWrite(lock, HIGH);  //By default, lock is active(locked)
}

void loop()
{
while(Serial1.available()) 
{
  //for(int i=0; i<4; i++)   //While data is available read 4 bytes
  //{
   final = Serial1.read();  //Read 4 bytes into the array labled "final"
  //}

 // for(int i=0; i<4; i++)
  //{
   if(final==correct) //Compare each char received to each car in our password in order
   {
    pass_correct = 1;   //If we compare two chars and they match, set the pass_correct variable to true(1)
   }
   else
   {
    pass_correct = 0;  //if the two compared chars do NOT match, set pass_correct variable to false(0)
    break;   //End loop and stop comparing chars
   }
  //}
}

if(pass_correct==1)  //If all chars compared match, deactivate(unlock) the lock for 5 seconds
{
  Serial1.println("Unlocked");
  digitalWrite(lock, LOW);
  delay(5000);
  Serial1.println("Locked");
  pass_correct = 0;
}
else
{
digitalWrite(lock, HIGH); //Else if there was not a complete match, keep the lock high(locked)
}
}

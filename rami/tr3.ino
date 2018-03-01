
// a traffic light circuit which red and green lights for 5 seconds each and the yellow flashes 3 times and easily adjusted through variables 

int red=6;
int yellow=5;
int green=4;
int timeon=5000;
int flash=500;
int noflash=3;


void setup() {
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
}


void loop() { 
digitalWrite(green,HIGH);
delay(timeon);
digitalWrite(green,LOW);
for (int i = 1 ; i<=noflash ; i=i+1 )
{
  digitalWrite(yellow,HIGH);
  delay(flash);
  digitalWrite(yellow,LOW);
  delay(flash);
}
digitalWrite(red,HIGH);
delay(timeon);
digitalWrite(red,LOW);
}

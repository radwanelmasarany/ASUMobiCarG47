//   red 30 sec green 30 sec   yellow  5flashing 10 sec
const int red = 11  ;
const int green = 12 ;
const int yellow = 13 ;
int i =0;
void setup() {
  pinMode(red,OUTPUT);
   pinMode(green,OUTPUT);
    pinMode(yellow,OUTPUT);

}

void loop() {
digitalWrite(red,HIGH);
delay(30000);
digitalWrite(red,LOW);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(green,LOW);
for(i=0;i<=5;i++)
{digitalWrite(yellow,HIGH);
delay(1000);
digitalWrite(yellow,LOW);
delay(1000);}

}

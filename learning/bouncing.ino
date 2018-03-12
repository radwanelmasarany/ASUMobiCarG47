int led1=4;
int led2=5;
int led3=6;
int led4=7;
int bouncetime=1000;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() {
 
for(int i=4 ; i<=7 ; i++)
{
digitalWrite(i,HIGH);
delay(bouncetime);
digitalWrite(i,LOW);
} 
for(int j=7; j>=4 ; j--)
{
digitalWrite(j,HIGH);  
delay(bouncetime);
digitalWrite(j,LOW);
}
}

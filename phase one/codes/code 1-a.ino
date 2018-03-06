#include <Servo.h>
Servo servof;
int trig =20;
int echo=21;
float duration;
int distance;

int calcdistance()
{ //function to calculate distance
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance= duration*0.034/2;
  return distance;
  }

void setup() {
Serial.begin(9600);
servof.attach(12);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

} 

void loop() {
  digitalWrite(3, LOW);
  digitalWrite(2,HIGH);
for(int i=0;i<=180;i+=30)
{// moving servo every 30 degree to make ultrasonic 
  // from 0 degree to 180
  servof.write(i);
  distance=calcdistance();
 Serial.print(distance); //print the value 
  delay(50); 
  }
for (int i=180;i>=0;i-=30)
{
  // moving servo every 30 degree to make ultrasonic 
  // from 180 degree to 0
  servof.write(i);
  distance=calcdistance();
 Serial.print(distance);
 delay(50);
   }
  

}

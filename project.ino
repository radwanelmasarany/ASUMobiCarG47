#include <Servo.h>
#define trigpin 5
#define echopin 6
Servo myservo;
  int duration, distance;
  
void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
 
  pinMode(echopin, INPUT);
  myservo.attach(2);
myservo.writeMicroseconds(1500);

}
void loop() {
 myservo.write(90);
 digitalWrite(trigpin,HIGH);
  _delay_ms(500);
  digitalWrite(trigpin, LOW);
  
  duration=pulseIn(echopin,HIGH); 
  distance=(duration/2)/29.1; 
 if(distance <=20)
 {
 myservo.write(0); 
 STOP();
 delay(600);
}
else
{
  myservo.write(90);
  delay(600);
}
  Serial.print("cm"); 
Serial.println(distance);
 
}


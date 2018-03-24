#include <Servo.h>
Servo servof;
int trig =20;
int echo=21;
float duration;
int distance;
const int M1 = 2 ;      //M1 M2 RIGHT FWD MOTOR 
const int M2 = 3 ;      // M3 M4 RIGHT BACK MOTOR 
const int M3 = 4 ;      // M5 M6 LEFT BACK MOTOR 
const int M4 = 5 ;      // M7 M8 LEFT FWD MOTOR 
const int M5 = 6 ;      // MOTOR1 IS RIGHT FWD MOTOR 
const int M6 = 7 ;      // MOTOR2 IS RIGHT BACK MOTOR 
const int M7 = 8 ;      // MOTOR3 IS LEFT BACK MOTOR 
const int M8 = 9 ;      // MOTOR4 IS LEFT FWD MOTOR
char z ;
int dist1,dist2,dist3,dist4,dist5;
int distA,distB,distC;    //to choose the bist diriction 
int SDIS=10;//safe distance
void SRVLTR(){
  //function for ultrasonic and servo
  servof.write(0);
delay(10);
dist1=calcdistance();
delay(10);
  servof.write(45);
delay(10);
dist2=calcdistance();
delay(10);
  servof.write(90);
delay(10);
dist3=calcdistance();
delay(10);
  servof.write(135);
delay(10);
dist4=calcdistance();
delay(10);
  servof.write(180);
delay(10);
dist5=calcdistance();
}
 void bistdirc(){
  //function to choose the best way
  if ( (dist1||dist2||dist3||dist4||dist5)<=SDIS){
      STOP();
    servof.write(0);
    distA=calcdistance();
    delay(20);
    servof.write(90);
    distB=calcdistance();
    delay(20);
    servof.write(180);
    distC=calcdistance();
    delay(20);
    if (distA>(distB&&distC)){
      left();
    }
    else if (distB>(distA&&distC)){
      forward();
    }
    else right();
  }
 }

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
  void forward ()
{  digitalWrite (M1,HIGH);         // MOTOR1 MOTOR2 MOTOR3 MOTOR4 ALL FWD 
   digitalWrite (M2,LOW);
   digitalWrite (M3,HIGH);
   digitalWrite (M4,LOW);
   digitalWrite (M5,HIGH);
   digitalWrite (M6,LOW);
   digitalWrite (M7,HIGH);
   digitalWrite (M8,LOW);
  
}
void backward ()
{
  digitalWrite (M1,LOW);              // MOTOR1 MOTOR2 MOTOR3 MOTOR4 ALL BAKCWARD
  digitalWrite (M2,HIGH);
  digitalWrite (M3,LOW);
  digitalWrite (M4,HIGH);
  digitalWrite (M5,LOW);
  digitalWrite (M6,HIGH);
  digitalWrite (M7,LOW);
  digitalWrite (M8,HIGH);
}
void left ()
{
  digitalWrite (M1,HIGH);            // MOTOR1 MOTOR2  FWD     MOTOR3 MOTOR4 BACKWARD
  digitalWrite (M2,LOW);
  digitalWrite (M3,HIGH);
  digitalWrite (M4,LOW);
  digitalWrite (M5,LOW);
  digitalWrite (M6,HIGH);
  digitalWrite (M7,LOW);
  digitalWrite (M8,HIGH);
}
void right ()
{
  digitalWrite (M1,LOW);               // MOTOR1 MOTOR2 BACKWARD MOTOR3 MOTOR4 FWD
  digitalWrite (M2,HIGH);
  digitalWrite (M3,LOW);
  digitalWrite (M4,HIGH);
  digitalWrite (M5,HIGH);
  digitalWrite (M6,LOW);
  digitalWrite (M7,HIGH);
  digitalWrite (M8,LOW);
}
void forwardright ()
{
  digitalWrite (M1,LOW);            //MOTOR1 OFF    MOTOR2 MOTOR3 MOTOR4 FWD 
  digitalWrite (M2,HIGH);
  digitalWrite (M3,HIGH);
  digitalWrite (M4,LOW);
  digitalWrite (M5,HIGH);
  digitalWrite (M6,LOW);
  digitalWrite (M7,HIGH);
  digitalWrite (M8,LOW);
}
void forwardleft()
{
   digitalWrite (M1,HIGH);         // MOTOR1 MOTOR2 MOTOR3 FWD MOTOR4 OFF
   digitalWrite (M2,LOW);
   digitalWrite (M3,HIGH);
   digitalWrite (M4,LOW);
   digitalWrite (M5,HIGH);
   digitalWrite (M6,LOW);
   digitalWrite (M7,LOW);
   digitalWrite (M8,HIGH);
}
void backright ()
{
   digitalWrite (M1,LOW);          //MOTOR1 BACKWARD MOTOR2 OFF MOTOR3 MOTOR4 BACKWARD 
   digitalWrite (M2,HIGH);
   digitalWrite (M3,HIGH);
   digitalWrite (M4,LOW);
   digitalWrite (M5,LOW);
   digitalWrite (M6,HIGH);
   digitalWrite (M7,LOW);
   digitalWrite (M8,HIGH);
}
void backleft()
{  
  digitalWrite (M1,LOW);          // MOTOR1 MOTOR2 BACKWARD MOTOR3 OFF MOTOR4 BACKWARD 
  digitalWrite (M2,HIGH);
  digitalWrite (M3,LOW);
  digitalWrite (M4,HIGH);
  digitalWrite (M5,HIGH);
  digitalWrite (M6,LOW);
  digitalWrite (M7,LOW);
  digitalWrite (M8,HIGH);
       
}
void STOP()
{ 
  digitalWrite (M1,LOW);
  digitalWrite (M2,LOW);
  digitalWrite (M3,LOW);
  digitalWrite (M4,LOW);
  digitalWrite (M5,LOW);
  digitalWrite (M6,LOW);
  digitalWrite (M7,LOW);
  digitalWrite (M8,LOW);
       
}

void setup() {
Serial.begin(9600);
servof.attach(12);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode (M1,OUTPUT);
pinMode (M2,OUTPUT);
pinMode (M3,OUTPUT);
pinMode (M4,OUTPUT);
pinMode (M5,OUTPUT);
pinMode (M6,OUTPUT);
pinMode (M7,OUTPUT);
pinMode (M8,OUTPUT);

} 

void loop() {
  digitalWrite(3, LOW);
  digitalWrite(2,HIGH);

  if(Serial.available())
         {;}
    z=Serial.read();
   if(z=='F')
     {forward();}
    else if(z=='B')
     {backward();}
    else if(z=='R')
     {right();}
    else if(z=='L')
     {left();}
    else if(z=='G')
     {forwardleft();}
    else if(z=='I')
      {forwardright();}
    else if(z=='H')
       {backleft();}
    else if(z=='J')
        {backright();}
    else if(z=='S')
        {STOP();} 

     SRVLTR();
     bistdirc();

}

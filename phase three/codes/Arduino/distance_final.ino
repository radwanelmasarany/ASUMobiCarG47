

int i;
int redpin=0;
const int M1 = 2 ;      //M1 M2 RIGHT FWD MOTOR 
const int M2 = 3 ;      // M3 M4 RIGHT BACK MOTOR 
const int M3 = 4 ;      // M5 M6 LEFT BACK MOTOR 
const int M4 = 5 ;      // M7 M8 LEFT FWD MOTOR 
const int M5 = 6 ;      // MOTOR1 IS RIGHT FWD MOTOR 
const int M6 = 7 ;      // MOTOR2 IS RIGHT BACK MOTOR 
const int M7 = 8 ;      // MOTOR3 IS LEFT BACK MOTOR 
const int M8 = 9 ;      // MOTOR4 IS LEFT FWD MOTOR
char z ;
int Delay = ;     //variable calculated from practical measurement     
void setup() {
 pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode (M1,OUTPUT);
pinMode (M2,OUTPUT);
pinMode (M3,OUTPUT);
pinMode (M4,OUTPUT);
pinMode (M5,OUTPUT);
pinMode (M6,OUTPUT);
pinMode (M7,OUTPUT);
pinMode (M8,OUTPUT);

 
  
    pinMode(redpin,OUTPUT);
    Serial.begin(9600);
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
void loop() {
   digitalWrite(3, LOW);
  digitalWrite(2,HIGH);

  if(Serial.available()>0)
  {
    z=Serial.read();
   if(z=='F')
     {
      for(i=0;i<Delay;i=i+10)
     {
      forward();
      delay(10);}
     STOP();
     }
    else if(z=='B')
     {
      for(i=0;i<Delay;i=i+10)
     { 
      backward();
       delay(10);}
       STOP();
     }
   
  }
}

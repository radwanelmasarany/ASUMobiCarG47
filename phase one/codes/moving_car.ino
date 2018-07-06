const int M1=2;
const int M2=3;
const int M3=4;
const int M4=5;
const int inspd1=10;
char z;


void setup() {

pinMode (M1,OUTPUT);
  pinMode (M2,OUTPUT);
  pinMode (M3,OUTPUT);
  pinMode (M4,OUTPUT);
   pinMode(inspd1,OUTPUT);
  Serial.begin(9600);
}
void forward ()
{  digitalWrite (M1,HIGH);         // MOTOR1 MOTOR2  ALL FWD 
   digitalWrite (M2,LOW);
   digitalWrite (M3,HIGH);
   digitalWrite (M4,LOW);
  
}
void backward ()
{
  digitalWrite (M1,LOW);              // MOTOR1 MOTOR2 ALL BAKCWARD
  digitalWrite (M2,HIGH);
  digitalWrite (M3,LOW);
  digitalWrite (M4,HIGH);
  
}
void left ()
{
  digitalWrite (M1,HIGH);            // MOTOR1  FWD     MOTOR3  BACKWARD
  digitalWrite (M2,LOW);
  digitalWrite (M3,LOW);
  digitalWrite (M4,HIGH);
}
void right ()
{
  digitalWrite (M1,LOW);               // MOTOR1 BACKWARD MOTOR3 FWD
  digitalWrite (M2,HIGH);
  digitalWrite (M3,HIGH);
  digitalWrite (M4,LOW);
  }
void STOP()
{ 
  digitalWrite (M1,LOW);
  digitalWrite (M2,LOW);
  digitalWrite (M3,LOW);
  digitalWrite (M4,LOW);
       
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
  
  z=Serial.read();

     if(z=='F')
     {forward();}
     else if(z=='B')
     {backward();}
     else if(z=='R')
     {right();}
     else if(z=='L')
     {left();}
      else if(z=='S')
        {STOP();}   

}




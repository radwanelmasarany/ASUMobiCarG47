const int M1=3;
const int M2=4;
const int M3=5;
const int M4=6;
//definr sensers
#define LEFT_SENSOR (30)
#define MID_SENSOR (42)
#define RIGHT_SENSOR (36)

int SPEED=220;
char DATA='0';
char STATE='W';
char MOVE='S';
//for switch between two modes
void CONTROL (char motion);
void FOLLOW ();
//function for movinh
void forward();
void backward();
void STOP();
void left();
void right();

void setup() {
 Serial.begin(9600);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  pinMode(LEFT_SENSOR,INPUT);
  pinMode(MID_SENSOR,INPUT);
  pinMode(RIGHT_SENSOR,INPUT);
  
}
int LS,MS,RS;
void loop() {
  
       int LS=digitalRead(LEFT_SENSOR);
       int RS=digitalRead(RIGHT_SENSOR);
       int MS=digitalRead(MID_SENSOR);

    if(Serial.available()>0)
    {
      DATA=Serial.read();

        if (DATA=='W' || DATA=='w')
          {
              STATE=DATA;  
          }
          if(DATA=='F'||DATA=='B'||DATA=='R'||DATA=='L'||DATA=='S')
                 {
                  MOVE=DATA;
                 }
    }
     if(STATE=='w')
                 { 
                    
                    FOLLOW();
                    Serial.println('L');
                 }
                 else
                 {
                   CONTROL(MOVE);
                 }
}
void forward ()
{

  digitalWrite (M1, HIGH);        // MOTOR1 MOTOR2 MOTOR3 MOTOR4 ALL FWD
  digitalWrite (M2, LOW);
  digitalWrite (M3, HIGH);
  digitalWrite (M4, LOW);

}
void left ()
{
  digitalWrite (M1, HIGH);           // MOTOR1 MOTOR2  FWD     MOTOR3 MOTOR4 BACKWARD
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M4, HIGH);
}
void right ()
{
  digitalWrite (M1, LOW);              // MOTOR1 MOTOR2 BACKWARD MOTOR3 MOTOR4 FWD
  digitalWrite (M2, HIGH);
  digitalWrite (M3, HIGH);
  digitalWrite (M4, LOW);
}
void backward ()
{
  digitalWrite (M1, LOW);             // MOTOR1 MOTOR2 MOTOR3 MOTOR4 ALL BAKCWARD
  digitalWrite (M2, HIGH);
  digitalWrite (M3, LOW);
  digitalWrite (M4, HIGH);

}
void STOP()
{
  digitalWrite (M1, LOW);
  digitalWrite (M2, LOW);
  digitalWrite (M3, LOW);
  digitalWrite (M4, LOW);

}
void CONTROL (char motion){
  if(motion=='F')
  {
    forward();
  }
  if(motion=='B')
  {
    backward();
  }
  if(motion=='L')
  {
    left();
  }
  if(motion=='R')
  {
    right();
  }
  if(motion=='S')
  {
    STOP();
  }
}
void FOLLOW ()
{
  if((LS==HIGH&&(RS==LOW)&&MS==HIGH))
  {
      left();
     while(MS==HIGH&&RS==LOW)
     {
      Serial.println("left to medium");
      left();
        LS=digitalRead(LEFT_SENSOR);
        RS=digitalRead(RIGHT_SENSOR);
        MS=digitalRead(MID_SENSOR);
     }
           Serial.println("forward");

      forward();
  }
  else if((LS==LOW&&(RS==HIGH)&&MS==HIGH))
  {
     right();
     while(LS==LOW&&MS==HIGH)
     {
            Serial.println("right to medium");

      right();
     LS=digitalRead(LEFT_SENSOR);
        RS=digitalRead(RIGHT_SENSOR);
        MS=digitalRead(MID_SENSOR);
     }
                Serial.println("forward");

     forward();
  }
  else if(LS==LOW&&RS==HIGH&&MS==LOW)
  {
    right();
     while(LS==LOW&&RS==HIGH)
     {
                  Serial.println("right to l");

      right();
      LS=digitalRead(LEFT_SENSOR);
        RS=digitalRead(RIGHT_SENSOR);
        MS=digitalRead(MID_SENSOR);
     }
     forward(); 
                     Serial.println("forward");

  }
  else if(LS==HIGH&&RS==LOW&&MS==LOW)
  {
     left();
     while(RS==LOW&&LS==HIGH)
     {
                      Serial.println("left to r");

      left();
      LS=digitalRead(LEFT_SENSOR);
        RS=digitalRead(RIGHT_SENSOR);
        MS=digitalRead(MID_SENSOR);
     }
      forward();
                      Serial.println("forward");

  }
  else{
    forward();
                    Serial.println("forward");

    }

}


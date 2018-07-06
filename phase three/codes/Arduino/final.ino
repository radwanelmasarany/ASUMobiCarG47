/*
this code for moving car using two motors and variable inpt voltage 
this code include phase one,two and three

*/

/*
motor1 refers to two motors in right hand and motor2 refers to two motors in left hand
*/

#define MOTOR1_1 (2)
#define MOTOR1_2 (3)
#define MOTOR2_1 (5)
#define MOTOR2_2 (6)

/*
line follower sensors difinations
*/

#define LEFT_SENSOR (4)
#define MID_SENSOR (7)
#define RIGHT_SENSOR (8)
#define trig (12)
#define echo (13)

int SPEED2=255;
int SPEED1=220 ;
char DATA='0';
char STATE='W';
char MOVE='S';
char MODE;
int duration, distance ;
/*
'W' to phase one
'U' TO LINE FOLLOWER
'V' TO PHASE 3
*/

/*
for switch between moods
*/
void CONTROL( char motion);
void FOLLOW();
void SHAPES (void); 
void rect (void);
void infinite (void);
void circle (void);
void dist(void);
void angle (void );
void LENGTH (void);



int LS,MS,RS;
void backward(void);
void forward (void);
void left(void);
void right(void);
void STOP(void);
void lefti(void);
void righti(void);

void setup() {
Serial.begin(9600);
pinMode(MOTOR1_1,OUTPUT);
pinMode(MOTOR1_2,OUTPUT);
pinMode(MOTOR2_1,OUTPUT);
pinMode(MOTOR2_2,OUTPUT);
pinMode(LEFT_SENSOR,INPUT);
pinMode(MID_SENSOR,INPUT);
pinMode(RIGHT_SENSOR,INPUT);
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);

}

void loop() {

       int LS=digitalRead(LEFT_SENSOR);
       int RS=digitalRead(RIGHT_SENSOR);
       int MS=digitalRead(MID_SENSOR);

while (STATE=='W') {
  if (Serial.available()>0)
  {
    MODE==Serial.read();
  }
    if(STATE  =='U'||STATE=='V'){
      MODE==STATE;
      break;
    }
    DATA==Serial.available();
   CONTROL (DATA);
   LENGHT;
}

while (STATE=='U') {
if (Serial.available()>0)
  {
    MODE==Serial.read();
  }
    if(STATE  =='W'||STATE=='V'){
      MODE==STATE;
      break;
    }
    FOLLOW();
  
}

  while (STATE=='V') {
if (Serial.available()>0)
  {
    MODE==Serial.read();
  }
    if(STATE  =='W'||STATE=='U'){
      MODE==STATE;
      break;
    }
  SHAPES();
  }
  }

/*
function to moving car 
*/

void forward (void)
{
  analogWrite(MOTOR1_1,SPEED1);
  analogWrite(MOTOR1_2,0);
  analogWrite(MOTOR2_1,SPEED1);
  analogWrite(MOTOR2_2,0);
}

void backward(void)
{
  analogWrite(MOTOR1_1,0);
  analogWrite(MOTOR1_2,SPEED1);
  analogWrite(MOTOR2_1,0);
  analogWrite(MOTOR2_2,SPEED1);
}
void right(void)
{
  analogWrite(MOTOR1_1,0);
  analogWrite(MOTOR1_2,SPEED1);
  analogWrite(MOTOR2_1,SPEED1);
  analogWrite(MOTOR2_2,0);
}

void left(void)
{
  analogWrite(MOTOR1_1,SPEED1);
  analogWrite(MOTOR1_2,0);
  analogWrite(MOTOR2_1,0);
  analogWrite(MOTOR2_2,SPEED1);
}

void STOP(void)
{
   analogWrite(MOTOR1_1,0);
  analogWrite(MOTOR1_2,0);
  analogWrite(MOTOR2_1,0);
  analogWrite(MOTOR2_2,0);
}

void righti(void)
{
  analogWrite(MOTOR1_1,SPEED2);
  analogWrite(MOTOR1_2,SPEED1);
  analogWrite(MOTOR2_1,SPEED1);
  analogWrite(MOTOR2_2,SPEED2);
}

void lefti(void)
{
  analogWrite(MOTOR1_1,SPEED1);
  analogWrite(MOTOR1_2,SPEED2);
  analogWrite(MOTOR2_1,SPEED2);
  analogWrite(MOTOR2_2,SPEED1);
}

/*
code for motion car 
*/
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

/*
code for line follower 
*/

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

void LENGHT (void) {
digitalWrite(trig,HIGH);
  _delay_ms(500);
  digitalWrite(trig, LOW);
   duration=pulseIn(echo,HIGH); 
  distance=(duration/2)/29.1; 
 if(distance <=20)
 { 
 STOP();
 }
}

/*
code for making shapes of phase three
*/

void SHAPES ()
{
 dist();
 delay(2500);
 angle ();
 delay(2500);
 rect();
 delay(2500);
 circle();
 delay(2500);
 infinite();
 delay (2500);

  }
  /*
  this function to move a 20 cm as example
  */
void dist (void)

{
  forward();
  delay(400);
  STOP();
  delay(150);
  backward();
  delay(400);
  STOP();
  
}
/*
this function made to make the car rotate 50 degree
*/
void angle (void) {
  left();
  delay(130);
  STOP();
}

void rect (void) {
  forward();
  delay(1000);
  left();
  delay(250);
 forward();
 delay (1000);
  left();
  delay(250);
  forward ();
  delay(1000);
   left();
  delay(250);
  forward ();
  delay (1000);
  STOP();
}

void circle () 
{
  lefti();
  delay(650);
  }

void infinite () 
{
 lefti();
 delay(350);
 STOP();
 delay(100);
 forward();
 delay(400);
 STOP();
 delay(75);
 righti();
 delay(350);
 STOP();
 delay(90);
 forward();
 delay(400);
 STOP(); 
}


#define MOTOR1_1 (3)
#define MOTOR1_2 (4)
#define MOTOR2_1 (5)
#define MOTOR2_2 (6)

#define LEFT_SENSOR (30)
#define MID_SENSOR (42)
#define RIGHT_SENSOR (36)

int SPEED=220 ;

void forward (void);
void left(void);
void right(void);

void setup() {
  // put your setup code here, to run once:
pinMode(MOTOR1_1,OUTPUT);
pinMode(MOTOR1_2,OUTPUT);
pinMode(MOTOR2_1,OUTPUT);
pinMode(MOTOR2_2,OUTPUT);
Serial.begin(9600);
pinMode(LEFT_SENSOR,INPUT);
pinMode(RIGHT_SENSOR,INPUT);
pinMode(MID_SENSOR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
       int LS=digitalRead(LEFT_SENSOR);
       int RS=digitalRead(RIGHT_SENSOR);
       int MS=digitalRead(MID_SENSOR);
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
void forward (void)
{
  analogWrite(MOTOR1_1,SPEED);
  analogWrite(MOTOR1_2,0);
  analogWrite(MOTOR2_1,SPEED);
  analogWrite(MOTOR2_2,0);
}

void right(void)
{
  analogWrite(MOTOR1_1,0);
  analogWrite(MOTOR1_2,SPEED);
  analogWrite(MOTOR2_1,SPEED);
  analogWrite(MOTOR2_2,0);
}

void left(void)
{
  analogWrite(MOTOR1_1,SPEED);
  analogWrite(MOTOR1_2,0);
  analogWrite(MOTOR2_1,0);
  analogWrite(MOTOR2_2,SPEED);
}



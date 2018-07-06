#define MOTOR1_1 (2)
#define MOTOR1_2 (3)
#define MOTOR2_1 (5)
#define MOTOR2_2 (6)

int SPEED2=255;
int SPEED1=220 ;
void infinite (void);

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
}

void loop() {
infinite(); }


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

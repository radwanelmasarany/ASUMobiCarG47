
// motor forward right
const int m1=30;
const int m2=31; 
//motor backward right
const int m3=32;
const int m4=33;
//motor forward left
const int m5=34;
const int m6=35;
//motor backward left
const int m7=36;
const int m8=37;
//defining sensors
#define LS 2
#define MS 3
#define RS 4

void setup() {
  // put your setup code here, to run once:
pinMode (LS,INPUT);
pinMode (RS,INPUT);
pinMode (MS,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(LS)&&digitalRead(MS)&&digitalRead(RS))
{
  forward();
}
else if(!digitalRead(LS)&&digitalRead(MS)&&!digitalRead(RS))
{
  forward();
}
else if(digitalRead(LS)&&!digitalRead(MS)&&!digitalRead(RS))
{
  right();
}
else if(!digitalRead(LS)&&!digitalRead(MS)&&digitalRead(RS))
{
  left();
}
else if(digitalRead(LS)&&!digitalRead(MS)&&digitalRead(RS))
{
  STOP();
}
}
void forward(){
 digitalWrite(m1,HIGH);
 digitalWrite(m2,LOW);
 digitalWrite(m3,HIGH);
 digitalWrite(m4,LOW);
 digitalWrite(m5,HIGH);
 digitalWrite(m6,LOW);
 digitalWrite(m7,HIGH);
 digitalWrite(m8,LOW);
}
void right(){
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  digitalWrite(m5,HIGH);
  digitalWrite(m6,LOW);
  digitalWrite(m7,HIGH);
  digitalWrite(m8,LOW);
}
void left(){
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
  digitalWrite(m5,LOW);
  digitalWrite(m6,HIGH);
  digitalWrite(m7,LOW);
  digitalWrite(m8,HIGH);
}
void STOP()
{ 
  digitalWrite (m1,LOW);
  digitalWrite (m2,LOW);
  digitalWrite (m3,LOW);
  digitalWrite (m4,LOW);
  digitalWrite (m5,LOW);
  digitalWrite (m6,LOW);
  digitalWrite (m7,LOW);
  digitalWrite (m8,LOW);
       
}

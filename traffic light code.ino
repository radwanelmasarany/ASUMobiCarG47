void setup() {
  // put your setup code here, to run once:
pinMode (13,OUTPUT);
pinMode (12,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,1);
digitalWrite(12,0);
digitalWrite(11,0);
delay(3000);
digitalWrite(13,0);
digitalWrite(12,1);
digitalWrite(11,0);
delay(3000);
digitalWrite(13,0);
digitalWrite(12,0);
digitalWrite(11,1);
delay(3000);
}

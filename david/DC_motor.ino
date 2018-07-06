//Example_10_DC_Motor


int motorPin = 9 ;
int onTime = 2500 ;
int offTime = 1000 ;

void setup() {
  
pinMode(motorPin,OUTPUT);
}

void loop() {
 
analogWrite(motorPin,100);
delay(onTime);
digitalWrite(motorPin, LOW);
delay(offTime);
analogWrite(motorPin,190);
delay(onTime);
digitalWrite(motorPin, LOW);
delay(offTime);
analogWrite(motorPin,255);
delay(onTime);
digitalWrite(motorPin, LOW);
delay(offTime);
}

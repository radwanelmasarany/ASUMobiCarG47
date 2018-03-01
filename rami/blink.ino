int timeon=1500;
int timeoff=500;
int led=1;

void setup() {
pinMode(led,OUTPUT);  
}

void loop() {
  digitalWrite(led,HIGH);
  delay(timeon);
  digitalWrite(led,LOW);
  delay(timeoff);
}

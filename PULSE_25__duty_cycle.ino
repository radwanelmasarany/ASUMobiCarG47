const int PULSE = 11;
void setup()
{ 
  pinMode (PULSE,OUTPUT);
}

void loop() 
{ 
  digitalWrite (PULSE,HIGH);
  delay (500);
  digitalWrite (PULSE,LOW);
  delay (1500);
}

int del=1000; // sets a default delay time

void setup() {
  
  for (int i = 4; i<=7 ; i++) 
  {
    pinMode(i, OUTPUT); // initialize the digital pins as outputs:
  }
} 
 
 void loop() 
 {
  for (int i = 4; i<=6; i++)  
  {
    digitalWrite(i, HIGH);
    delay(del);
    digitalWrite(i, LOW);
  }
  for (int i = 7; i>=5; i--) 
  { 
    digitalWrite(i, HIGH);
    delay(del);
    digitalWrite(i, LOW);
  }
}


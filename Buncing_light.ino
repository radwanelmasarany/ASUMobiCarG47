const int LED1 = 4;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 7;

void setup()
{  
  pinMode (LED1,OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (LED3,OUTPUT);
  pinMode (LED4,OUTPUT);
}

void loop()
{   
  digitalWrite (LED1,HIGH);
  delay (1000);
  digitalWrite (LED1,LOW);
  digitalWrite (LED2,HIGH);
  delay (1000);
  digitalWrite (LED2,LOW);
  digitalWrite (LED3,HIGH);
  delay (1000);
  digitalWrite (LED3,LOW);
  digitalWrite (LED4,HIGH);
  delay (1000);
  digitalWrite (LED4,LOW);
  digitalWrite (LED3,HIGH);
  delay (1000);
  digitalWrite (LED3,LOW);
  digitalWrite (LED2,HIGH);
  delay(1000);
  digitalWrite (LED2,LOW);
  
  
}


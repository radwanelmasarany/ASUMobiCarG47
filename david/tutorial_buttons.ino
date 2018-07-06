//Example_4_On_Off_with_2_Switchs_1
// led is on & off each sec if button1 pressed & on&off each 5sec if button2 pressed


const int led = 13;
const int button1 = 2;
 const int button2 = 3;
void setup() {
  
pinMode(led,OUTPUT);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
}

void loop() {
 
  if(digitalRead(button1) ==HIGH)
 { digitalWrite(led,HIGH);
 delay(1000);
 digitalWrite(led,LOW);
  delay(1000);}
 else if (digitalRead(button2) ==HIGH)
  { digitalWrite(led,HIGH);
 delay(5000);
 digitalWrite(led,LOW);
  delay(5000);}

  
  

}

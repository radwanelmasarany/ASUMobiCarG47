
// Write embedded program that show a bouncing light between 4 LEDs connected to pins 4, 5, 6 and 7 delay 1 sec.


const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;
void setup() {
  
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
}

void loop() {
 
 
 digitalWrite(led1,HIGH);
 delay(1000);

 digitalWrite(led1,LOW);
 digitalWrite(led2,HIGH);
  delay(1000);
  
   digitalWrite(led2,LOW);
 digitalWrite(led3,HIGH);
  delay(1000);

   digitalWrite(led3,LOW);
 digitalWrite(led4,HIGH);
  delay(1000);
 
 


  
  

}

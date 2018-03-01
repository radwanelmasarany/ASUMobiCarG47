// Example_6_fading_led_light inc & dec led ligth(time of dec =2 time of inc)


const int led = 11;
int i =0;
void setup() {
  
pinMode(led,OUTPUT);

}

void loop() {

 
for(i=0;i<255;i++)
{analogWrite(led,i);
delay(10);}
for(i=255;i>0;i--)
{analogWrite(led,i);
delay(20);}
  
  

}

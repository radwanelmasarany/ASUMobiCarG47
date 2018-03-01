const int LDR = A0 ;
const int LED = 11 ;
int BRIGHTNESS ;

void setup() 
{
  pinMode (LED,OUTPUT );

}

void loop() 
{
  BRIGHTNESS = analogRead (LDR);
  BRIGHTNESS = map (BRIGHTNESS , 0 , 900, 0 ,255);
  BRIGHTNESS = constrain (BRIGHTNESS,0,255);
  analogWrite (LED , BRIGHTNESS);

}

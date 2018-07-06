// Example_7_Temprature_Sensor



const int tempsensor=A0;
float voltage ;
float temp;
int reading;

void setup() {
  Serial.begin(9600);   //VI:serial has capital'S'


}

void loop() {

reading = analogRead(tempsensor);
voltage = reading *5.0/1024 ;
Serial.print(voltage);
Serial.println("volts");
temp = (voltage-0.5)*100;
Serial.println( "temp is: ");
Serial.print(temp);    // in celisius
delay(1000);

 
  
  

}

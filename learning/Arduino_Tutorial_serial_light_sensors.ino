// Example_8_Light_Sensor_2



const int sensor=A0;
int reading;

void setup() {
  Serial.begin(9600);   //VI:serial has capital'S'


}

void loop() {

reading = analogRead(sensor);
Serial.println("analog reading is:");
Serial.print(reading);

if (reading < 10) { Serial.println(" - Dark");}
else if (reading < 200) { Serial.println(" - Dim");}
else if (reading < 500) {Serial.println(" - Light"); }
else if (reading < 800) { Serial.println(" - Bright"); }
else {Serial.println(" - Very bright"); }
 delay(1000);


}

 
  
  



void setup() {
  // put your setup code here, to run once:

int motor_right[] = {6, 9};

const int RightSensor = A0; 

const int LeftSensor = A1; 



int SensorLeft; 

int SensorRight; // This stores the value of the Right Sensor pin to use later on in the sketch

int SensorDifference; // This value is used to determine the difference between the Left and Right

void setup() {

int i; for(i = 0; i < 2; i++){ pinMode(motor_left[i], OUTPUT); pinMode(motor_right[i], OUTPUT); }

pinMode(LeftSensor, INPUT); 

pinMode(RightSensor, INPUT); 

digitalWrite(A0, HIGH); 

digitalWrite(A1, HIGH); 

Serial.begin(9600); 

Serial.println(" \nBeginning Light Seeking Behavior"); 
}



void loop() {

SensorLeft = 1023 - analogRead(LeftSensor); 

SensorRight = 1023 - analogRead(RightSensor); 

SensorDifference = abs(SensorLeft - SensorRight); 


Serial.print("Left Sensor = "); 

Serial.print(SensorLeft); 

Serial.print("\t"); 

Serial.print("Right Sensor = "); 

Serial.print(SensorRight); 

Serial.print("\t"); 


if (SensorLeft<500 && SensorRight<500) { motor_stop();

Serial.println("Stop"); }

if (SensorLeft > SensorRight && SensorDifference > 75 && SensorLeft>500 && SensorRight>500) { 
turn_left();

Serial.println("Left"); 

}
if (SensorLeft < SensorRight && SensorDifference > 75 && SensorLeft>500 && SensorRight>500) { 

turn_right();

Serial.println("Right"); 

}

else if (SensorLeft>500 && SensorRight>500 && SensorDifference < 75) { 

drive_forward();

Serial.println("Forward");

}

Serial.print("\n");

} void motor_stop(){ digitalWrite(motor_left[0], LOW); digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW); digitalWrite(motor_right[1], LOW); }

void drive_forward(){ digitalWrite(motor_left[0], HIGH); digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], HIGH); digitalWrite(motor_right[1], LOW); }

void drive_backward(){ digitalWrite(motor_left[0], LOW); digitalWrite(motor_left[1], HIGH);

digitalWrite(motor_right[0], LOW); digitalWrite(motor_right[1], HIGH); }

void turn_left(){ digitalWrite(motor_left[0], LOW); digitalWrite(motor_left[1], HIGH);

digitalWrite(motor_right[0], HIGH); digitalWrite(motor_right[1], LOW); }

void turn_right(){ digitalWrite(motor_left[0], HIGH); digitalWrite(motor_left[1], LOW);

digitalWrite(motor_right[0], LOW); digitalWrite(motor_right[1], HIGH); }

}

void loop() {
  

}

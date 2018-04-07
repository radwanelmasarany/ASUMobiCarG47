const int inspd1=9;
const int inspd2=10;
char ip ;
void setup() {
 
Serial.begin(9600);
 pinMode(inspd1,OUTPUT);
 pinMode(inspd2,OUTPUT);
}

void loop() {
if(Serial.available()>0)
ip=Serial.read();
  if(ip=='0')
    {
      analogWrite(inspd1,0);
      analogWrite(inspd2,0);
      }
    if( ip == '1'){
      analogWrite(inspd1,50);
      analogWrite(inspd2,50);
      }
    if( ip == '2'){
      analogWrite(inspd1,80);
      analogWrite(inspd2,80);
      }    
    if( ip == '3'){
      analogWrite(inspd1,90);
      analogWrite(inspd2,90);
      }
        if( ip == '4'){
      analogWrite(inspd1,100);
      analogWrite(inspd2,100);
      }
        if( ip == '5'){
      analogWrite(inspd1,140);
      analogWrite(inspd2,140);
      }
        if( ip == '6'){
      analogWrite(inspd1,160);
      analogWrite(inspd2,160);
      }
          if( ip == '7'){
      analogWrite(inspd1,190);
      analogWrite(inspd2,190);
      }
        if( ip == '8'){
      analogWrite(inspd1,200);
      analogWrite(inspd2,200);
      }
      
        if( ip == '9'){
      analogWrite(inspd1,240);
      analogWrite(inspd2,240);
      }
        if( ip == 'q'){
      analogWrite(inspd1,255);
      analogWrite(inspd2,255);
        }
}

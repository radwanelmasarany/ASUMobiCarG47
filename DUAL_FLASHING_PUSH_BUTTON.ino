const int LED1 = 11;
const int LED2 = 13;
const int VOLT = 2;


void setup() 
{  
  pinMode (LED1,OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (VOLT,INPUT);
 
}

void loop()
{  
   if (digitalRead (VOLT)== HIGH)

    { digitalWrite (LED1,HIGH);
      delay (500);
      digitalWrite (LED1,LOW);
      digitalWrite (LED2,HIGH);
      delay (500);
      digitalWrite (LED2,LOW);
    }
    else 
    {   digitalWrite (LED1,LOW);
        digitalWrite (LED2,LOW);
    }    
   

}

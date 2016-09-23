#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
int deg = 0;
int sum = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if(Serial.available() > 0){
          int str = Serial.read();    
          if(str<=57){
               sum = (str-48)+(sum*10);    
          } 
          if(str=='s'){
               deg = sum;
               Serial.println(deg);
               sum = 0; 
         }
    }
}

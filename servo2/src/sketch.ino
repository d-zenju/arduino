#include <Servo.h>

// servo
Servo servo;
int flag = -1;
int sum = 0;
int deg = 0;

void setup() {
  // setup Servo
  servo.attach(3);
  servo.write(deg);
  
  // setup Serial
  Serial.begin(9600);
  Serial.println("Ready");
}

void readSerial() {
  char str;
  if (Serial.available()) {
    str = Serial.read();
    
    switch (str) {
      case '0'...'9':
        sum = sum * 10 + (str - 48);
        break;
        
      case 's':
        deg = sum;
        flag = 1;
        Serial.println(deg);
        sum = 0;
        break;
        
      default:
        sum = 0;
        break;
    }
  }
}

void loop() {
  // read Serial (ex. 180deg --> 180s)
  readSerial();
  
  // move Servo
  if (flag != -1) {
    servo.write(deg);
    flag = -1;
  }
}

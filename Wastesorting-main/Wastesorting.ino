#include <Servo.h>

Servo servo1;
Servo servo2;

int python;

int motor1 = 3; 
int motor2 =5;

int angle1 = 90;
int angle2 = 90;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(motor1);
  servo2.attach(motor2);
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  while(Serial.available()){
    python = Serial.read();
   // Serial.println(python);

    if(python == '0'){
      angle1 = 60;
      angle2 = 90;
    }
    else if(python == '1'){
      angle1 = 120;
      angle2 = 60;
    }
    else if(python == '2'){
      angle1 = 120;
      angle2 = 120;
    }
    servo1.write(angle1);
    servo2.write(angle2);
    delay(1000);
    Serial.println(python);
  }

}

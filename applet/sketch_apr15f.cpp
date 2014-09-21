#include <Servo.h>

#include "WProgram.h"
void setup();
void loop();
Servo servo1;  // create servo object to control a servo
Servo servo2; // create servo object to control a servo
Servo servo3;

int sensorPin1 = 0;
int sensorPin2 = 1;
int sensorPin3 = 2;
int pos1;      // angle of servo 1
int pos2; // angle of servo2
int pos3;
int sensorValue3=0;
int sensorValue2=0;
int sensorValue1=0;
int val=0;
int val_servo3=0;
int val_servo2=0;
int val_servo1=0;
void setup()
{
  servo1.attach(11);  // attaches the servo on pin 9 to the servo object
  servo2.attach(9);  // attaches the servo on pin 10 to the servo object
  servo3.attach(10);
  Serial.begin(9600);
}

void loop()
{
  sensorValue3 = analogRead(sensorPin3);    
  val_servo3 = map(sensorValue3, 0, 1023, 0, 179);
  servo3.write(val_servo3);
  
  sensorValue2=analogRead(sensorPin2);
  val = map(sensorValue2, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  val_servo2=179-val; 
  servo2.write(val_servo2);
  
  sensorValue1=analogRead(sensorPin1);
  val_servo1 = map(sensorValue1, 0, 1023, 0, 179);
  servo1.write(val_servo1);
 
 Serial.println(val_servo1,DEC);
 
 //Serial.println(val_servo2,DEC);
 delay(200);  
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}


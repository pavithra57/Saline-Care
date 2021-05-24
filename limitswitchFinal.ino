#include <Servo.h>
Servo servo_test;
int Lswitch = 2; 
int led = 13;  
int angle = 0;
 
void setup()
{
  servo_test.attach(9); 
  Serial.begin(9600); 
  pinMode(Lswitch, INPUT); 
  pinMode(led, OUTPUT); 
}
 
void loop()
{
  if( (digitalRead(Lswitch) == LOW)) 
  {
    Serial.println("door is closed"); 
    servo_test.write(70);

  }
  
    if( (digitalRead(Lswitch) == HIGH) ) 
  {
    Serial.println("door is opened"); 
    if(angle<90)
      servo_test.write(0);
   /* for(; angle < 90; angle =angle+90)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    
  }*/
 delay(100);
  }
  
 
}

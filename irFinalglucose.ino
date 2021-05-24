#include <Servo.h>
Servo servo_test;
int trigPin = 9;
int echoPin = 8;
int analog_ip = A0;   // select the input pin Photo Diode.
int inputVal = 0;
int angle = 0;// to store photo diode input
int ctrl = 0;
void setup() 
{
servo_test.attach(9); 
 // put your setup code here, to run once:
  pinMode(5, HIGH);
  pinMode(echoPin,INPUT);
 Serial.begin(9600);
}
 
void loop() {
  ir();
  servo_test.write(0);
  Serial.println(inputVal);
  if(inputVal<= 100)
  {
 for(angle = 0; angle < 180; angle += 90)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(0);                       
  }
  for(ctrl=0;ctrl<1;ctrl +=0)
  {
    if(echoPin=HIGH)
  {
    ctrl=1;
  }
   
    delay(10);
  } 
  }
  
  
  }
  

 void ir()
 {
  inputVal = analogRead(analog_ip); // Reading and storing analog input value.

        Serial.print("Input Value:");
        Serial.print(inputVal);       // Printing Analog input value of Photo Diode.
        Serial.print("\n");           // moving to new line
        delay(500);                   // Waiting for a while.

 }

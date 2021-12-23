#define joyX A0
#define joyY A1

#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo;     // variable untuk menyimpan posisi data

int pos = 00; 

int xValue ;
int yValue ;
void setup() {
  Serial.begin(9600);
   myservo.attach(2); //sinyal data kabel motor servo dikonekan di pin 3 Arduino
}
 
void loop() {
  // put your main code here, to run repeatedly:
  pos = map(analogRead(joyX),0,1023,0,180);
  yValue = map(analogRead(joyY),0,1023,0,180);
  
  myservo.write(pos); //prosedur penulisan data PWM ke motor servo
        delay(50); //waktu tunda 15 ms
//  //print the values with to plot or view
//  Serial.print(xValue);
//  Serial.print("\t");
//  Serial.println(yValue);
 
}
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo;     // variable untuk menyimpan posisi data

int pesan[1]={0};
RF24 rf24(7,8);
const byte alamat = 225;

int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
int pos = 00;   

void setup() {
//  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
//  myservo.attach(3); //sinyal data kabel motor servo dikonekan di pin 3 Arduino
  rf24.begin();
  rf24.openReadingPipe(0,alamat);
  rf24.setPALevel(RF24_PA_MIN);
  rf24.startListening();
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, 0, 180);
  mapY = map(yPosition, 0, 1023, 0, 180);
  
//  Serial.print("X: ");
//  Serial.print(mapX);
//  Serial.print(" | Y: ");
//  Serial.print(mapY);
//  Serial.print(" | Button: ");
//  Serial.println(SW_state);
//  delay(100);

//myservo.write(mapX); //prosedur penulisan data PWM ke motor servo
//  delay(15); //waktu tunda 15 ms

//  pesan[0]=mapX;
  const char pesan[]="hello"; 

  rf24.write(pesan,sizeof(pesan));

  
}

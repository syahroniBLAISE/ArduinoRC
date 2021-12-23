#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

#include <Servo.h> // menyertakan library servo ke dalam program 
Servo myservo;     // variable untuk menyimpan posisi data

int pos = 00;  
int pesan[1]={0};
const int led=2;
RF24 rf24(7,8);

const byte alamat = 225;

void setup() {
  pinMode(led,OUTPUT);
  delay(100);
  rf24.begin();
  rf24.openReadingPipe(0,alamat);
  rf24.setPALevel(RF24_PA_MIN);
  rf24.startListening();
  
  myservo.attach(3); //sinyal data kabel motor servo dikonekan di pin 3 Arduino
}

void loop() {
  while(rf24.available()){
    rf24.read(pesan,1);
    if(pesan[0]==1){
      for(pos = 00; pos < 180; pos += 1)  //fungsi perulangan yang akan dijadikan PWM dengan kenaikan 1
       {
        myservo.write(pos); //prosedur penulisan data PWM ke motor servo
        delay(50); //waktu tunda 15 ms                 
       } 
       for(pos = 180; pos>=1; pos-=1)  //fungsi perulangan yang akan dijadikan PWM dengan penurunan 1
       {                              
        myservo.write(pos);                 
        delay(15); 
                                
       }
       
    }
   
  }

}

#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

int pesan[1]={0};
const int tombol=6;
RF24 rf24(7,8);

const byte alamat = 225;

void setup() {
  pinMode(tombol,INPUT);
  rf24.begin();
  rf24.openWritingPipe(alamat);
  rf24.setPALevel(RF24_PA_MIN);
  rf24.stopListening();
}

void loop() {
  int bacaTombol;
  bacaTombol=digitalRead(tombol);
  pesan[0]=bacaTombol;
  rf24.write(pesan,1);
  pesan[0]= 0;
  rf24.write(pesan,1);
}

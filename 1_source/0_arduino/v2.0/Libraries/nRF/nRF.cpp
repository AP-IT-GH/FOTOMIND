#include "Arduino.h"
#include "nRF.h"
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
RF24 radio(9,10);
boolean stringComplete = false;  // whether the string is complete
static int dataBufferIndex = 0;
boolean stringOverflow = false;
char charOverflow = 0;
char SendPayload[31] = "";
char RecvPayload[31] = "";
char serialBuffer[31] = "";
nRF::nRF()
{
  Serial.begin(57600);
  radio.begin();  
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(70);  
  radio.enableDynamicPayloads();
  radio.setRetries(15,15);
  radio.setCRCLength(RF24_CRC_16);
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);    
  radio.startListening();
  radio.printDetails();  
}

void nRF::Send(String message)
{
	messageSize = message.length();
}

void nRF_receive(void) {
  int len = 0;
  if ( radio.available() ) {
      bool done = false;
      while ( !done ) {
        len = radio.getDynamicPayloadSize();
        done = radio.read(&RecvPayload,len);
        delay(5);
      }
  
    RecvPayload[len] = 0; // null terminate string
    
    
    Serial.print("R:");
   
    Serial.print(RecvPayload);
    Serial.println();
    RecvPayload[0] = 0;  // Clear the buffers
  }  

} // end nRF_receive()

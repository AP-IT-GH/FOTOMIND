#include <SPI.h>
#include <CommunicationMedium.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>

CommunicationMedium Master;
void setup()
{
  Master.SendData("abcdefghij");
  Serial.begin(9600);
}

void loop()
{
  Master.SendData("abcdefghij");
  Serial.println(Master.RecieveData());
}
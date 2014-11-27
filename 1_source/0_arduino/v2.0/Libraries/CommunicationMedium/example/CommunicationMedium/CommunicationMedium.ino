#include <SPI.h>
#include <CommunicationMedium.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>

CommunicationMedium Master;
void setup()
{
  Serial.begin(57600);
  Master.init();
}

void loop()
{
  //Master.SendData("yourmessage max 8 characters");
  String receipt = Master.RecieveData();
  if(receipt!="empty")
  {
    Serial.println(receipt);
  }
}
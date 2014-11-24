#ifndef nRF_Sent_h
#define nRF_Sent_h

#include "Arduino.h"
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

class nRF
{
  public:
	nRF();
	void Init();
    void Send(String Message);
	RF24 rfModule;
  private:
    int messageSize;
};

#endif
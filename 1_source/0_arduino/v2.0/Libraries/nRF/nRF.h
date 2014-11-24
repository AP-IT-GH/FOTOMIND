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
    void Send(String Message);	
	void nRF_receive();
  private:
    int messageSize;
	const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
};

#endif
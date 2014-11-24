#include "Arduino.h"
#include "nRF.h"
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

void nRF()
{
}

void nRF::Init()
{
	rfModule(9,10);
}

void nRF::Send(String message)
{
	messageSize = message.length();
}
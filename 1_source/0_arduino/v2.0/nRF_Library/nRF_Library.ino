#include <nRF.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

nRF nRFModule;

void setup()
{
  nRFModule.Init();
}



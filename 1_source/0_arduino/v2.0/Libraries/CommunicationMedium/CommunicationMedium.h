#ifndef CommunicationMedium_h
#define CommunicationMedium_h
//includes
#include <Arduino.h>
#include <CommunicationMedium.h>
#include <SPI.h>
#include <3thPartyLibraries\nRF24L01.h>
#include <3thPartyLibraries\RF24_config.h>
#include <3thPartyLibraries\RF24.h>
class CommunicationMedium
{
	public:
		CommunicationMedium();
		void SendData(String Message);
		String RecieveData();
	private:
		RF24 _module;
		const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };		
};
#endif
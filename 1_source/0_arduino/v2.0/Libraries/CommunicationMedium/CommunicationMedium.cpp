//includes
#include <Arduino.h>
#include <CommunicationMedium.h>
#include <SPI.h>
#include <3thPartyLibraries\nRF24L01.h>
#include <3thPartyLibraries\RF24_config.h>
#include <3thPartyLibraries\RF24.h>
//variables
CommunicationMedium::CommunicationMedium():_module(9,10)
{
	_module.begin();
	_module.setDataRate(RF24_250KBPS);
	_module.setPALevel(RF24_PA_MAX);
	_module.setChannel(70);  
	_module.enableDynamicPayloads();
	_module.setRetries(15,15);
	_module.setCRCLength(RF24_CRC_16);
	_module.openWritingPipe(pipes[0]);
	_module.openReadingPipe(1,pipes[1]);    
	_module.startListening();
}

void CommunicationMedium::SendData(String Message)
{
	char tmpMessage[10];
	strcpy(tmpMessage,Message.c_str());
	_module.openWritingPipe(pipes[1]);
    _module.openReadingPipe(0,pipes[0]);  
    _module.stopListening();
	bool ok = _module.write(&tmpMessage,strlen(tmpMessage));
	_module.openWritingPipe(pipes[0]);
    _module.openReadingPipe(1,pipes[1]); 
    _module.startListening();  
	tmpMessage[0]=0;	
}

String CommunicationMedium::RecieveData()
{	
	int len = 0;
	char RecvPayload[10];
	if ( _module.available() ) 
		{
			bool done = false;
			while ( !done ) 
			{
			len = _module.getDynamicPayloadSize();
			done = _module.read(&RecvPayload,len);
			}
		}  
    RecvPayload[len] = 0; // null terminate string
	return RecvPayload;
    RecvPayload[0] = 0;  // Clear the buffers
}
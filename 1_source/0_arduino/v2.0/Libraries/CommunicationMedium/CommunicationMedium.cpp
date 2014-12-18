//includes
#include <Arduino.h>
#include <CommunicationMedium.h>
#include <SPI.h>
#include <3thPartyLibraries\nRF24L01.h>
#include <3thPartyLibraries\RF24_config.h>
#include <3thPartyLibraries\RF24.h>
//variables
RF24 _module(9,10);
void CommunicationMedium::init()
{
	//configuration of RF24 library
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
//Sends string to other endpoint(s) listening
void CommunicationMedium::SendData(String Message)
{
	//Get the message and append # for easier communication
	Message = '#' + Message;
	char tmpMessage[10];
	//copy the content of Message in tmpMessage
	strcpy(tmpMessage,Message.c_str());
	Serial.println(tmpMessage);
	//SEND MODE
	_module.openWritingPipe(pipes[1]);
    _module.openReadingPipe(0,pipes[0]);  
    _module.stopListening();
	bool ok = _module.write(&tmpMessage,strlen(tmpMessage));	
	//RECIEVE MODE
	_module.openWritingPipe(pipes[0]);
    _module.openReadingPipe(1,pipes[1]); 
    _module.startListening();  
	tmpMessage[0]=0;	
}
//Recieve data that is send using senddata
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
	if(RecvPayload[0] == '#')
	{
		char ReturnPayload[9];
		for(int i=0;i<9;i++)
		{			
			ReturnPayload[i]=RecvPayload[i+1];
		}
		return ReturnPayload;
	}
	//return empty when there is no precieding # 
    RecvPayload[0] = 0;  // Clear the buffers
	return "empty";
}
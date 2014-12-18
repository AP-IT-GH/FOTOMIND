#include <SPI.h>
#include <CommunicationMedium.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>
#include <ArduinoInteraktiv.h>
#include <DistanceSRF04.h>

//#define SENDER
#define RECEIVER
//use our library for communication
CommunicationMedium Master;
//Here you can add the keys which will be used for their corresponding function
String UltraSonicKey = "117";//u
String TriggerManualKey = "105";//i
String PiezoTriggerKey = "116";//t
String NoTriggerKey = "112";//p
String TriggerLaserKey = "108";//l
String LatestReceive = "";
//bool used to limit the triggering so it doestn trigger all the time
bool MustTrigger = false;
//Use distancesensor
DistanceSRF04 Dist;
int distance;
//use library made by Bernd @ Austria
ArduinoInteraktiv camera; 

void setup()
{
  //start the camerashield
  camera.Start(); 
  //serial communication enable
  Serial.begin(57600);
  //start our wireless library
  Master.init(); 
 //start using distancesensor 
  Dist.begin(4,5); //(echo, trigger)
}
void loop()
{
  //here comes the code for the sending arduino, this one will be connected to a computer
  #ifdef SENDER
    if(Serial.available()>0)
    {
      //get the text from the serial port
      byte incomingByte = Serial.read();
      //send the text which is recieved over serial port
      Master.SendData((String)incomingByte);      
    }
  #endif
  //this code compiles for the receiver
  #ifdef RECEIVER
  //get the data from our RF module
    String receipt = Master.RecieveData();
    //if the recieved data is contains the word empty we wouldn't want to do something
    if(receipt!="empty")
    {
      //get the value recieved
      LatestReceive = receipt;
       //trigger the camera when nessesary   
      MustTrigger = true;    
    }
    //check which function needs to be executed
    if(LatestReceive == UltraSonicKey)
      triggerUltrasonic();
      
    else if(LatestReceive == TriggerManualKey)
    {
      triggerManual();
       
      }
      else if(LatestReceive == PiezoTriggerKey)
      triggerPiezo();
      else if (LatestReceive == TriggerLaserKey)
      triggerLaser();
    else if(LatestReceive == NoTriggerKey)
      noMoreTriggers(); 
  #endif
}
//functions which will be executed when nessesary
void triggerUltrasonic()
{
  distance = Dist.getDistanceCentimeter(); 
  if (distance <= 170)
  {
    camera.SinglePicture();
  }
}
void triggerManual()
{
  if(MustTrigger)
  {
  camera.SinglePicture();
  MustTrigger = false;
  }
}
void triggerPiezo()
{
  int a = analogRead(A0);
  if(a>=60)
  {
    camera.SinglePicture();
  }
}
void triggerLaser()
{
  //implement
  int a = analogRead(A1);
  if(a>50)
  {
    camera.SinglePicture();
  }
}
void noMoreTriggers()
{
  
}

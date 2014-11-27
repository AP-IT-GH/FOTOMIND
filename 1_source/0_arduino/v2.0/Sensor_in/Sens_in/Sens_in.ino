 #include <ArduinoInteraktiv.h>
#include <DistanceSRF04.h>

DistanceSRF04 Dist;
int distance;

ArduinoInteraktiv camera; //Make an object fram "ArduinoInteraktiv", we named the object "camera"
//When you want to use different pins you can simply change them when you create the object.
//ArduinoInteraktiv camera(int pushButton, int Switch, int piezoSensor, int lightSensor, int potentiometer, int focus, int shutter, int flash, int led1, int led2);
//Default pins: ArduinoInteraktiv camera(11,12,A0,A1,A2,10,9,8,2,3);

void setup()
{
  camera.Start(); //This is the initialisation for de Pin configuration.
  Serial.begin(9600);
  Dist.begin(4,5); //(echo, trigger)
}

void loop()
{
  distance = Dist.getDistanceCentimeter();
  Serial.print("\nDistance in centimers: ");
  Serial.print(distance);
 
  //if (distance <= 10)
  //{
  camera.SinglePicture();
  delay(3000);
  //}
  
 
  
}

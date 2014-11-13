#include <ArduinoInteraktiv.h>

ArduinoInteraktiv camera; //Make an object fram "ArduinoInteraktiv", we named the object "camera"
//When you want to use different pins you can simply change them when you create the object.
//ArduinoInteraktiv camera(int pushButton, int Switch, int piezoSensor, int lightSensor, int potentiometer, int focus, int shutter, int flash, int led1, int led2);
//Default pins: ArduinoInteraktiv camera(11,12,A0,A1,A2,10,9,8,2,3);

void setup()
{
  camera.Start(); //This is the initialisation for de Pin configuration.
}

void loop()
{
  camera.Time_Lapse(12,5000);
  // First opt value: You can use the switch or an analog sensor to enable the timelapse.
  // Second opt value: The time between the pictures in milliseconds
}

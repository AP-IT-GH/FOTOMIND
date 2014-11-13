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
  if (camera.GetPushButtonState() == HIGH) { // If the pushbutton is high
  camera.MultiFlash(); // Go in mode MultiFlash
  // Optional parameters:
  // MultiFlash(int time_between_flash_ms, int flashes) 
  // By default 3 flashes and 1000ms between the flashes.
  // How to use:
  // This is only tested in a dark room.
  // After pushing the button the focus is going on. 2s later the shutter is going in bulk mode.
  // After the last flash the shutter will be closed.
  }
}

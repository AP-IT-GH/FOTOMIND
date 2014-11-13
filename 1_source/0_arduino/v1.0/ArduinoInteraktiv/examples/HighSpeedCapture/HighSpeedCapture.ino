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
  camera.HighSpeedCapture(A1); //Calling HighSpeedCature function with sensor on analog pin A1.
  // HighSpeedCapture(int sensor, int interval_sensor_flash = 0, int ValueSensorActivated = 512)
  // Sensor is used to enable flash. 
  // How To use:
  // The function is only tested in a darkroom.
  // You can enable the HighSpeedCapturing by bush once the button. The camera should go in Bulk Mode.
  // When the sensor is triggered the flashlight will flash. The Bulk mode will be ended after 1000ms.
}

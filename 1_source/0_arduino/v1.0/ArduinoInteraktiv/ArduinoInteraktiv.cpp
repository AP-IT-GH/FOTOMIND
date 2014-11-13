#include "Arduino.h"
#include "ArduinoInteraktiv.h"


ArduinoInteraktiv::ArduinoInteraktiv(int pushButton, int Switch, int piezoSensor, int lightSensor, int potentiometer, int focus, int shutter, int flash, int led1, int led2)
{
  _pushButton = pushButton;
  _switch = Switch;
  _lightSensor = lightSensor;
  _piezoSensor = piezoSensor;
  _potentiometer = potentiometer;
  _focus = focus;
  _shutter = shutter;
  _flash = flash;
  _led1 = led1;
  _led2 = led2;
  //Init_pinMode();
}

void ArduinoInteraktiv::Start()
{
  pinMode(_pushButton, INPUT);
  pinMode(_switch, INPUT);
  pinMode(_focus, OUTPUT);
  pinMode(_shutter, OUTPUT);
  pinMode(_flash, OUTPUT);
  pinMode(_led1, OUTPUT);
  pinMode(_led2, OUTPUT);
  digitalWrite(_led1, HIGH);
  digitalWrite(_led2, HIGH);
  delay(300);
  digitalWrite(_led1, LOW);
  digitalWrite(_led2, LOW);
}
void ArduinoInteraktiv::MultiFlash(int time_between_flash_ms, int flashes) 
{
  _focusStart();
  delay(2000);
  _shutterStart();
  delay(time_between_flash_ms);
  for (int i=0; i < flashes; i++){
    _flashLight();
    delay(time_between_flash_ms);
  }
  _shutterStop();
  _focusStop();
}

void ArduinoInteraktiv::SinglePicture(bool flashLight)
{
  _focusStart();
  _shutterStart();
  if(flashLight)
  {
    _flashLight();
  }
  else {
    delay(200);
  } 
  _shutterStop();
  _focusStop();
}

void ArduinoInteraktiv::Time_Lapse(int sensor_or_input, int interval, int ValueSensorActivated)
{
  int state_of_sensor_input = 0;
  if (sensor_or_input >= 0 && sensor_or_input <= 13)
  {
	state_of_sensor_input = digitalRead(sensor_or_input);
	if(state_of_sensor_input == HIGH)
	{
	  SinglePicture();
	  delay(interval);
	}
  }
  else if (sensor_or_input >= A0 && sensor_or_input <= A5)
  {
  	state_of_sensor_input = analogRead(sensor_or_input);
  	if(state_of_sensor_input > ValueSensorActivated)
	{
  	  SinglePicture();
  	  delay(interval);
  	}
  }
}

void ArduinoInteraktiv::HighSpeedCapture(int sensor, int interval_sensor_flash, int ValueSensorActivated) 
{
  if(GetPushButtonState())
  {
    _highSpeedCaptureEnabled = HIGH;
  }
  else if (_highSpeedCaptureEnabled == HIGH)
  {
    int state_of_sensor_input = 0;
    _focusStart();
    _shutterStart();
    if (sensor >= 0 && sensor <= 13 && sensor != _pushButton)
    {
	  state_of_sensor_input = digitalRead(sensor);
	  if(state_of_sensor_input == HIGH)
	  {
	  	delay(interval_sensor_flash);
	    _flashLight();
	    delay(1000);
	    _shutterStop();
   	    _focusStop();
   	    _highSpeedCaptureEnabled = LOW;
	  }
    }
    else if (sensor >= A0 && sensor <= A5)
    {
  	  state_of_sensor_input = analogRead(sensor);
  	  if(state_of_sensor_input < ValueSensorActivated)
	  {
	    delay(interval_sensor_flash);
	    _flashLight();
	    delay(1000);
	    _shutterStop();
   	    _focusStop();
   	    _highSpeedCaptureEnabled = LOW;
  	  }
    }
  }
  else
  {
    _shutterStop();
   	_focusStop();
  }
}

int ArduinoInteraktiv::GetPushButtonState()
{  
  _statePushButton = 0;
  _statePushButton = digitalRead(_pushButton);
  return _statePushButton;
}

int ArduinoInteraktiv::GetSwitchState()
{
  _stateSwitch = 0;
  _stateSwitch = digitalRead(_switch);
  return _stateSwitch;
}

int ArduinoInteraktiv::GetPotentiometerValue()
{
  _valuePotentiometer = 0;
  _valuePotentiometer = analogRead(_potentiometer);
  return _valuePotentiometer;
}

int ArduinoInteraktiv::GetPiezoValue()
{
  _valuePiezoSensor = 0;
  _valuePiezoSensor = analogRead(_piezoSensor);
  return _valuePiezoSensor;
}

int ArduinoInteraktiv::GetLightSensorValue()
{
  _valueLightSensor = 0;
  _valueLightSensor = analogRead(_lightSensor);
  return _valueLightSensor;
}

void ArduinoInteraktiv::_flashLight(int time_flash_on) 
{
  _flashOn();
  delay(time_flash_on);
  _flashOff();
}

void ArduinoInteraktiv::_flashOn()
{
  digitalWrite(_flash, HIGH);
  digitalWrite(_led2, HIGH);
}

void ArduinoInteraktiv::_flashOff()
{
  digitalWrite(_flash, LOW);
  digitalWrite(_led2, LOW);
}

void ArduinoInteraktiv::_shutterStart() { 
  digitalWrite(_shutter, HIGH);
}

void ArduinoInteraktiv::_shutterStop() {
 digitalWrite(_shutter, LOW); 
}

void ArduinoInteraktiv::_focusStart() {
  digitalWrite(_focus, HIGH);
}

void ArduinoInteraktiv::_focusStop() {
  digitalWrite(_focus, LOW);
}
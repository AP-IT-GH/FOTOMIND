# Arduino Interaktiv Workshop
[![Gitter](https://badges.gitter.im/Join Chat.svg)](https://gitter.im/berndverhofstadt/ArduinoInteraktiv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
The Arduino Interaktiv workshop was organised in June 2014 at Fachhochschule St. Pölten (St. Pölten University of Applied Sciences) in Austria.
http://www.animationsummer.at/arduino-interaktiv/

During the workshop, the participants developed an Arduino shield, Arduino software and created experimental photograps and animations with their new hardware.
This library was written to share the results of the workshop with the world.

Hardware support:
 * Nikon D5000 series
 * More coming soon...

## General workflow
 * Develop the printed circuit board (Arduino shield)
 * Solder all the components
 * Test the hardware with some basic Arduino sketches. (test sensors, test flash,...)
 * Write the software to control your own camera
 * Experiment and implement your own ideas!

## Building the hardware
 * Eagle files (schematic, PCB layout)
 * Pictures of PCB
 * Overview of hardware components
 * Connectors: most camera's have to own exotic connector (a converter is often needed)
 * More info coming soon

## Testing the hardware
 * Running the examples one-by-one to verify if everything works as expected
 * Common mistakes (soldering mistakes: shorted pins, shorted traces, defected LEDs, loose components,...)

## Setting up the camera
 * coming soon
 
## Examples

### Multi-flash
 * For Multi-Flash mode an external flash is recommended.
 * Set your camera to bulk mode.
 * There are a few optional parameters. The interval time and number of flashes.

### Time-lapse
 * The Time-Lapse can be activated by an external input. 
 * The interval time can be easily adjusted.
 
### High-Speed Capturing
 * To use the High-Speed Capturing function you'll need an external input.
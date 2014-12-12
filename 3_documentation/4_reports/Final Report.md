# Smart Objects: Fotomind#
## Introduction ##
### Members ###
Bernd Verhofstadt, Cedric Baetens , Ikhlas Berazzi, Jef Gys, Tom Mampaey, Frederik Moonen, Thomas Mulder, Cedric Snijers, Robin Vercammen.
### Project Supervisors ###
Christian Munk (Austria), Jeroen Doggen.
###Info about the project###
-  Short article about the result of the original project in St. Pölten, Austria
   [Link (Dutch)](http://eaict.ap.be/animation-summer-arduino-interaktiv/)
- All basic information about the FOTOMIND 1.0 project
   [Link](http://www.animationsummer.at/arduino-interaktiv/)
- Site of Christian Munk where he places all his projects.
   [Link](http://www.progressivefactory.com/)
- Article about the collaboration between Artesis Plantijn University College    and St. Pölten University of Applied Sciences [Link (Dutch)](https://www.ap.be/nieuws/experiment-met-computer-van-de-toekomst/2178)

###Assignment as seen in the first report:###
>We take via a structured way a couple of photo’s by controlling several camera’s at the same time trough an Arduino. Every camera has it’s own Arduino module. Every module connected to the camera is a slave & is wireless supervised by one master Arduino, so we can dynamically add & remove camera’s. Every camera has it’s own RaspberryPi to collect the photo’s on the camera and send them to the server. This function allows us to keep taking pictures without removing the SD card.<
## Description: Fotomind V1.0 ##
FOTOMIND V1.0 is a project by Christian Munk. It is a remote that allows to trigger a DSLR caerma by using external trigger.
### Interface ###
<ol>
<li>Button</li>
<li>Potentiometer</li>
<li>LED</li>
<li>Display</li>
</ol>
### Connector List ###
The fotomind is equipped with female jack connections (3.5mm), these connetions are inputs that allow to to trigger the camera when a sensor is connected. 
<ol>
<li>Photoresistor</li>
<li>Microphone</li>
<li>Piezo</li>
</ol>
### Features ###
<ol>
<li>LCD background light</li>
<li>On/Off Switch</li>
<li>9V external power supply</li>
<li>Battery case for mobile use: 4 x AA</li>
<li>2 rows 16 character LCD Display</li>
<li>Background light</li>
</ol>
### Examples ###
<ol>
<li>Time Sequence/Lapse</li>
Pictures are taken with a specific time interval.
<li>Foto Trap</li>
Take multiple pictures when sensor is triggered.
<li>High speed Photography</li>
This setup has to be executed in a dark room. The shutter is constantly open, an external flash is triggered and the shutter is closed when the laser beam is discontinued. 
</ol>
![Picture of Setup](https://copy.com/thumbs_public/1qdt7rBKIJxfFwKW/Image1.jpg?size=1024)
<p>[Result High Speed Photography](https://copy.com/hnnhiVT3sFPKF8mY)
![HighSpeedZitrone](http://eaict.ap.be/wp-content/uploads/2014/07/Zitrone_Matrix_0.1sec2.gif)
![HighSpeedKarotte](http://eaict.ap.be/wp-content/uploads/2014/07/Karotte-2_01sec.gif)
Result of Time Lapse (click to open in YouTube)
[![Result of Time Lapse](http://img.youtube.com/vi/Lv71nvoqJXY/0.jpg)](http://www.youtube.com/watch?v=Lv71nvoqJXY)
### Design ###
![Picture 1](https://copy.com/thumbs_public/GHQAvVJfb3sU2DGc/Image10.jpg?size=512)
![Picture 2](https://copy.com/thumbs_public/GHQAvVJfb3sU2DGc/Image7.jpg?size=1024)
![Picture 3](https://copy.com/thumbs_public/GHQAvVJfb3sU2DGc/Image8.jpg?size=1024)
![Picture 4](https://copy.com/thumbs_public/GHQAvVJfb3sU2DGc/Image9.jpg?size=1024)
![Picture 5](https://copy.com/thumbs_public/GHQAvVJfb3sU2DGc/Image4.jpg?size=1024)
![Picture 6](https://copy.com/thumbs_public/GHQAvVJfb3sU2DGc/Image5.jpg?size=1024)
### Extra Information
-  Short article about the result of the original project in St. Pölten, Austria
   [Link (Dutch)](http://eaict.ap.be/animation-summer-arduino-interaktiv/)
- All basic information about the FOTOMIND 1.0 project
   [Link](http://www.animationsummer.at/arduino-interaktiv/)
- Site of Christian Munk where he places all his projects.
   [Link](http://www.progressivefactory.com/)
- Article about the collaboration between Artesis Plantijn University College    and St. Pölten University of Applied Sciences[Link (Dutch)](https://www.ap.be/nieuws/experiment-met-computer-van-de-toekomst/2178)

## Description: Fotomind V2.0 ##
###Interface###
The setup can be controlled by using two different user interfaces.
####HTML UI####
The web interface can be used to view al the pictures taken by different camera's . All the pictures are saved on the server. It is possible to delete and download certain pictures. For each event, a new folder can be created. More Information about the website can be found in the 1source\4webserver.
![screenshot Website](https://cloud.githubusercontent.com/assets/5656511/5182098/fbdac642-749d-11e4-9d60-a5ba838cd332.png)
####C# UI####
The C# interface is used to control the Arduino that is connected to the computer by using a USB cable. The user interface allows to set the trigger of al the arduino's connected to a camera. More Information about the website can be found in the 1source\2windows.
![screenshot C# UI](https://copy.com/qVPeHEk8U0iLJZYN)
###Hardware###
We have chosen to use two different types of hardware, because not all camera's have the option to be triggered by USB. The advantage of using multiple hardware devices, is that there are multiple points of failiure. If for example the raspberry PI fails, the camera's can still be triggered by using the arduino and the images will be saved to the internal SD Card.
####Arduino####
The arduino is equiped with a custom designed shield.
![Arduino And Shield](https://copy.com/lmHqzlcdeA9PkcjE)
####Rasberry PI####
The aspberry pi runs debian with the Gphoto libary installed.
####Arduino Shield####
The new shield was designed from scratch because there was not enough place for the connections of NRF024 module.
![Arduino Shield](https://copy.com/gWriatevxmfvFwLk)
![Arduino Shield](https://copy.com/bzHoV1IOfbchOPSh)
###Setup###
![Setup](https://copy.com/FiFK9J4qmGn17b4v)
###Communication###
####NRF024####
The communication between the different arduinos is based on the NRF024. We have chosen for this type of communication because we didn't need much bandwidth.
####Ethernet/Wifi####
The communication between the server and the arduinos is based on 802.11(wifi) or 802.3(ethernet). We opted to use ethernet for the communication because of the bigger bandwidth.

## Overview ##
In the first two weeks we created the basis for this project. We were able to register when the camera took a picture & load it on a server. Furthermore we were created a library that enables wireless communication between two Arduino's. The wireless connection is based on slave Arduino which receives the data & triggers the camera & the master Arduino which is connected to a computer. The master Arduino send information trough a RF module. For changing the modes in which the camera triggers we developed a WPF program for control.

The remaining time was dedicated to finetuning & bringing it all together!

## Tests and Experiments
In the last weeks we intensly tested the entire project, triggering the camera with different sensors: ultrasonic - piezzo - manual. 
![Test 1.0](https://copy.com/Dc0uuO2OOyMpzCqI)
![Test 2.0](https://copy.com/WiZF4AxGqBMFcbDO)


## Conclusion ##
All expectations from the assignment are completed & succesfull.

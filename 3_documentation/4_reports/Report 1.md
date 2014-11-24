#Fotomind#
## Assignment ##
<div><p>We take via a structured way a couple of photo’s by controlling several camera’s at the same time trough an Arduino. Every camera has it’s own Arduino module. Every module connected to the camera is a slave & is wireless supervised by one master Arduino, so we can dynamically add & remove camera’s. Every camera has it’s own RaspberryPi to collect the photo’s on the camera and send them to the server. This function allows us to keep taking pictures without removing the SD card.</p></div>

<ol>
	<li>Control the camera trough an Arduino</li>
	<li>Communicate between several Arduino’s</li>
		> Wired Connection
		> Wireless Conenction
	<li>Read the photo’s from the camera</li>
	<li>Send the photo’s to the server</li>
</ol>

**11/29/2014 2:53:40 PM **
<div><p>Christian explained the first steps from the project to us, by making an alignment for highspeed photography. The alignment existed from an Arduino, a camera, a laser & a sensor which are all connected. If the laser beam was broken by a solid object the shutter realease was triggered. It got clear on how sensitive the alignement is & how the estimation when the camera had to be trigger was crucial.</p></div>
<div><p>Next we drew up a visual connection schema:</p></div>
![](https://raw.githubusercontent.com/AP-Elektronica-ICT/FOTOMIND/master/3_documentation/3_visualisation/Scheme.png?token=AGRMjVy0SSFBFzbL-A-NPBbw8bOlqpqxks5UfHS7wA%3D%3D)
<div>
<p>Here after we started researching on the possiblities for reading the picture from the camera without removing the SDcard from the slot. We found a library which gives us the possibilities for this: gphoto2. We could succesfully run this on a RaspberryPi.</p>
<p>Afterwards we started investigating on how we need to communicate between several Arduino’s. We were able to succesfull connect one Arduino to another, send & receive data trough a **wire**.</p></div>
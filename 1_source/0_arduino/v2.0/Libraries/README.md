#Libraries#
<p>
In this folder we list the libraries we are using in our project.
</p>
<ol>
	<li>
		Self Written libraries
		<ul>
			<li>
				CommunicationMedium
			</li>
		</ul>
	</li>
	<li>
		Used Libraries
		<ul>
			<li>
				RF24-master
			</li>
			<li>
				DistanceSensor
			</li>
			<li>
				ArduinoInteraktiv
			</li>
		</ul>
	</li>
</ol>

##Self written libraries##
###CommunicationMedium###
<p>
We wrote this library to have a wrapper around the existing RF24 library. We wrote this wrapper for easu acces to the needed functionality of the wireless sensor. We most basicly made a function to SendData wich allows a parameter of a String to be send. Another functionality we needed was to recieve the message. we wrote another function in order to recieve data, this function return a String. Our wrapper abstracts a lot of code so we can minimize the code in another library/program.
</p>
##Used libraries##
###RF24###
<p>
This is the library which allows us to communicate with the nrf24 module. This library handles all the lower level communication with the device. The module however needs to be configured. The configuration will be handled by our self-written library 
</p>
###DistanceSensor###
<p>
This is the library used for reading the ultrasonic sensor
</p>
###ArduinoInteraktiv###
<p>
Library made at the St. Pöten Univeristy for interfacing with the camera.
</p>
 
#Requirements#
## Software: ##

<ul>
	<li>
	Write a graphical interface for interfacing with the arduino. This interface has to be able to:
		<ol>
			<li>
				Choose which arduino master reciever will be controlled.
			</li>
			<li>
				Choose which trigger will be used.
			</li>
			<li>
				The interface should be able to trigger a camera. 
			</li>
		</ol>
	</li>
	<li>
		Write an arduino library/program in order to process input given in the interface and communicate with the controlled master recievers.
			<ol>
				<li>
					Recieve commands from computer program
				</li>	
				<li>
					execute commands from computer
				</li>
				<li>
					put payload on wireless media
				</li>
				<li>
					(check if payload is executed)
				</li>
			</ol>
	</li>
<li>
	Write an interface to recieve a payload and send a confirmation from master Arduino.
		<ol>
			<li>
				Translate the payload to an instruction the slave arduino's understand.
			</li>
			<li>
				send a confirmation or error when processing the payload.
			</li>
			<li>
				It has to be able to execute the payload by itsel
			</li>
		</ol>
	</li>
	<li>
		The bridge between the wireless reciever and the other clustered arduino's
			<ol>
				<li>
					address other arduino's using spi
				</li>	
				<li>
					send data to other arduino's using spi
				</li>				
			</ol>
	</li>
</ul>
## Hardware: ##
<ul>
	<li>
	Trigger Camera
		<ol>
			<li>
				Be able to take a picture
			</li>
			<li>
				(use flash)
			</li>
		</ol>
	</li>
<li>
	Read sensor and trigger camera according to instruction
			<ol>
				<li>
					Trigger camera by use of instruction
				</li>	
				<li>
					Use proper sensor according to the send instruction 
				</li>
				<li>
					Trigger on selected sensor
				</li>
				<li>
					(dynamicly addable sensors)
				</li>
			</ol>
	</li>
<li>
		An input box connectable to a computer using USB
		<ol>
			<li>
				input: single usb-B
			</li>
		</ol>		
	</li>
	<li>
		A big output box with more arduino's for mulitple camera's
		<ol>
			<li>
				input: power for arduino's and raspberry pi
			</li>
			<li>
				ethernet connection for raspberry pi 
			</li>
			<li>
				multiple connection for camera trigger: preferable a 3.5mm jack or something common
			</li>
			<li>
				multiple connection for camera data: preferable a quadruple usb hub
			</li>
		</ol>
	</li>
	<li>	
		A little output box with one arduino for one camera
		<ol>
			<li>
				like the big output box but with less connections 
			</li>
		</ol>
	</li>
	<li> 
		(PCB-design for optimal arduiro-shield)
	</li>
</ul>


</ul>
## Connection: ##
See schematic for visualisation (3_documentation>3_visualisation>Scheme.png)
<ul>
	<li>
	Wireless connection between Master Arduino (Computer) and Slaves Arduino's (Camera's) over nRF24
	</li>
	<li>
	Connection between camera and server by using Raspberry pi's
	</li>
	<li>
	Write a library for easy acces to the communication medium
		<ol>
			<li>
				send a message to a specific other arduino identified by something unique
			</li>
			<li>
				make it easy to send a message from one to another			
			</li>
		</ol>
	</li>
<li>
	Get the photo's of the camera
		<ol>
			<li>
				use gphoto to collect the pictures from the camera's
			</li>
			<li>
				store those photo's temporary in ram for better performance
			</li>
			<li>
				index photo's according to photo
			</li>
			<li>
				(process photo's right after they are taken (trigger event))
			</li>
		</ol>
	</li>
	<li>
		Write a script which will upload the taken photo's to an online database
	</li>
<li>
	Write a webpage for interfacing with the photo's
		<ol>
			<li>
				view photo's
			</li>
			<li>
				download photo's
			</li>
			<li>
				delete photo's
			</li>
		</ol>
	</li>
	<li>
		The database should provide a simple post script for uploading an image
			<ol>
				<li>
					save photo on filesystem
				</li>	
				<li>
					index filesystem in a database using tags for easy access to photo's
				</li>
			</ol>
	</li>
</ul>

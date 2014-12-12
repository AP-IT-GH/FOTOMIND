# Arduino shields#

##Schematic:##
We remade and optimized the existing schematic of FotoMind 1.0:
<ul>
<li>Added the wireless connection (nRF24) for remote triggering</li>
<li>Optimized some wire-connections</li>
<li>Added 3 visualisation LEDs to confirm power, trigger, flash,...</li>
<li>Added buttons to test the functionality'On-board' (independent of the wireless-communication)</li>
<li>Added some mulifunctional connectors to add diffrent sensors or outputs</li>
<li>Added a on-board ultrasonic sensor (HC-SR04) to measure distance </li>
</ul>

[schematic](https://www.dropbox.com/s/dkf0853rwxmuuqd/Schematic.PNG?dl=0)


##The PCB:##
We made a very multifunctional PCB that we easy can adjust by placing/or not placing some components:
<ul>
<li>At the side of the PCD we placed a header the put a distance-sensor (optional)  </li>
<li>In the middle there's a connector to put the wireless-nRF24-module </li>
<li>We have the option to put 3 opto's on the board for trigger(1), Flash and focus</li>
<li>We also have countless options due the multiple connectors connected to the arduino ports and vcc.</li>
</ul>
[PCB-design](https://www.dropbox.com/s/i2g31ev0dzjte93/PCB-design.PNG?dl=0)
# Raspberry Pi
#Installation#
<p>
First we downloaded the raspbian image to our computer.We copied the image to an SD card using Win32DiskImager. When the image is copied it is time to boot our Raspberry Pi. We run through the initial setup and now we are able to use the Raspberry Pi. Since we are using a 'AZERTY' keyboard and raspbian is using a querty keyboard as default we will be changing that as the first thing. We open the keyboard file using <code>sudo nano /etc/default/keyboard</code> and change the line <code>XKBLAYOUT="en"</code> to <code>XKBLAYOUT="be"</code>,save the file and restart the Raspberry Pi.
</p>
<p>
Now we are going to set up ssh and for testing purposes a static ip address. 
For the static ip address we are going to use <code>192.168.0.129</code>. We need to edit the interfaces file <code>sudo nano /etc/network/interfaces</code>. For the moment we are getting an ip address from a DHCP server. In order to change this to static we need to change <code>iface eth0 inet dhcp</code> to <code>iface eth0 inet static</code>. Below this line we are now going to specify our static behavior as follows: 
<br/>
<code>
address 192.168.0.129<br/>
netmask 255.255.255.0<br/>
network 192.168.0.0<br/>
broadcast 192.168.0.255<br/>
gateway 192.168.0.1
</code>
</br>
we now save and exit the file. Once we reboot the changes we made will be applied. </br>
When the reboot is complete we can test SSH (which is configured out of the box). We use Putty from a client computer to connect to our Raspberry Pi over the network.
</p>


</p>
# Sources #
<div>
Raspberry Pi image:</br>
http://downloads.raspberrypi.org/raspbian_latest
</div>
<div>
Win32DiskImager:</br>
http://sourceforge.net/projects/win32diskimager/files/Archive/Win32DiskImager-0.9.5-install.exe/download
</div>
# Reminder #
username for our pi is 'pi' and password is 'raspberrypi'
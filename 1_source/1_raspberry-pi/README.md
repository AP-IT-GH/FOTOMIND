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
<p>
Now that we have our Raspberry Pi up and running we are going to create a ramdisk. We will be using one in order to avoid writing photo's from the camera's to the internal SD card of the Raspberry Pi. This has 2 big advantages. The SD card will not wear off under heavy load and we can process our pictures much faster.</br>
We start by making a directory where we are going to mount our newly made ramdisk. <code>mkdir /mnt/ramdisk</code> then we will be making a 100MB ramdisk. A generic command is specified as followed: <code>mount -t [Type] -o size=[Size] [Fstype] [Mountpoint]</code> where <code>[Type]</code> is the type of ram to use, we will be using tmpfs in order to specify a vast amount of storage. We will make <code>[Size]</code> around a 100MB in order to have enough cache when shooting pictures. As <code>[Fstype]</code> we will use tmpfs. And our <code>[Mountpoint]</code> will be the directory we have created before. Our command looks like this: <code>mount -t tmpfs -o size=100m tmpfs /mnt/ramdisk</code>. In order to have this directory available over a reboot we add it to the fstab to let it mount when the Raspberry Pi boots. However the contents will not live over a reboot. <br/>
<code>sudo nano /etc/fstab</code> <br/>
In this files we will add a line:
<code>tmpfs       /mnt/ramdisk tmpfs   nodev,nosuid,noexec,nodiratime,size=100m   0 0 </code>
Now we have a 100MB ramdisk which we will be using in the next steps in order to process the pictures fast.
</p>
<p>
Now we start with installing gphoto. <br/>
<code>sudo apt-get update</code><br/>
<code>sudo apt-get upgrade</code><br/>
<code>sudo apt-get install gphoto2</code><br/>
We need the latest version in order to achieve maximum compatibility we use gphoto2-updater<br/>
<code>
wget https://raw.githubusercontent.com/gonzalo/gphoto2-updater/master/gphoto2-updater.sh <br/>
chmod +x gphoto2-updater.sh <br/>
sudo ./gphoto2-updater.sh <br/>
</code>
After executing the script we can run gphoto from /usr/bin/gphoto. We should be able to use a camera at this moment.
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
<div>
Ramdisk:<br/>
http://www.jamescoyle.net/how-to/943-create-a-ram-disk-in-linux
</div>
<div>
gphoto download:<br/>
http://sourceforge.net/projects/gphoto/files/latest/download?source=files
</div>
<div>
gphoto2-updater:<br/>
https://github.com/gonzalo/gphoto2-updater
</div>
# Reminder #
username for our pi is 'pi' and password is 'raspberrypi'
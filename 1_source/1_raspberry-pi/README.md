# Raspberry Pi
####Installation####
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
When the reboot is complete we can test SSH (which is configured out of the box). We use Putty from a client computer to connect to our Raspberry Pi over the network.<br/>
Another option is to edit the cmdline.txt in the boot partition as described here: (http://pihw.wordpress.com/guides/direct-network-connection/). We will be using this method because it's easier to switch between static and dynamic ip addresses without the need for an external screen and keyboard directly connected to the Raspberry Pi.
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
<p>
We write a shell script <code>GetFileFromDirectoryAndSendToServer.sh</code> and place it in our home directory<code>/home/pi</code>. The purpose of this script is that is being run right after gphoto has detected there was an image captured from a camera. The script will do folowing things:<br/>
<ol>
	<li>
		search for the file it has to upload
	</li>
	<li>
		upload the file to the server
	</li>
	<li>
		remove the file from the ramdisk
	</li>
</ol>
<code>
<div>
	We are using the bash shell 
</div>
	#!/bin/bash <br/>
<div>
	this is the directory we made when mounting the ramdisk for temporary storage
</div>
	dir='/mnt/ramdisk'
<div>
	we select one file from the temporary storage
</div>
	file=$(/bin/ls -1 "$dir" | head -1) <br/>
<div>
	we make the path so that is in a good format
</div>
	path=$(readlink --canonicalize "$dir/$file") <br/>
<div>
	define where our server script is located
</div>
	server='http://www.verhofstadt.eu/upload.php'<br/>
<div>
	get the mac adress for unique identifiquation of Raspberry Pi's
</div>
	mac=$(ifconfig eth0 | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}')<br/>
<div>
	Post to the form located at $server with input fields 'mac' and 'image'
</div>
	curl -F "mac=$mac" -F "image=$path" $server<br/>
<div>
	remove the photo we just posted
</div>
	rm $path 
</code> <br/>
However we want to run this script whenever an image is taken and that's where gphoto comes in. Gphoto has the built in command  <code>gphoto2 --capture-tethered --hook-script [PATH TO SCRIPT]</code> where we will fill in our script for postprocessing. We would like the Raspberry Pi to be listening for such events the moment it boots. So we are going to write the script <code>GphotoStartupScript.sh</code> this script has to:<br/>
<ol>
	<li>
		start up at boot time
	</li>
	<li>
		run the code <code></code>
	</li>
</ol>
We place the script in our home folder <br/>
<code>
	#!/bin/bash<br/>
	#saved at /home/pi<br/>
	cd /mnt/ramdisk<br/>
	/usr/local/bin/gphoto2 --capture-tethered --hook-script /home/pi/GetFileFromDirectoryAndSendToServer.sh<br/>
</code>
It will search for camera's and use them if there are no cameras connected at startup you can run the script manually. We now need to add it to the <code>/etc/rc.local</code> file so that it will run during startup.
</p>

# Practical approach #
<div>
<p>We started of with a Nikon D3100 for testing, but experienced connection problems. The Canon 50d & Nikon D5200 showed us no problems. </p>
</div>
<div>
<p>Next we removed the <code>-filename</code> variable in the <code>GphotoStartupScript.sh</code>, because it didn't work. </p>
</div>
<div>
<p>For local testing purposes we changed the  server parameter to <code>server='http://192.168.1.121:8888/fotomind/upload.php'</code> & finetuned the <code>"image=@$path"</code> variable in the <code>GetFileFromDirectoryAndSendToServer.sh</code>. Everytime we take a photo, the photo is uploaded to the server in a matter of seconds.</p>
</div>
<div>
<p>Some other minor problem we conquered: a full RAM disk, because of that we added a <code>rm</code> command so the file is removed from the RAMdisk everytime it is uploaded.</p>
</div>
<div>
<p>Next we succesfully made the script execute on startup from the raspberry. This proces has some easy steps:</p>
<ol>	
	<li>Power on camera</li>
	<li>Connect the camera to the RaspberryPi</li>
	<li>Fire up RaspberryPi</li>
	<li>Wait a little while for the RaspberryPi to powerup</li>
	<li>Take a picture</li>
</ol>
</div>

# Sources #

#### Raspberry Pi image: ####
http://downloads.raspberrypi.org/raspbian_latest

####Win32DiskImager:####
http://sourceforge.net/projects/win32diskimager/files/Archive/Win32DiskImager-0.9.5-install.exe/download

####Access raspberry pi over direct ethernet####
http://pihw.wordpress.com/guides/direct-network-connection/

####Ramdisk:####
http://www.jamescoyle.net/how-to/943-create-a-ram-disk-in-linux

####gphoto download:####
http://sourceforge.net/projects/gphoto/files/latest/download?source=files

####gphoto2-updater:####
https://github.com/gonzalo/gphoto2-updater

# Reminder #
username for our pi is 'pi' and password is 'raspberrypi'
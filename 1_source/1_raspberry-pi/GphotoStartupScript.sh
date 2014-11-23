#!/bin/bash
#saved at /home/pi
(cd /mnt/ramdisk && /usr/local/bin/gphoto2 --capture-tethered --hook-script /home/pi/GetFileFromDirectoryAndSendToServer.sh)
#/usr/local/bin/gphoto2 --capture-tethered --hook-script /home/pi/GetFileFromDirectoryAndSendToServer.sh -filename /mnt/ramdisk/picture%n.jpg

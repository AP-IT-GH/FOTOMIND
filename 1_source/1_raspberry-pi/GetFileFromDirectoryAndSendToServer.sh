#!/bin/bash
#saved at /home/pi
if [ $ACTION == download ];then
dir='/mnt/ramdisk' #directory where we store our photo's temporary
file=$(/bin/ls -1 "$dir" | head -1) #list one file (there can only be one file processed at a time
path=$(readlink --canonicalize "$dir/$file") #make a path to the file
server='http://192.168.1.121:8888/fotomind/upload.php'
mac=$(ifconfig eth0 | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}')
#use this line for uploading, hope it works if bernd has the site online
#curl -F "userid=1" -F "filecomment=This is an image file" -F "image=@/home/user/desktop/img.jpg" localhost/upload.php
curl -F "mac=$mac" -F "image=@$path" $server
rm $path #remove file when it is send, this will remove nothing if there is no file
else
        exit 0
fi


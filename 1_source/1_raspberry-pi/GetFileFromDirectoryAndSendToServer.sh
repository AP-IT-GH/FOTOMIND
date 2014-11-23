#!/bin/bash
#saved at /home/pi
dir='/mnt/ramdisk' #directory where we store our photo's temporary
file=`/bin/ls -1 "$dir" | head -1` #list one file (there can only be one file at a time)
path=`readlink --canonicalize "$dir/$file"`#make a path to the file
#echo $path #for testing purposes
rm $path #remove file when it is send, this will remove nothing if there is no file
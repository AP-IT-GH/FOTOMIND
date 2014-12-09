<?php

$path = "DATA/Planes/ShotView1"; 

$files = scandir($path, 1);
$last_file = $files[0];
print("/".$path."/".$last_file);

?>
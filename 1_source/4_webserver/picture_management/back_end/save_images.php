<?php
//ini_set('display_errors', 'On');
try {
	if ( !isset($_GET['images_arr']) && !isset($_GET['group']) && !isset($_GET['project']) ) throw new Exception("POST was not complete...", 1);
	# create new zip opbject
	
	$zip = new ZipArchive();
	$arr_images = explode(",", $_GET["images_arr"]);
	$groupname = $_GET['group'];
	$projectname = $_GET['project'];
	$path = "../DATA/$projectname/$groupname/";
	
	# create a temp file & open it
	$tmp_file = tempnam('TEMP','');
	$zip->open($tmp_file, ZipArchive::CREATE);

	# loop through each file
	foreach($arr_images as $image){
		#add path
		$final = $path . $image;

	    # download file
	    $download_file = file_get_contents($final);

	    #add it to the zip
	    $zip->addFromString(basename($image),$download_file);

	}

	# close zip
	$zip->close();
	
	# send the file to the browser as a download
	
    $file_name = basename($tmp_file);

	// set the download rate limit (=> 5046 kb/s)
	$download_rate = 5046;
	$download_file_name = $file_name.'.zip';
	if(file_exists($tmp_file) && is_file($tmp_file))
	{
	    header('Cache-control: private');
	    header('Content-Type: application/octet-stream');
	    header('Content-Length: '.filesize($tmp_file));
	    header('Content-Disposition: filename='.$download_file_name);

	    flush();
	    $file = fopen($tmp_file, "r");
	    while(!feof($file))
	    {
	        // send the current file part to the browser
	        print fread($file, round($download_rate * 1024));
	        // flush the content to the browser
	        flush();
	        // sleep one second
	        sleep(1);
	    }
	    fclose($file);}
	else {
	    throw new Exception('Error: The file '.$tmp_file.' does not exist!', 1);
	    
	}

	unlink($tmp_file);
	exit;
	} catch (Exception $e) {
		echo 'Caught exception: ',  $e->getMessage(), "\n";
	}
?>
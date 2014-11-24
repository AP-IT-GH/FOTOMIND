<?php
	try {
		if ( !isset($_POST['images_arr']) && !isset($_POST['group']) && !isset($_POST['project']) ) throw new Exception("POST was not complete...", 1);
		$arr_images = $_POST['images_arr'];
		$groupname = $_POST['group'];
		$projectname = $_POST['project'];
		$path = "../DATA/$projectname/$groupname/";
		foreach ($arr_images as $image) {
			$final = $path . $image;
			if (file_exists($final)) {
		        unlink($final);
		    }
		}		

	} catch (Exception $e) {
		echo 'Caught exception: ',  $e->getMessage(), "\n";
	}
	

?>
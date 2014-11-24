<?php
//UPLOAD IMAGES	
//ini_set('display_errors', 'On');

try {
  	$allow = array("jpg", "jpeg", "gif", "png", "nef", "cr2");
	$projectname = 'Staking';
	if (isset($_POST['group'])) {
		$groupname = str_replace(':','_',$_POST['group']);
		$todir = "DATA/$projectname/$groupname/";
		if (!!$_FILES['file']['tmp_name'] ) // is the file uploaded yet?
		{
			$fileName = $_FILES['file']['name'];
			$info = explode('.', strtolower( $_FILES['file']['name']) ); // whats the extension of the file
			if ( in_array( end($info), $allow) ) // is this file allowed
			{
				if (!file_exists($todir)) {
				    mkdir($todir, 0777, true);
				}
				$new_file_name = $todir . $fileName;
				if ( move_uploaded_file( $_FILES['file']['tmp_name'], $new_file_name) )
				{
					echo "done...";
				}
			}
			else
			{
				throw new Exception('This file extension is not allowed.');		// error this file extension is not allowed.
			}
		}
		else
		{
			throw new Exception('Failed to upload!');
		}
	}
	else
		throw new Exception("Group is not set", 1);
} catch (Exception $e) {
	echo 'Caught exception: ',  $e->getMessage(), "\n";
}
?>
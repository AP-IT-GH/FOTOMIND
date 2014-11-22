<?php
//UPLOAD IMAGES	

try {
    $allow = array("jpg", "jpeg", "gif", "png");
	$todir = 'user_images/';		
	if (!!$_FILES['file']['tmp_name'] ) // is the file uploaded yet?
	{
	$info = explode('.', strtolower( $_FILES['file']['name']) ); // whats the extension of the file
	if ( in_array( end($info), $allow) ) // is this file allowed
	{
		$new_file_name = $todir . $this->user_id . '.' . end($info);
		if ( move_uploaded_file( $_FILES['file']['tmp_name'], $new_file_name) )
		{
			$file_location = '/' . $new_file_name;
			$this->foto = $file_location;
		}
	}
	else
	{
		throw new Exception('');		// error this file extension is not allowed, default avatar is set.
		//echo "false";
	}
}
else
{
	throw new Exception('Failed to upload!');
	//echo "Failed to upload!";
}
} catch (Exception $e) {
    echo 'Caught exception: ',  $e->getMessage(), "\n";
}
if($_POST)
{

}
else
{
echo "send something...";
}
?>
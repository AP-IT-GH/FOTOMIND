# Webserver

All files on the webserver to collect, show and edit the pictures.
This is the management module to collect and organize the pictures.

## Frameworks and used links
-  Semantic UI: used for the layout and icons of the website http://semantic-ui.com 
-  Image Picker: used to show the picture and select them http://rvera.github.io/image-picker/
-  jQuery: used javascript framework http://jquery.com/ 

## How it works
### Upload image
The first step is to upload an image to the server. It's importent to do this with a post and give the parameter file as File and group as Text. As groupname we use the mac address of the raspberry pi. 
The project name will be defined hardcoded in the code.
- Send pictures with POST to http://localhost:8888/fotomind/upload.php
- Send image as 'file'
- Send group name as 'group'

### Image formats
It's easy to change the allowed image formats, just add the extension in lower case without a point.
```php
$allow = array("jpg", "jpeg", "gif", "png", "nef", "cr2");
```
### Directory structure
The path will inlude the project name, groupname/mac address rasp pi and the filename.
```php
$groupname = str_replace(':','_',$_POST['group']);
$todir = "DATA/$projectname/$groupname/";
```
this will output something like this:
```
/DATA/project_name/10_dd_b1_xx_xx_xx/img0011.jpg
```

## Functions on the web interface
### Screenshot web interface
![screenshot](https://cloud.githubusercontent.com/assets/5656511/5182098/fbdac642-749d-11e4-9d60-a5ba838cd332.png)

### Save images
When selected one or more pictures the function will open a new tab with a _get url. ```values``` defines the images to save. 
```javascript
var url = document.URL+"back_end/save_images.php?images_arr="+values+"&group="+groupname+"&project="+projectname;
window.open(url, '_blank');
```
It's important to know that the file can't be send back over Ajax. 
The backend will create a zip file and copy the pictures into this zip.
```php
$zip = new ZipArchive();

# Create temporary zip folder on the server:
$tmp_file = tempnam('TEMP','');
$zip->open($tmp_file, ZipArchive::CREATE);

# Loop through each file and at the files to the zip folder
foreach($arr_images as $image){
	#create the path to the image
	$final = $path . $image;

	# download file
	$download_file = file_get_contents($final);
	    
	#add it to the zip
  $zip->addFromString(basename($image),$download_file);
}
# Close zip
$zip->close();
```
When all the selected picture are in the temp stored zip the php file will send headers to the browser to download the zip.
Code from [PHP Docs](http://docs.php.net/manual/da/function.readfile.php#83653)
```php
# Send the file to the browser as a download
$file_name = basename($tmp_file);

# Set the download rate limit (=> 5046 kb/s)
$download_rate = 5046;
# The temp file has no extention this will be added in to string.
$download_file_name = $file_name.'.zip';

# Check if the temp file exist and is readable
if(file_exists($tmp_file) && is_file($tmp_file))
{
  # push headers to browser
  header('Cache-control: private');
  header('Content-Type: application/octet-stream');
  header('Content-Length: '.filesize($tmp_file));
  header('Content-Disposition: filename='.$download_file_name);
  
  # Flushes the system write buffers of PHP. 
  # This attempts to push current output all the way to the browser with a few caveats.
  flush();
	$file = fopen($tmp_file, "r");
	while(!feof($file))
	{
	  # send the current file part to the browser
	  print fread($file, round($download_rate * 1024));
	  # flush the content to the browser
	  flush();
	  # sleep one second
	  sleep(1);
	}
	
	fclose($file);
}

# After download delete temp generated file
unlink($tmp_file);
```
The zip will be downloaded in the default download folder.

### Delete images
The files will be deleted on the backend. This is with a post over Ajax. All selected images are send with the current project name and group name. THe backend will check if the files exist and delete them. When finished it will reload the pictures in the browser. 
```javascript
$.ajax({
  type: "POST",
  url: "./back_end/delete_images.php",
  data: { 
    images_arr: values,
    group: groupname,
    project: projectname
  }
  })
  .done(function() {
    reload_images();
    alert("Images deleted");
  });  
```
### Select and Deselect all 
All the options will be selected with ```true``` of deselected with ```false```. 
After this action it's important to sync the imagepicker to update the changes.
```javascript
$("#check_all").click(function(){
  $('#image_grid option').prop('selected', true);
  $("#image_grid").data('picker').sync_picker_with_select();
});

$("#uncheck_all").click(function(){
  $('#image_grid option').prop('selected', false);
  $("#image_grid").data('picker').sync_picker_with_select();
});
```

### Reload images in browser
Before load new images the options will be removed inside the ```selection``` tag.
The reload function will POST to the server with Ajax to get all te pictures in the selected project and group.
The option string will be generated with the following code:
```javascript
var optionstr = "";
$.each(json, function(i, value) {
  optionstr+="<option data-img-src='./DATA/"+dropProject+"/"+dropGroup+"/"+value+"' value='"+value+"'>"+value+"</option>";
});
```
Now the options will be added in the selection.
```javascript
// send to the image grid.
$('#image_grid').html(optionstr);
// initialize the imagepicker.
$("#image_grid").imagepicker({ show_label: true });
// Retrieve the picker
$("#image_grid").data('picker');    
// Show the grid.
$('#images_grid').show();
```

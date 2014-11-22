<?php
if($_POST){
  if($_POST['project']&&$_POST['group']){
  $projname = $_POST['project'];
  $groupname = $_POST['group'];
  $path = './DATA/' . $projname . $groupname . '/';
  getContent($path);

}
else if($_POST['project'])
{
	$projname = $_POST['project'];
	$path = './DATA/' . $projname . '/';
	getContent($path);
}
else
{
	echo "error";
}
}

function getContent($_path)
{
	$allFolders = new Array();
	$results = scandir($_path);
	foreach ($results as $result) {
    if ($result === '.' or $result === '..') continue;

    if (is_dir($_path . '/' . $result)) {
        //Add to array 
    }
}
}
?>
<?php
//ini_set('display_errors', 'On');
if(isset($_POST['active'])){
  
  if(isset($_POST['project'])){
    $projname = $_POST['project'];
    $path = '../DATA/' . $projname . '/';
    getContent($path);
  }
  else {
    $path = '../DATA/';
    getContent($path);
  }
}
else
  echo "error";

function getContent($dir)
{
  $export = array();
  $results = scandir($dir);
  foreach ($results as $result) {
    if ($result === '.' or $result === '..' or $result === '' or $result[0] === '.') continue;
      $export[] = $result;
  }
  print_r($export);
}

?>
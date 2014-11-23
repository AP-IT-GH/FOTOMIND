<?php
ini_set('display_errors', 'On');
if(isset($_POST['active'])&&isset($_POST['project'])&&isset($_POST['group'])){
  $projname = $_POST['project'];
  $groupname = $_POST['group'];
  $path = '../DATA/' . $projname . '/' . $groupname . '/';
  getContent($path);
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
  echo json_encode( $export );
}

?>
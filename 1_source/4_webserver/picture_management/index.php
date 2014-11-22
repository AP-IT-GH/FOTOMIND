<!DOCTYPE html>
<html>
<head>
  <!-- Standard Meta -->
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0">

  <!-- Site Properities -->
  <title>Picture Manager - FOTOMIND</title>

  <link href='http://fonts.googleapis.com/css?family=Source+Sans+Pro:400,700|Open+Sans:300italic,400,300,700' rel='stylesheet' type='text/css'>

  <link rel="stylesheet" type="text/css" href="css/semantic.css">
  <link rel="stylesheet" type="text/css" href="css/style.css">
  <link rel="stylesheet" type="text/css" href="css/image-picker.css">

  <script src="javascript/jquery-2.1.0.min.js"></script>
  <script src="javascript/semantic.min.js"></script>
  <script src="javascript/image-picker.min.js"></script>
  <script src="javascript/core.js"></script>

</head>



<body id="home">


<div class="ui buttons">
  <div id="save_btn" class="ui green button">Save</div>
  <div class="or"></div>
  <div id="delete_btn" class="ui red button">Delete</div>
</div>


<!-- GRID  
<div class="five column doubling ui grid">
  <div class="column">
    <div class="ui segment">
      
    </div>
  </div>
  <div class="column">
    <div class="ui segment">
      
    </div>
  </div>
  <div class="column">
    <div class="ui segment">
      
    </div>
  </div>
</div>

END GRID --!>
<select multiple="multiple" class="image-picker show-labels show-html">
  <option data-img-src="http://placekitten.com/180/200" value="1">dslr0001.jpg</option>
  <option data-img-src="http://placekitten.com/180/200" value="2">dslr0002.jpg</option>
  <option data-img-src="http://placekitten.com/180/200" value="3">dslr0003.jpg</option>

</select>

</body>

</html>
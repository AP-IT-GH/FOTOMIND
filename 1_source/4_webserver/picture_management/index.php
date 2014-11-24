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

  <h1>PhotoMind</h1>
  <h2>Picture Manager</h2><br />

  <select id="project_name" >
    <option value="proj">Choose Project...</option>
  </select><br />

  <select id="group_name">
  </select><br /><br />

  <div id="images_grid">
    <!-- SAVE AND DELETE BTN -->
    <div class="ui buttons">
      <div id="save_btn" class="ui green button">Save</div>
      <div class="or"></div>
      <div id="delete_btn" class="ui red button">Delete</div>
    </div>
    <!-- CHECK UNCHECK BTN -->
    <div class="ui buttons">
      <div id="check_all" class="ui button"><i class="check square icon"></i></div>
      <div class="or"></div>
      <div id="uncheck_all" class="ui button"><i class="minus square outline icon"></i></div>
    </div>
    <br /><br />
    <!-- RELOAD BTN -->
    <div id="reload_images" class="ui icon button"><i class="refresh icon"></i></div>
    <br /><br />

    <select id="image_grid" multiple="multiple" class="image-picker show-labels show-html">
    </select>
  </div>
</body>
</html>
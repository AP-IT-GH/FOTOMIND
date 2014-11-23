$(document)
  .ready(function() {
  
    $('#delete_btn').click(function(){
      var del = confirm("Are you sure you want to delete the photos?");
      if(del)
      	alert("Photo\'s deleted!!");
      else
        alert("Photo\'s NOT deleted!!");
    });
    
    $.ajax({
      type: "POST",
      url: "./back_end/get_dir.php",
      dataType: 'json',
      data: { active: "true" }
    })
      .done(function( json ) {
        $.each(json, function(i, value) {
          $('#project_name').append($('<option>').text(value).attr('value', value));
        });
      });   

    $('#group_name').hide();

    $('#project_name').change(function () {
        var end = this.value;
        var firstDropVal = $('#project_name').val();
        if (firstDropVal != 'proj') {
          $.ajax({
            type: "POST",
            url: "./back_end/get_dir.php",
            dataType: 'json',
            data: { active: "true", project: firstDropVal }
          })
            .done(function( json ) {
              $('#group_name').empty();
              $('#group_name').append($('<option>').text('Choose Camera Group...').attr('value', 'group'));
              $.each(json, function(i, value) {
                $('#group_name').append($('<option>').text(value).attr('value', value));
              });
              
              $('#group_name').show();
            });
          }
          else 
            $('#group_name').hide();
    });

    $('#group_name').change(function () {
        alert();
    });

    $('#save_btn').click(function(){
      var values = $('#image_grid').val();
      alert(values);
      //alert("Photo\'s saved!!");
    });
  
    // Initialize the object
    $("#image_grid").imagepicker({ show_label: true });
    // Retrieve the picker
    $("#image_grid").data('picker');
      
  });
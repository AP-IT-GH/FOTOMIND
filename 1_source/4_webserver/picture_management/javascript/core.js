  $(document)
  .ready(function() {

    $('#delete_btn').click(function(){
      if ( $("#image_grid option:selected").length != 0 ) {
        var del = confirm("Are you sure you want to delete the photos?");
        if(del){
          var values = $('#image_grid').val();
          var groupname = $('#group_name').val();
          var projectname = $('#project_name').val();

          $.ajax({
            type: "POST",
            url: "./back_end/delete_images.php",
            data: { 
              images_arr: values,
              group: groupname,
              project: projectname
            }
          })
          .done(function( json ) {
            alert("Images deleted");
          });  

        }
      }
      else
        alert("First select one or more images...");
      
    });

    $('#save_btn').click(function(){
      if ( $("#image_grid option:selected").length != 0 ) {
        var values = $('#image_grid').val();
        var groupname = $('#group_name').val();
        var projectname = $('#project_name').val();

        var url = document.URL+"back_end/save_images.php?images_arr="+values+"&group="+groupname+"&project="+projectname;
        window.open(url, '_blank');
      }
      else
        alert("First select one or more images...");
    });
    
      // Initialize the object
      $("#image_grid").imagepicker({ show_label: true });
      // Retrieve the picker
      $("#image_grid").data('picker');
      
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
      $('#images_grid').hide();

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
        else {
          $('#group_name').hide();
          $('#images_grid').hide();
        }

      });

      $('#group_name').change(function () {
        var end = this.value;
        var dropGroup = $('#group_name').val();
        var dropProject = $('#project_name').val();
        if (dropGroup != 'group') {
          $.ajax({
            type: "POST",
            url: "./back_end/get_images.php",
            dataType: 'json',
            data: { active: "true", group: dropGroup, project: dropProject }
          })
          .done(function( json ) {
            $('#image_grid').empty();
            var optionstr = "";
            $.each(json, function(i, value) {
              optionstr+="<option data-img-src='http://placehold.it/200x200' value='"+value+"'>"+value+"</option>";
            });
            $('#image_grid').html(optionstr);
            $("#image_grid").imagepicker({ show_label: true });
            // Retrieve the picker
            $("#image_grid").data('picker');           
            $('#images_grid').show();
          });
        }
        else {
          $('#images_grid').hide();
        }
      });

    });
$(document)
  .ready(function() {
  
    $('#delete_btn').click(function(){
      var del = confirm("Are you sure you want to delete the photos?");
      if(del)
      	alert("Photo\'s deleted!!");
      else
        alert("Photo\'s NOT deleted!!");
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
      
    
    
      
  })
;
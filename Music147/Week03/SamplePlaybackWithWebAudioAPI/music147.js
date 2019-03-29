$(document).ready(function() {
  var videoHeight = $("#video > video").height();
  $("#script-text").height(videoHeight - 50);

  $("#toggle-script").on("click", function() {
    $("#script-text").toggle();
  });

  $(".question").on("click", function() {
    var questionId = $(this).attr("id");
    var answerID = "#answer-" + questionId.split("-")[1];
    $(answerID).toggle();
  });
});

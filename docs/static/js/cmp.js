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

//to automatically write last changed date
function fetchHeader(url, wch) {
    try {
        var req=new XMLHttpRequest();
        req.open("HEAD", url, false);
        req.send(null);
        if(req.status== 200){
            return req.getResponseHeader(wch);
        }
        else return false;
    } catch(er) {
        return er.message;
    }
}
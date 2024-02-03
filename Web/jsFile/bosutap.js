var anh=document.getElementById("slider");
var index = 0;

function next() {
    index++;
    if (index > 5) {
        index = 0;
    }
    document.getElementById('slider').src = "image/ct"+index + ".jpg";
    document.getElementById('viTri').innerText = index +1 + "/6";
}
function prev() {
    index--;
    if (index < 0) {
        index = 5;
    }
    document.getElementById('slider').src = "image/ct"+index + ".jpg";
    document.getElementById('viTri').innerText = index +1 + "/6";
}
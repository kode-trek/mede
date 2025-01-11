v_start = 0
v_stop = 0
v1 = document.querySelector("video");

function f1() {v1.pause();}
function f2() {v1.play();}

function f3() {
 v1 = document.querySelector("video");
 v1.currentTime -= 0.25;
 v_start = v1.currentTime;
 if (v1.currentTime < 0) {
  v1.pause();
  v1.currentTime = 0;
 }
}

function f4() {
 v1 = document.querySelector("video");
 v1.currentTime += 0.25;
 v_stop = v1.currentTime;
 if (v1.currentTime > v1.duration) {
  v1.pause();
  v1.currentTime = 0;
 }
}

function f5() {v_start = v1.currentTime;}
function f6() {v_stop = v1.currentTime;}

function f7() {
 document.getElementById("id-1").innerHTML +=
 "ffmpeg -ss " + v_start + " -t " + v_stop + " -i " + "" +
 " -acodec copy -vcodec copy -async 1 " + "vid_" + Date.now() + ".mp4" + "\n";
}

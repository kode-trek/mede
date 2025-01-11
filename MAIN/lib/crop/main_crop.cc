/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "proc_crop.hh"
#include "sim_crop.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[CROP] ", "blue");
 string v2 = mark( "--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "crops image/video.""\n"
  "mede crop " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede crop [inp-img/vid]""\n"
  "tells resolution of [inp-img/vid].""\n" +
  v3 + "mede crop [inp-img/vid] [x] [y] [w] [h]""\n"
  "crops [inp-img/vid] in specified dimension [x] [y] [w] [h]. "
  "produces [out-img/vid].""\n"
  "[x] x-start-point of crop-box""\n"
  "[y] y-start-point of crop-box""\n"
  "[w] width of crop-box""\n"
  "[h] height of crop-box""\n" +
  v4 + "mede crop " + quote("my-vid.avi") + " 0 0 32 24""\n"
  "crops 'my-vid.avi' in size of 'width=32, height=24' "
  "starting from 'x=0, y=0' of video-frame's top-left.""\n" +
  v4 + "mede crop " + quote("my-photo.jpg") + " 0 0 50 50""\n"
  "cuts '50x50' of 'my-photo.jpg' from top-left."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_crop(argv[2], argv[3], argv[4], argv[5], argv[6]);
  exit(0);
 }
 proc_crop(argv[1], argv[2], argv[3], argv[4], argv[5]);
}

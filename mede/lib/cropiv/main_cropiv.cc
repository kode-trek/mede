/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_cropiv.hh"
#include "sim_cropiv.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 [v4] mark-example
 */
 string v1 = mark("blue", "-- C R O P I mage V ideo --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 string v4 = mark("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "crops image/video.""\n"
  "mede cropiv " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede cropiv <inp-img/vid>""\n"
  "tells resolution of <inp-img/vid>.""\n" +
  v3 + "mede cropiv <inp-img/vid> <x> <y> <w> <h>""\n"
  "crops <inp-img/vid> in specified dimension <x> <y> <w> <h>. "
  "produces <out-img/vid>.""\n"
  "<x> x-start-point of crop-box""\n"
  "<y> y-start-point of crop-box""\n"
  "<w> width of crop-box""\n"
  "<h> height of crop-box""\n" +
  v4 + "mede cropiv " + quote("my-vid.avi") + " 0 0 32 24""\n"
  "crops 'my-vid.avi' in size of 'width=32, height=24' "
  "starting from 'x=0, y=0' of video-frame's top-left.""\n" +
  v4 + "mede cropiv " + quote("my-photo.jpg") + " 0 0 50 50""\n"
  "cuts '50x50' of 'my-photo.jpg' from top-left."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_cropiv(argv[2], argv[3], argv[4], argv[5], argv[6]);
  exit(0);
 }
 proc_cropiv(argv[1], argv[2], argv[3], argv[4], argv[5]);
}

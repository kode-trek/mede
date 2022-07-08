/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_ceniv.hh"
#include "sim_ceniv.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 [v4] mark-example
 */
 string v1 = mark("blue", "-- C E N sor I mage V ideo --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 string v4 = mark("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "censors certain part of image/video.""\n"
  "mede ceniv " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede ceniv <inp-img/vid>""\n"
  "tells resolution of <inp-img/vid>.""\n" +
  v3 + "mede ceniv <inp-img/vid> <x> <y> <w> <h> [<color>=black]""\n"
  "covers certain part of <inp-img/vid> in specified dimension <x> <y> <w> <h> "
  "with <color>-filled box. produces <out-img/vid>.""\n"
  "<x> x-start-point of cover-box""\n"
  "<y> y-start-point of cover-box""\n"
  "<w> width of cover-box""\n"
  "<h> height of cover-box""\n" +
  v4 + "mede ceniv " + quote("my-vid.avi") + " 0 0 32 24 blank""\n"
  "draws a 'glass'-filled box in size of 'width=32, height=24' starting from "
  "'x=1, y=1' top-left of 'my-vid.avi'-frame.""\n" +
  v4 + "mede ceniv " + quote("my-img.png") + " 0 0 50 50""\n"
  "draws a '50x50' 'black'-filled box on picture's top-left."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_ceniv(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
  exit(0);
 }
 proc_ceniv(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

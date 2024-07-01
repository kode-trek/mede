/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "../media.hh"
#include "proc_cen_pt1.hh"
#include "proc_cen.hh"
#include "sim_cen.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[CENsor] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "censors certain part of image/video.""\n"
  "mede cen " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede cen [inp-img/vid]""\n"
  "tells resolution of [inp-img/vid].""\n" +
  v3 + "mede cen [inp-img/vid] [x] [y] [w] [h] [color=black]""\n"
  "covers certain part of [inp-img/vid] in specified dimension [x] [y] [w] [h] "
  "with [color]-filled box. produces [out-img/vid].""\n"
  "[x] x-start-point of cover-box""\n"
  "[y] y-start-point of cover-box""\n"
  "[w] width of cover-box""\n"
  "[h] height of cover-box""\n" +
  v4 + "mede cen " + quote("my-vid.avi") + " 0 0 32 24 blank""\n"
  "draws a 'glass'-filled box in size of 'width=32, height=24' starting from "
  "'x=1, y=1' top-left of 'my-vid.avi'-frame.""\n" +
  v4 + "mede cen " + quote("my-img.png") + " 0 0 50 50""\n"
  "draws a '50x50' 'black'-filled box on picture's top-left."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_cen(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
  exit(0);
 }
 proc_cen(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

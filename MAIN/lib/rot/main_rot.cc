/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "proc_rot.hh"
#include "sim_rot.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[ROTate] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "rotates image/video.""\n"
  "mede rot " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede rot [inp-img/vid] [orientation=left]""\n"
  "rotates [inp-img/vid] to specified [orientation]. produces rotated "
  "[out-img/vid]. ""\n"
  "[orientation] directions: right | left | flip | up-side-down""\n" +
  v4 + "mede rot 'my-vid.avi""\n"
  "rotates 'my-vid.avi' counter-clockwise.""\n" +
  v4 + "mede rot " + quote("my-photo.png") + " flip""\n"
  "mirrors 'my-photo.png'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "SIM") {
  sim_rot(argv[2], argv[3]);
  exit(0);
 }
 proc_rot(argv[1], argv[2]);
}

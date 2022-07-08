/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_rotiv.hh"
#include "sim_rotiv.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 [v4] mark-example
 */
 string v1 = mark("blue", "-- R O T ate I mage V ideo --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 string v4 = mark("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "rotates image/video.""\n"
  "mede rotiv " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede rotiv <inp-img/vid> [<orientation>=left]""\n"
  "rotates <inp-img/vid> to specified <orientation>. produces rotated "
  "<out-img/vid>. ""\n"
  "<orientation> directions: right | left | flip | up-side-down""\n" +
  v4 + "mede rotiv " + quote("my-vid.avi") + "\n"
  "rotates 'my-vid.avi' counter-clockwise.""\n" +
  v4 + "mede rotiv " + quote("my-photo.png") + " flip""\n"
  "mirrors 'my-photo.png'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_rotiv(argv[2], argv[3]);
  exit(0);
 }
 proc_rotiv(argv[1], argv[2]);
}

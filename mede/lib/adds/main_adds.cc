/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_adds.hh"
#include "sim_adds.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 */
 string v1 = mark("blue", "-- A D D S ubtitle --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "adds hard subtitles to video.""\n"
  "mede adds " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede adds <inp-sub.SRT> <inp-vid>""\n"
  "attaches <inp-sub.SRT> to <inp-vid>. produces <out-vid>."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_adds(argv[2], argv[3]);
  exit(0);
 }
 proc_adds(argv[1], argv[2]);
}

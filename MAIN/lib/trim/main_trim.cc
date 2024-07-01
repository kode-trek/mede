/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "../media.hh"
#include "proc_trim.hh"
#include "sim_trim.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[TRIM] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "trims media.""\n"
  "mede trim " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede trim [inp-med] [start] [stop] [mode=default]""\n"
  "trims [inp-med] from ([start] up to [stop])-time. produces [out-med]""\n"
  "if [default] might not be promising""\n"
  "if [precise] might be slow. very accurate""\n"
  "if [glance] super fast. incorrect timing.""\n" +
  v4 + "mede trim " + quote("my-vid.avi") + " 2:40 4:05.10""\n"
  "cuts 'my-vid.avi'""\n"
  "from '2-min and 40-sec'""\n"
  "to '4-min and 5-sec and 10-msec'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_trim(argv[2], argv[3], argv[4], argv[5]);
  exit(0);
 }
 proc_trim(argv[1], argv[2], argv[3], argv[4]);
}

/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_trimm.hh"
#include "sim_trimm.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 [v4] mark-example
 */
 string v1 = mark("blue", "-- T R I M M edia --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 string v4 = mark("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "trims media-file.""\n"
  "mede trimm " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede trimm <inp-med> <start> <stop>""\n"
  "trims <inp-med> from (<start> up to <stop>)-time. "
  "produces <out-med>""\n" +
  v4 + "mede trimm " + quote("my-vid.avi") + " 2:40 4:05.10""\n"
  "cuts 'my-vid.avi'""\n"
  "from '2-min and 40-sec'""\n"
  "to '4-min and 5-sec and 10-msec'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_trimm(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_trimm(argv[1], argv[2], argv[3]);
}

/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_meta.hh"
#include "sim_meta.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 */
 string v1 = mark("blue", "-- M E T A data --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "elicits meta-data of media.""\n"
  "mede meta " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede meta <inp-med>""\n"
  "elicits and displays meta-data and stream(s) in <inp-med>."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_meta(argv[2]);
  exit(0);
 }
 proc_meta(argv[1]);
}

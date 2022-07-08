/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_ena.hh"
#include "sim_ena.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 */
 string v1 = mark("blue", "-- E N umerate A ll --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "enumerates file(s) from N to (N + n).""\n"
  "mede ena " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede ena <dir> [<N>=1] [<initial>=_]""\n"
  "renames all file(s) in <dir>ectory initiating with <_N>."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_ena(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_ena(argv[1], argv[2], argv[3]);
}

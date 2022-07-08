/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_cdup.hh"
#include "sim_cdup.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 */
 string v1 = mark("blue", "-- C luster DUP licate --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "clusters file(s) by size into multiple group(s).""\n"
  "mede cdup " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + " mede cdup <dir>""\n"
  "clusters file(s) within <dir>ectory into multiple folder(s) containing "
  "files of""\n""the same size."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_cdup(argv[2]);
  exit(0);
 }
 proc_cdup(argv[1]);
}

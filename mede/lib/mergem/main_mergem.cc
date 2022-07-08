/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_mergem.hh"
#include "sim_mergem.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 [v4] mark-example
 */
 string v1 = mark("blue", "-- M E R G E M edia --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 string v4 = mark("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "merges multiple media-file(s) into one whole.""\n"
  "mede mergem " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede mergem <dir>""\n"
  "merges multiple media-file(s) of <dir>ectory into one whole <med-out>.""\n" +
  v4 + "mede mergem " + quote("my-dir") + "\n"
  "all files inside 'my-dir' must be of the same format (ex. 3gpp), same "
  "resolution (ex. 800x600), etc. otherwise it might be led to unexpected "
  "result."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_mergem(argv[2]);
  exit(0);
 }
 proc_mergem(argv[1]);
}

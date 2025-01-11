/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "proc_merge.hh"
#include "sim_merge.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[MERGE] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "merges multiple audio/video-file(s) into one whole.""\n"
  "mede merge " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede merge [dir]""\n"
  "merges multiple media-file(s) in [dir]ectory into one whole [med-out].""\n" +
  v4 + "mede merge " + quote("my-dir") + "\n"
  "all files inside 'my-dir' must be of the same format (ex. 3gpp), same "
  "resolution (ex. 800x600), etc. otherwise the result would not be promising."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_merge(argv[2]);
  exit(0);
 }
 proc_merge(argv[1]);
}

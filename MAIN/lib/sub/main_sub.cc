/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "proc_sub.hh"
#include "sim_sub.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[SUBtitle] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "adds subtitles to video.""\n"
  "mede sub " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede sub [inp-sub.SRT] [inp-vid] [sub-mode=soft]""\n"
  "attaches [inp-sub.SRT] to [inp-vid]. produces [out-vid].""\n"
  "if [soft] adds transcripts to video.""\n"
  "if [hard] attaches hard subtitles to video. might take time."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_sub(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_sub(argv[1], argv[2], argv[3]);
}

/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "proc_meta.hh"
#include "sim_meta.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[METAdata] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "elicits meta-data including stream(s) of media.""\n"
  "mede meta " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede meta [inp-med]""\n"
  "elicits and displays meta-data/stream(s) in [inp-med]."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_meta(argv[2]);
  exit(0);
 }
 proc_meta(argv[1]);
}

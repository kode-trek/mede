/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "proc_snap.hh"
#include "sim_snap.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[SNAPshot] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "takes screenshot.""\n"
  "converts image to (up/de)-graded quality JPEG.""\n"
  "combines multiple image(s) into one PDF.""\n"
  "combines multiple image(s) into one video-clip.""\n"
  "records screen.""\n"
  "converts video to GIF.""\n"
  "mede snap " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede snap --shot""\n"
  "takes screen-shot.""\n" +
  v3 + "mede snap --jpg [inp-img] [quality-percentage=100]""\n"
  "converts [inp-img] to [out-img.JPG].""\n" +
  v3 + "mede snap --pdf [img/dir]""\n"
  "converts [image] to [out-doc.PDF].""\n"
  "combines multiple images within [dir]ectory onto [out-doc.PDF].""\n" +
  v3 + "mede snap --mov [img/dir] [delay=on]""\n"
  "converts [image] to [out-vid.MP4].""\n"
  "combines multiple image(s) within [dir]ectory into [out-vid.MP4].""\n"
  "[on] delays 128ms-gap among frames.""\n"
  "[off] displays slides with no pause.""\n" +
  v3 + "mede snap --roll""\n"
  "records screen.""\n" +
  v3 + "mede snap --gif [inp-vid]""\n"
  "converts [inp-vid] to [out-img.GIF]. resizes [out-img.GIF] to W=320:H "
  "resolution while preserving aspect-ratio."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_snap(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_snap(argv[1], argv[2], argv[3]);
}

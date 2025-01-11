/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "../media.hh"
#include "proc_laud_pt1.hh"
#include "proc_laud.hh"
#include "sim_laud.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[Leak AUDio] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "lists audio-track(s) in media.""\n"
  "mutes video.""\n"
  "blinds screen.""\n"
  "extracts sound from video.""\n"
  "mede laud " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede laud --aud [inp-med]""\n"
  "lists audio-tracks of [inp-med].""\n" +
  v3 + "mede laud --[d]mute [inp-vid]""\n"
  "converts [inp-vid] to silent [out-vid].""\n"
  "[--mute] decreases volume of media to zero. takes longer.""\n"
  "[--dmute] eliminates any audio-track(s) in media. faster but not reliable."
  "\n" +
  v3 + "mede laud --icu [inp-vid]""\n"
  "eliminates video-track of [inp-vid]. produces full-black-screen [out-vid]."
  "\n" +
  v3 + "mede laud --sound [inp-med] [aud=0]""\n"
  "extracts [0:aud] track from [inp-med]. produces [out-aud.MP3].""\n" +
  v4 + "mede laud --sound " + quote("my-midi.mid") + "\n"
  "converts 'my-midi.mid' to 'my-midi.mp3'.""\n" +
  v4 + "mede laud --sound " + quote("my-vid.mkv") + " 2""\n"
  "extracts '0:2' audio-track of 'my-vid.mkv'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_laud(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_laud(argv[1], argv[2], argv[3]);
}

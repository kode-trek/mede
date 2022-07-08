/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_laud.hh"
#include "sim_laud.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 [v4] mark-example
 */
 string v1 = mark("blue", "-- L eak A U D io --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 string v4 = mark("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "mutes video.""\n"
  "blinds screen.""\n"
  "extracts sound from media.""\n"
  "converts MIDI to MP3.""\n"
  "mede laud " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede laud --aud <inp-med>""\n"
  "enlists audio-tracks of <inp-med>.""\n" +
  v3 + "mede laud --(d)mute <inp-vid>""\n"
  "converts <inp-vid> to silent <out-vid>.""\n"
  "if (--mute) attaches zero-sound to media. takes longer.""\n"
  "if (--dmute) dirty-mute is faster but not reliable.""\n" +
  v3 + "mede laud --icu <inp-vid>""\n"
  "eliminates video-track of <inp-vid>. produces full-black-screen <out-vid>."
  "\n" +
  v3 + "mede laud --sound <inp-med> [<aud>=0]""\n"
  "extracts <0:aud> track from <inp-med>. produces <out-aud.MP3>.""\n" +
  v4 + "mede laud --sound " + quote("my-midi.mid") + "\n"
  "converts 'my-midi.mid' to 'my-midi.mp3'.""\n" +
  v4 + "mede laud --sound " + quote("my-vid.avi") + " 2""\n"
  "extracts '0:2' audio-track of 'my-vid.avi'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_laud(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_laud(argv[1], argv[2], argv[3]);
}

/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "proc_pubm.hh"
#include "sim_pubm.hh"
int main(int argc, char* argv[]) {
 /* variable(s)
 [v1] mark-title
 [v2] mark-help
 [v3] mark-pattern
 [v4] mark-example
 */
 string v1 = mark("blue", "-- P U B lish M edia --");
 string v2 = mark("blue", "--help");
 string v3 = mark("blue", "[PATTERN] ");
 string v4 = mark("blue", "[EXAMPLE] ");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "\n"
  "prepares media-file for publishin' on the web.""\n"
  "mede pubm " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede pubm <inp-med> [<vid>=0] [<aud>=0]""\n"
  "converts <inp-med> to <out-vid.MP4> or <out-aud.MP3>. produces "
  "<out-player.HTM> with <out-med> referred.""\n"
  "if (vid/aud) maps '0:vid' and '0:aud' of <inp-med> to <out-med.MP4>.""\n" +
  v4 + "mede pubm " + quote("my-vid.mkv") + " 0 2""\n"
  "maps '0:0' video-track and '0:2' audio-track of 'my-vid.mkv' to "
  "'my-vid_POLISHED_*.mp4' referred in 'my-vid_PLAYER_*.htm'.""\n" +
  v4 + "mede pubm " + quote("my-music.ogg") + "\n"
  "converts mono-channel 'my-music.ogg' to 'my-music_POLISHED_*.mp3' along "
  "with 'my-music_PLAYER_*.htm'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_pubm(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_pubm(argv[1], argv[2], argv[3]);
}

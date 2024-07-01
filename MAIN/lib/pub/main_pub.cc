/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"
#include "../media.hh"
#include "proc_pub_pt1.hh"
#include "proc_pub.hh"
#include "sim_pub.hh"

int main(int argc, char* argv[]) {
 string v1 = mark("[PUBlish] ", "blue");
 string v2 = mark("--help", "blue");
 string v3 = mark("[PATTERN] ", "blue");
 string v4 = mark("[EXAMPLE] ", "blue");
 // op(s)
 if (str(argv[1]) == "") {
  cout <<
  v1 + "prepares media-file for publishin' on the web.""\n"
  "mede pub " + v2
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--help") {
  cout <<
  v3 + "mede pub [inp-med] [vid=0] [aud=0]""\n"
  "converts [inp-med] to [out-vid.MP4] or [out-aud.MP3]. produces "
  "[out-player.HTM] with [out-med] referred.""\n"
  "[vid][aud] maps '0:vid' and '0:aud' of [inp-med] to [out-med.MP4].""\n" +
  v4 + "mede pub " + quote("my-vid.mkv") + " 0 2""\n"
  "maps '0:0' video-track and '0:2' audio-track of 'my-vid.mkv' to "
  "'my-vid_POLISHED_*.mp4' referred in 'my-vid_PLAYER_*.htm'.""\n" +
  v4 + "mede pub " + quote("my-music.ogg") + "\n"
  "converts mono-channel 'my-music.ogg' to 'my-music_POLISHED_*.mp3' along "
  "with 'my-music_PLAYER_*.htm'."
  << endl;
  exit(0);
 }
 if (str(argv[1]) == "--sim") {
  sim_pub(argv[2], argv[3], argv[4]);
  exit(0);
 }
 proc_pub(argv[1], argv[2], argv[3]);
}

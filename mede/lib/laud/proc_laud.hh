/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "../media.hh"
bool is_midi(string arg1) {
 /* variable(s)
 [v1] input-media
 [v2] temporary-text-file
 */
 string cmd = mark("blue", "[] ");
 string err1 = mark("yellow", "[WARNING] ");
 //
 string v1 = arg1;
 string v2 = ts();
 // command(s)
 string cmd1 = "echo `file -b --mime-type " + quote(v1) + "` > " + v2;
 // op(s)
 if (not write_access()) {
  cout << err1 + "write-permission denied!" << endl;
  exit(1);
 }
 int e = sys(cmd1);
 if ((cat(v2).txt).substr(0, (cat(v2).txt).size() - 1) == "audio/midi") {
  rm(v2);
  return 1;
 }
 else {
  rm(v2);
  return 0;
 }
}
void proc_laud(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input-media
 [v3] extension
 [v4] audio-track
 [v5] map
 [v6] output-media
 [med] media-info
 0: number-of-video-track(s)
 1: number-of-audio-track(s)
 2: number-of-channel(s)
 3: media-type (1:video-only 2:audio-only 3:aud/vid/sub)
 */
 string inp1 = mark("blue", "[inp] ");
 string cmd = mark("blue", "[] ");
 string out1 = mark("blue", "[out] ");
 string out2 = mark("green", "DONE.");
 string err1 = mark("yellow", "[WARNING] ");
 string err2 = mark("red", "HALTED.""\n""[FAILED] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 can(v2);
 vector<int> med = meds(v2);
 string v3 = "";
 v3 = uri(v2)[3];
 if (v3 == "") v3 = ".mp4";
 string v4 = arg3;
 if (med[3] == 2) v4 = "0";
 if ((med[1] > 1) and (v4 == "")) v4 = "1";
 if (v4 == "") v4 = "a";
 string v5 = "";
 for (int i = 0; i < med[2]; i++) v5 += " -map 0:" + str(i) + "?";
 string v6 = "";
 if (v1 == "--mute") v6 = uri(v2)[2] + "_MUTED_" + ts() + v3;
 if (v1 == "--dmute") v6 = uri(v2)[2] + "_DIRTY-MUTED_" + ts() + v3;
 if (v1 == "--icu") v6 = uri(v2)[2] + "_BLINDED_" + ts() + v3;
 if (v1 == "--sound") v6 = uri(v2)[2] + "_SOUND_" + ts() + ".mp3";
 // message(s)
 string msg1 = cmd + "audio-track(s) found in media...";
 string msg2 =
 inp1 + uri(v2)[1] + "\n" +
 out1 + uri(v6)[1] + "\n" +
 cmd + "eliminating sound in media...";
 string msg3 =
 inp1 + uri(v2)[1] + "\n" +
 out1 + uri(v6)[1] + "\n" +
 cmd + "eliminating video in media...";
 string msg4 =
 inp1 + uri(v2)[1] + "\n" +
 out1 + uri(v6)[1] + "\n" +
 cmd + "extracting sound from media...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v2) + " 2>&1 | grep -oP 'Stream .* Audio'";
 string cmd2 = "ffmpeg -i " + quote(v2) + " -f lavfi -t 0.1 -i "
 "anullsrc -filter_complex '[0:v:0][1:a] concat=n=1:v=1:a=1' " + quote(v6);
 string cmd3 = "ffmpeg -i " + quote(v2) + " -c copy -an " + quote(v6);
 string cmd4 = "ffmpeg -i " + quote(v2) + " -vf "
 "drawbox=x=0:y=0:w=0:h=0:color=black@1:t=fill" + v5 + " " + quote(v6);
 string cmd5 = "timidity " + quote(v2) + " -Ow -o - 2>/dev/null | ffmpeg -i - "
 "-acodec libmp3lame -ab 64k " + quote(v6);
 string cmd6 = "ffmpeg -i " + quote(v2) + " -map 0:" + v4 + " -vf "
 "tblend=all_mode=grainextract -map_metadata -1 -map_chapters -1" + " -c:a "
 "libmp3lame " + quote(v6);
 // op(s)
 if (v1 == "--aud") {
  if (is_midi(v2)) {
   cout << err1 + "media is MIDI." << endl;
   exit(0);
  }
  note(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << mark("yellow", "NONE.") << endl;
   exit(0);
  }
  cout << endl;
  sys(cmd1 + " 2>/dev/null");
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (med[3] == 2)) {
  cout << err1 + "media is an audio-type." << endl;
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (is_midi(v2))) {
  cout << err1 + "media is an audio-type." << endl;
  exit(0);
 }
 if (v1 == "--mute") {
  note(msg2);
  e = sys(cmd2 + " -y 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd2 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
  exit(0);
 }
 if (v1 == "--dmute") {
  note(msg2);
  e = sys(cmd3 + " -y 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd3 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
  exit(0);
 }
 if ((v1 == "--icu") and (med[3] == 2)) {
  cout << err1 + "no video-track found in media." << endl;
  exit(0);
 }
 if ((v1 == "--icu") and (is_midi(v2))) {
  cout << err1 + "no video-track found in media." << endl;
  exit(0);
 }
 if (v1 == "--icu") {
  note(msg3);
  e = sys(cmd4 + " -y 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd4 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (med[3] == 1)) {
  cout << err1 + "media is muted." << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (is_midi(v2))) {
  note(msg4);
  e = sys(cmd5 + " -y 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd5 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
  exit(0);
 }
 if (v1 == "--sound") {
  note(msg4);
  e = sys(cmd6 + " -y 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd6 << endl;
   rm(v6);
   exit(1);
  }
  cout << out2 << endl;
  exit(0);
 }
}

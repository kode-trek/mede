/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "../media.hh"
void proc_pubm(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] input-media
 [v2] video-track
 [v3] audio-track
 [v4] output-media
 [v5] output-audio
 [v6] output-player
 [v7] video-html5-code
 [v8] audio-html5-code
 [v9] map
 [med] media-info
 0: number-of-video-track(s)
 1: number-of-audio-track(s)
 2: number-of-channel(s)
 3: media-type (1:video-only 2:audio-only 3:aud/vid/sub)
 [inp] mark-input
 [cmd] mark-command
 [out] mark-output
 [err] mark-error/warning
 */
 string inp1 = mark("blue", "[inp] ");
 string cmd = mark("blue", "[] ");
 string out1 = mark("blue", "[out] ");
 string out2 = mark("green", "DONE.");
 string err1 = mark("red", "HALTED.""\n""[FAILED] ");
 //
 string v1 = arg1;
 can(v1);
 vector<int> med = meds(v1, true);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = uri(v1)[2] + "_POLISHED_" + ts() + ".mp4";
 string v5 = uri(v1)[2] + "_POLISHED_" + ts() + ".mp3";
 string v6 = uri(v1)[2] + "_PLAYER_" + ts() + ".htm";
 string v7 =
 "<video controls width='640' length='320'>""\n"
 "<source src=" + quote(v4) + ">""\n"
 "</video>";
 string v8 =
 "<audio controls>""\n"
 "<source src=" + quote(v5) + ">""\n"
 "</audio>";
 string v9 = " -map 0:0 -map 0:a";
 // message(s)
 string msg1 =
 inp1 + uri(v1)[1] + "\n" +
 out1 + uri(v6)[1] + "\n" +
 out1 + uri(v4)[1] + "\n" +
 cmd + "preparing media to get published...";
 string msg2 =
 inp1 + uri(v1)[1] + "\n" +
 out1 + uri(v6)[1] + "\n" +
 out1 + uri(v5)[1] + "\n" +
 cmd + "preparing media to get published...";
 string msg3 =
 inp1 + uri(v1)[1] + "\n" +
 out1 + uri(v6)[1] + "\n" +
 out1 + uri(v4)[1] + "\n" +
 cmd + "preparing media to get published...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) + " -map_metadata -1 -map_chapters -1 "
 "-pix_fmt yuv320p -vcodec libx264 -acodec avc " + quote(v4);
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf tblend=all_mode=grainextract "
 "-map_metadata -1 -map_chapters -1 -c:a libmp3lame " + quote(v5);
 string cmd3 = "";
 if ((v2 == "") or (v3 == "")) {
  cmd3 = "ffmpeg -i " + quote(v1) + v9 + " -map_metadata -1 -map_chapters -1 "
  "-strict experimental -c:a aac -async 1 " + quote(v4);
 } else {
  cmd3 = "ffmpeg -i " + quote(v1) + " -map 0:" + v2 + " -map 0:" + v3 +
  " -map_metadata -1 -map_chapters -1 -strict experimental -c:a aac -async 1 "
  + quote(v4);
 }
 // op(s)
 if (med[3] == 1) {
  note(msg1);
  e = sys(cmd1 + " -y 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   rm(v4);
   exit(1);
  }
  drop(v6, v7);
  cout << out2 << endl;
  exit(0);
 }
 if (med[3] == 2) {
  note(msg2);
  e = sys(cmd2 + " -y 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   rm(v4);
   exit(1);
  }
  drop(v6, v8);
  cout << out2 << endl;
  exit(0);
 }
 note(msg3);
 e = sys(cmd3 + " -y 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err1 + cmd3 << endl;
  rm(v4);
  exit(1);
 }
 drop(v6, v7);
 cout << out2 << endl;
}

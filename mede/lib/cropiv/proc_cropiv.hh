/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "../media.hh"
void proc_cropiv(
 string arg1,
 string arg2,
 string arg3,
 string arg4,
 string arg5
 ) {
 /* variable(s)
 [v1] input-media
 [v2] x-box
 [v3] y-box
 [v4] w-box
 [v5] h-box
 [v6] box
 [v7] map
 [v8] extension
 [v9] output-media
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
 vector<int> med = meds(v1);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = arg4;
 string v5 = arg5;
 string v6 = "crop=x=" + v2 + ":y=" + v3 + ":w=" + v4 + ":h=" + v5;
 string v7 = "";
 for (int i = 0; i < med[2]; i++) v7 += " -map 0:" + str(i) + "?";
 string v8 = "";
 v8 = uri(v1)[3];
 if (v8 == "") v8 = ".mp4";
 string v9 = uri(v1)[2] + "_CROPPED_" + ts() + v8;
 // message(s)
 string msg1 = cmd + "aspect-ratio: ";
 string msg2 =
 inp1 + uri(v1)[1] + "\n" +
 out1 + uri(v9)[1] + "\n" +
 cmd + "cropping image/video...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf " + v6 + v7 + " " + quote(v9);
 // op(s)
 if (arg2 == "") {
  note(msg1);
  e = sys(cmd1);
  if (e) {
   cout << endl;
   exit(1);
  }
  exit(0);
 }
 note(msg2);
 e = sys(cmd2 + " -y 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err1 + cmd2 << endl;
  rm(v9);
  exit(1);
 }
 cout << out2 << endl;
}

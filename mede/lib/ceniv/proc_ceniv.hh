/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
#include "../media.hh"
vector<int> aspect_ratio(string arg1) {
 /* variable(s)
 [v1] input-media
 [v2] width
 [v3] height
 [v4] temporary-text-file
 [v5] aspect-ratio
 [err] mark-error/warning
 */
 string err1 = mark("yellow", "[WARNING] ");
 //
 string v1 = arg1;
 int v2, v3 = 0;
 string v4 = "." + ts();
 vector<string> v5 = {};
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 // op(s)
 if (not write_access()) {
  cout << err1 + "write-permission denied!" << endl;
  exit(1);
 }
 sys(cmd1 + " > " + v4);
 v5 = split(cat(v4).txt, "x");
 rm(v4);
 try {v2 = str2num(v5[0]);} catch (...) {v2 = 0;}
 try {v3 = str2num(v5[1]);} catch (...) {v3 = 0;}
 return {v2, v3};
}
string win(string arg1, string arg2, string arg3, string arg4, string arg5) {
 /* variable(s)
 [v1] input-media
 [v2] x-box-input
 [v3] y-box-input
 [v4] w-box-input
 [v5] h-box-input
 [v6] x-box-integer
 [v7] y-box-integer
 [v8] w-box-integer
 [v9] h-box-integer
 [v10] w-box-calculated
 [v11] h-box-calculated
 [v12] dimension
 [v13] box
 */
 string v1 = arg1;
 string v2 = arg2;
 if (v2 == "0") v2 = "1";
 string v3 = arg3;
 if (v3 == "0") v3 = "1";
 string v4 = arg4;
 string v5 = arg5;
 int v6, v7, v8, v9 = 0;
 try {v6 = str2num(v2);} catch (...) {v6 = 1;}
 try {v7 = str2num(v3);} catch (...) {v7 = 1;}
 try {v8 = str2num(v4);} catch (...) {v8 = 0;}
 try {v9 = str2num(v5);} catch (...) {v9 = 0;}
 int v10, v11 = 0;
 try {v10 = aspect_ratio(v1)[0];} catch (...) {v10 = 0;}
 try {v11 = aspect_ratio(v1)[1];} catch (...) {v11 = 0;}
 string v12 = "x=:y=:w=:h=";
 string v13 = "delogo=" + v12;
 // op(s)
 if ((v6 + v8) >= v10) v8 = v10 - v6 - 1;
 if ((v7 + v9) >= v11) v9 = v11 - v7 - 1;
 v2 = str(v6);
 v3 = str(v7);
 v4 = str(v8);
 v5 = str(v9);
 v12 = "x=" + v2 + ":" + "y=" + v3 + ":" + "w=" + v4 + ":" + "h=" + v5;
 v13 = "delogo=" + v12;
 return v13;
}
void proc_ceniv (
 string arg1,
 string arg2,
 string arg3,
 string arg4,
 string arg5,
 string arg6
 ) {
 /* variable(s)
 [v1] input-media
 [v2] <x>-box
 [v3] <y>-box
 [v4] <w>-box
 [v5] <h>-box
 [v6] dimension
 [v7] input-color
 [v8] box
 [v9] map
 [v10] extension
 [v11] output-media
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
 string v6 = "x=" + v2 + ":y=" + v3 + ":w=" + v4 + ":h=" + v5;
 string v7 = arg6;
 if (v7 == "") v7 = "black";
 string v8 = "drawbox=" + v6 + ":color=" + v7 + "@1:t=fill";
 if (v7 == "blank") v8 = win(v1, v2, v3, v4, v5);
 string v9 = "";
 for (int i = 0; i < med[2]; i++) v9 += " -map 0:" + str(i) + "?";
 string v10 = "";
 v10 = uri(v1)[3];
 if (v10 == "") v10 = ".mp4";
 string v11 = uri(v1)[2] + "_CENSORED_" + ts() + v10;
 // message(s)
 string msg1 = cmd + "aspect-ratio: ";
 string msg2 =
 inp1 + uri(v1)[1] + "\n" +
 out1 + uri(v11)[1] + "\n" +
 cmd + "covering image/video...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf " + v8 + v9 + " " + quote(v11);
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
  rm(v11);
  exit(1);
 }
 cout << out2 << endl;
}

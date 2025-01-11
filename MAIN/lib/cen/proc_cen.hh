/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_cen (
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
 [v9] extension
 [v10] output-media
 [f1] window-frame
 */
 string inp1 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("[WARNING] ", "yellow");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
 string err2_ = mark("[FAILED] ", "red");
 //
 string v1 = can(arg1);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = arg4;
 string v5 = arg5;
 string v6 = "x=" + v2 + ":y=" + v3 + ":w=" + v4 + ":h=" + v5;
 string v7 = arg6;
 if (v7 == "") v7 = "black";
 string v8 = "drawbox=" + v6 + ":color=" + v7 + "@1:t=fill";
 if (v7 == "blank") v8 = f1(v1, v2, v3, v4, v5);
 string v9 = uri(v1, "extension");
 if (v9 == "") v9 = ".mkv";
 string v10 = uri(v1, "file-name") + "_CENSORED_" + ts() + v9;
 // message(s)
 string msg1 = cmd + "aspect-ratio: ";
 string msg2 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v10, "full-name") + "\n" +
 cmd + "covering image/video...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + " -map 0:v? -map 0:a? -map 0:s? -vf " + v8 + " " + quote(v10);
 string cmd2_ = "ffmpeg -i " + quote(v1) + " -vf " + v8 + " " + quote(v10);
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
 volume_f1(v1, true);
 volume_f2(true);
 note(msg2);
 e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
 if (e) {
  rm(v10);
  e = sys(cmd2_ + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd2_ << endl;
   rm(v10);
  }
  if (not e) {
   cout << out2 << endl;
   cout << err1 + "not all stream(s) mapped." << endl;
   exit(0);
  }
  cout << err2_ + cmd2 << endl;  
  exit(1);
 }
 cout << out2 << endl;
}

/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_rot(string arg1, string arg2) {
 /* variable(s)
 [v1] input-media
 [v2] input-transpose
 [v3] transpose-code
 [v4] extension
 [v5] output-media
 */
 string inp1 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 string err1_ = mark("[FAILED] ", "red");
 string err2 = mark("WARNING] ", "red");
 //
 string v1 = can(arg1);
 string v2 = arg2;
 if (v2 == "") v2 = "left";
 string v3 = "";
 if ((v2 == "right") or (v2 == "--right")) v3 = "transpose=1";
 if ((v2 == "left") or (v2 == "--left")) v3 = "transpose=2";
 if ((v2 == "flip") or (v2 == "--flip")) v3 = "transpose=0, transpose=1";
 if ((v2 == "up-side-down") or (v2 == "--up-side-down"))
  v3 = "transpose=1, transpose=1";
 string v4 = uri(v1, "extension");
 if (v4 == "") v4 = ".mkv";
 string v5 = uri(v1, "file-name") + "_ROTATED_" + ts() + v4;
 // message(s)
 string msg1 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v5, "full-name") + "\n" +
 cmd + "rotating media...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) +
 " -map 0:v? -map 0:a? -map 0:s? -vf " + quote(v3) + " " + quote(v5);
 string cmd1_ = "ffmpeg -i " + quote(v1) + " -vf " + quote(v3) + " " + quote(v5);
 // op(s)
 volume_f1(v1, true);
 note(msg1);
 e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
 if (e) {
  rm(v5);
  e = sys(cmd1_ + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1_ << endl;
   rm(v5);
  }
  if (not e) {
   cout << out2 << endl;
   cout << err2 + "not all stream(s) mapped." << endl;
   exit(0);
  }
  cout << err1_ + cmd1 << endl;  
  exit(1);
 }
 cout << out2 << endl;
}

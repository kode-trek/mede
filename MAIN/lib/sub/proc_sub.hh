/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_sub(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] input-subtitle
 [v2] input-media
 [v3] transcript-type
 [v4] extension
 [v5] output-media
 */
 string inp1 = mark("[INP-SUB] ", "blue");
 string inp2 = mark("[INP-MED] ", "blue");
 string inp3 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = can(arg1);
 string v2 = can(arg2);
 string v3 = arg3;
 if (v3 == "") v3 = "soft";
 string v4 = uri(v2, "extension");
 if (v4 == "") v4 = ".mkv";
 string v5 = uri(v2, "file-name") + "_SUBBED_" + ts() + v4;
 if ((v3 == "soft") or (v3 == "--soft"))
  v5 = uri(v2, "file-name") + "_SOFT_SUB_" + ts() + v4;
 if ((v3 == "hard") or (v3 == "--hard"))
  v5 = uri(v2, "file-name") + "_HARD_SUB_" + ts() + v4;
 // message(s)
 string msg1 =
 inp1 + uri(v1, "full-name") + "\n" +
 inp2 + uri(v2, "full-name") + "\n" +
 out1 + uri(v5, "full-name") + "\n" +
 cmd + "adding soft subtitles to media...";
 string msg2 =
 inp1 + uri(v1, "full-name") + "\n" +
 inp2 + uri(v2, "full-name") + "\n" +
 out1 + uri(v5, "full-name") + "\n" +
 cmd + "attaching hard subtitles to media...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v2) + + " -i " + quote(v1) + " -c copy " +
 quote(v5);
 string cmd1_ = "ffmpeg -i " + quote(v2) + + " -i " + quote(v1) + " -map0:v? -map0:a? -map0:s? -c copy " +
 quote(v5);
 string cmd2 = "ffmpeg -i " + quote(v2) + " -vf subtitles=" + quote(v1) + " " +
 quote(v5);
 string cmd2_ = "ffmpeg -i " + quote(v2) + " -map0:v? -map0:a? -map0:s? -vf subtitles=" + quote(v1) + " " +
 quote(v5);
 // op(s)
 volume_f1(v2, true);
 if (not exist(v1)) {
  cout << "FILE NOT FOUND." << endl;
  exit(0);
 }
 if ((mime(v1, "type") == "text") and (v2 == "")) {
  cout << "TEXT" << endl;
  exit(0);
 }
 if (mime(v1, "type") != "text") {
  cout << "NON-TEXT" << endl;
  exit(0);
 }
 if ((v3 == "soft") or (v3 == "--soft")) {
  note(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   rm(v5);
   exit(e);
  }
 }
 if ((v3 == "hard") or (v3 == "--hard")) {
  note(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   rm(v5);
   exit(e);
  }
 }
 cout << out2 << endl;
}

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
 [v4] map
 [v5] extension
 [v6] output-media
 */
 string inp1 = mark("[inp] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[out] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = can(arg1);
 string v2 = arg2;
 if (v2 == "") v2 = "--left";
 string v3 = "";
 if (v2 == "--right") v3 = "transpose=1";
 if (v2 == "--left") v3 = "transpose=2";
 if (v2 == "--flip") v3 = "transpose=0, transpose=1";
 if (v2 == "--up-side-down") v3 = "transpose=1, transpose=1";
 string v4 = " -map 0:v? -map 0:a? -map 0:s?";
 string v5 = uri(v1, "extension");
 if (v5 == "") v5 = ".mkv";
 string v6 = uri(v1, "file-name") + "_ROTATED_" + ts() + v5;
 // message(s)
 string msg1 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 cmd + "rotating media...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) + v4 + " -vf " + quote(v3) + " " +
 quote(v6);
 // op(s)
 volume_f1(v1, true);
 note(msg1);
 e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err1 + cmd1 << endl;
  rm(v6);
  exit(e);
 }
 cout << out2 << endl;
}

//	string cmd1 = "ffmpeg -i " + as_is(inp) + " -vf " + as_is(rot) + \
//	" -c:a aac -strict -2 " + as_is(out);

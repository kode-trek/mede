/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_sub(string arg1, string arg2) {
 /* variable(s)
 [v1] input-subtitle
 [v2] input-media
 [v3] map
 [v4] <ass>-subtitle
 [v5] extension
 [v6] output-media
 */
 string inp1 = mark("[inp_sub] ", "blue");
 string inp2 = mark("[inp_med] ", "blue");
 string inp3 = mark("[inp] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[out] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = can(arg1);
 string v2 = can(arg2);
 string v3 = " -map 0:v? -map 0:a? -map 0:s?";
 string v4 = "." + uri(v1, "file-name") + ".ass";
 string v5 = uri(v2, "extension");
 if (v5 == "") v5 = ".mkv";
 string v6 = uri(v2, "file-name") + "_TERMED_" + ts() + v5;
 // message(s)
 string msg1 =
 inp1 + uri(v1, "full-name") + "\n" +
 inp2 + uri(v2, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 cmd + "attaching subtitles to media...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) + " " + quote(v4);
 string cmd2 = "ffmpeg -i " + quote(v2) + v3 + " -vf ass=" + quote(v4) + " " +
 quote(v6);
 // op(s)
 volume_f1(v1, true);
 volume_f1(v2, true);
 note(msg1);
 e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err1 + cmd1 << endl;
  exit(e);
 }
 e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err1 + cmd2 << endl;
  rm(v4);
  rm(v6);
  exit(e);
 }
 rm(v4);
 cout << out2 << endl;
}

//	string cmd2 = "ffmpeg -i " + as_is(inp) + " -c:a aac -async 1 -vf ass=" + \
//	as_is(ass) + " " + as_is(out);


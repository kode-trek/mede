/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_crop (
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
 */
 string inp1 = mark("[inp] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[out] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = can(arg1);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = arg4;
 string v5 = arg5;
 string v6 = "crop=x=" + v2 + ":y=" + v3 + ":w=" + v4 + ":h=" + v5;
 string v7 = " -map 0:v? -map 0:a? -map 0:s?";
 string v8 = uri(v1, "extension");
 if (v8 == "") v8 = ".mkv";
 string v9 = uri(v1, "file-name") + "_CROPPED_" + ts() + v8;
 // message(s)
 string msg1 = cmd + "aspect-ratio: ";
 string msg2 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v9, "full-name") + "\n" +
 cmd + "cropping image/video...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + v7 + " -vf " + v6 + " " + quote(v9);
 // op(s)
 if (arg2 == "") {
  note(msg1);
  e = sys(cmd1);
  if (e) {
   cout << endl;
   exit(e);
  }
  exit(e);
 }
 volume_f1(v1, true);
 note(msg2);
 e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err1 + cmd2 << endl;
  rm(v9);
  exit(e);
 }
 cout << out2 << endl;
}

//	cmd = "ffmpeg -i " + as_is(inp) + " -filter:v crop=" + box + " -c:a aac " + \
//	"-strict -2 " + as_is(out);

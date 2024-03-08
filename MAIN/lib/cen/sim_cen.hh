/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_cen (
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
 */
 string inp1 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = can(arg1);
 media_info med = imed(v1);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = arg4;
 string v5 = arg5;
 string v6 = "x=" + v2 + ":y=" + v3 + ":w=" + v4 + ":h=" + v5;
 string v7 = arg6;
 if (v7 == "") v7 = "black";
 string v8 = "drawbox=" + v6 + ":color=" + v7 + "@1:t=fill";
 if (v7 == "blank") v8 = f1(v1, v2, v3, v4, v5);
 string v9 = "";
 for (int i = 0; i < med.nstream; i++) v9 += " -map 0:" + str(i) + "?";
 string v10 = "";
 v10 = uri(v1, "extension");
 if (v10 == "") v10 = ".mkv";
 string v11 = uri(v1, "file-name") + "_CENSORED_" + ts() + v10;
 // message(s)
 string msg1 = cmd + "aspect-ratio: ";
 string msg2 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v11, "full-name") + "\n" +
 cmd + "covering image/video...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf " + v8 + v9 + " " + quote(v11);
 // op(s)
 volume_f1(v1);
 volume_f2();
 if (arg2 == "") {
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 cout << cmd + cmd2 << endl;
}

//	"[] ffmpeg -i " << quote(inp) << " -vf " << quote(box) << " -strict -2 " <<
//	quote(out)
//	<< endl;

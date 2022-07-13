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
 [v9] extension
 [v10] output-media
 [f1] window-frame
 */
 string cmd = mark("[] ", "blue");
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
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + " -map 0:v? -map 0:a? -map 0:s? -vf " + v8 + " " + quote(v10);
 // op(s)
 if (arg2 == "") {
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 cout << cmd + cmd2 << endl;
}

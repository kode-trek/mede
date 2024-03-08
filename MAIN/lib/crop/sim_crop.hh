/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_crop (
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
 string cmd = mark("[] ", "blue");
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
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + v7 + " -vf " + v6 + " " + quote(v9);
// string cmd2 = "ffmpeg -i " + quote(v1) + " -vf " + v6 + v7 + " " + quote(v10);
 // op(s)
 volume_f1(v1);
 if (arg2 == "") {
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 cout << cmd + cmd2 << endl;
}

//	cout <<
//	"[...] crops <inp-vid>..." "\n"
//	"[] ffmpeg -i " << quote(inp) << " -filter:v crop=" << box <<
//	" -c:a aac -strict -2 " << quote(out)
//	<< endl;

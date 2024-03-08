/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_rot(string arg1, string arg2) {
 /* variable(s)
 [v1] input-media
 [v2] input-transpose
 [v3] transpose-code
 [v4] map
 [v5] extension
 [v6] output-media
 */
 string cmd = mark("[] ", "blue");
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
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) + v4 + " -vf " + quote(v3) + " " +
 quote(v6);
 // op(s)
 volume_f1(v1, true);
 cout << cmd + cmd1 << endl;
}

//	"[...] rotates video." "\n"
//	"[] ffmpeg -i " << quote(inp) << " -vf " << quote(rot) <<
//	" -c:a aac -strict -2 " << quote(out)

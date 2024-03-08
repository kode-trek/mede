/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_sub(string arg1, string arg2) {
 /* variable(s)
 [v1] input-subtitle
 [v2] input-media
 [v3] map
 [v4] <ass>-subtitle
 [v5] extension
 [v6] output-media
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = can(arg1);
 string v2 = can(arg2);
 string v3 = " -map 0:v? -map 0:a? -map 0:s?";
 string v4 = "." + uri(v1, "file-name") + ".ass";
 string v5 = uri(v2, "extension");
 if (v5 == "") v5 = ".mkv";
 string v6 = uri(v2, "file-name") + "_TERMED_" + ts() + v5;
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) + " " + quote(v4);
 string cmd2 = "ffmpeg -i " + quote(v2) + v3 + " -vf ass=" + quote(v4) + " " +
 quote(v6);
 // op(s)
 volume_f1(v1);
 volume_f1(v2);
 cout << cmd + cmd1 << endl;
 cout << cmd + cmd2 << endl;
 cout << cmd + "rm " + v4 << endl;
}

//	string cmd2 = "ffmpeg -i " + as_is(inp) + " -c:a aac -async 1 -vf ass=" + \
//	as_is(ass) + " " + as_is(out);

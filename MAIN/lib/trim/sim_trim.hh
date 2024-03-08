/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_trim(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] input-media
 [v2] map
 [v3] start-time
 [v4] stop-time
 [v5] extension
 [v6] output-media
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = can(arg1);
 string v2 = " -map 0:v? -map 0:a? -map 0:s?";
 string v3 = arg2;
 string v4 = arg3;
 string v5 = uri(v1, "extension");
 if (v5 == "") v5 = ".mkv";
 string v6 = uri(v1, "file-name") + "_TRIMMED_" + ts() + v5;
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) + v2 + " -ss " + v3 + " -to " + v4 + " "
 + quote(v6);
 // op(s)
 volume_f1(v1);
 cout << cmd + cmd1 << endl;
}

//"[] ffmpeg -i " << quote(inp) <<
//"-strict experimental -c:a aac -async 1 -ss " << quote(t1) << " -to " <<
//quote(t2) << " " << quote(out)

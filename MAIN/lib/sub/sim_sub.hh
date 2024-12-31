/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_sub(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] input-subtitle
 [v2] input-media
 [v3] transcript-type
 [v4] extension
 [v5] output-media
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = can(arg1);
 string v2 = can(arg2);
 string v3 = arg3;
 if (v3 == "") v3 = "soft";
 string v4 = uri(v2, "extension");
 if (v4 == "") v4 = ".mkv";
 string v5 = uri(v2, "file-name") + "_SUBBED_" + ts() + v4;
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v2) + + " -i " + quote(v1) + " -c copy " +
 quote(v5);
 string cmd2 = "ffmpeg -i " + quote(v2) + " -vf subtitles=" + quote(v1) + " " +
 quote(v5);
 // op(s)
 volume_f1(v2, true);
 if (v3 == "soft") cout << cmd + cmd1 << endl;
 if (v3 == "hard") cout << cmd + cmd2 << endl;
}

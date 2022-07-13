/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_trim(string arg1, string arg2, string arg3, string arg4) {
 /* variable(s)
 [v1] input-media
 [v2] start-time
 [v3] stop-time
 [v4] trim-mode
 [v5] extension
 [v6] output-media
 */
 string inp1 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = can(arg1);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = arg4;
 if (v4 == "") v4 == "default";
 string v5 = uri(v1, "extension");
 if (v5 == "") v5 = ".mkv";
 string v6 = uri(v1, "file-name") + "_TRIMMED_" + ts() + v5;
 // command(s)
 string cmd1 = "ffmpeg -ss " + v2 + " -to " + v3 + " -i " + quote(v1) + " -map 0:v? -map 0:a? -map 0:s? " +
 quote(v6);
 if (v4 == "precise") {
  cmd1 = "ffmpeg -i " + quote(v1) + " -ss " + v2 + " -to " + v3 + " -map 0:v? -map 0:a? -map 0:s? " +
  quote(v6);
 }
 if (v4 == "glance") {
  cmd1 = "ffmpeg -i " + quote(v1) + " -ss " + v2 + " -to " + v3 + " -map 0:v? -map 0:a? -map 0:s? -c copy " +
  quote(v6);
 }
 // op(s)
 cout << cmd + cmd1 << endl;
}

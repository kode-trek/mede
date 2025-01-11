/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

vector<int> f1(string arg1) {
 /* variable(s)
 [v1] input-media
 [v2] width
 [v3] height
 [v4] temporary-text-file
 [v5] aspect-ratio
 */
 string out1 = mark("[OUT] ", "blue");
 string err1 = mark("[WARNING] ", "yellow");
 //
 string v1 = arg1;
 int v2, v3 = 0;
 string v4 = "~/." + ts();
 vector<string> v5 = {""};
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 // op(s)
 sys(cmd1 + " > " + v4);
 if (cat(v4) == "") {
  rm(v4);
  return {0, 0};
 }
 v5 = split(cat(v4), "x");
 rm(v4);
 try {v2 = str2num(v5[0]);} catch (...) {v2 = 0;}
 try {v3 = str2num(v5[1]);} catch (...) {v3 = 0;}
 return {v2, v3};
}

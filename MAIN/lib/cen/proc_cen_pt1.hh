/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

vector<int> f1_1(string arg1) {
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

string f1(string arg1, string arg2, string arg3, string arg4, string arg5) {
 /* variable(s)
 [v1] input-media
 [v2] x-box-input
 [v3] y-box-input
 [v4] w-box-input
 [v5] h-box-input
 [v6] x-box-integer
 [v7] y-box-integer
 [v8] w-box-integer
 [v9] h-box-integer
 [v10] w-box-calculated
 [v11] h-box-calculated
 [v12] dimension
 [v13] box
 [f1_1] aspect-ratio
 */
 string v1 = arg1;
 string v2 = arg2;
 if (v2 == "0") v2 = "1";
 string v3 = arg3;
 if (v3 == "0") v3 = "1";
 string v4 = arg4;
 string v5 = arg5;
 int v6, v7, v8, v9 = 0;
 try {v6 = str2num(v2);} catch (...) {v6 = 1;}
 try {v7 = str2num(v3);} catch (...) {v7 = 1;}
 try {v8 = str2num(v4);} catch (...) {v8 = 0;}
 try {v9 = str2num(v5);} catch (...) {v9 = 0;}
 int v10, v11 = 0;
 try {v10 = f1_1(v1)[0];} catch (...) {v10 = 0;}
 try {v11 = f1_1(v1)[1];} catch (...) {v11 = 0;}
 string v12 = "x=:y=:w=:h=";
 string v13 = "delogo=" + v12;
 // op(s)
 if ((v6 + v8) >= v10) v8 = v10 - v6 - 1;
 if ((v7 + v9) >= v11) v9 = v11 - v7 - 1;
 v2 = str(v6);
 v3 = str(v7);
 v4 = str(v8);
 v5 = str(v9);
 v12 = "x=" + v2 + ":" + "y=" + v3 + ":" + "w=" + v4 + ":" + "h=" + v5;
 v13 = "delogo=" + v12;
 return v13;
}

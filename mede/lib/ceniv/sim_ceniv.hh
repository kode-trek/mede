/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_ceniv (
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
 0: number-of-video-track(s)
 1: number-of-audio-track(s)
 2: number-of-channel(s)
 3: media-type (1:video-only 2:audio-only 3:aud/vid/sub)
 [cmd] mark-command
 */
 string cmd = mark("blue", "[] ");
 //
 string v1 = arg1;
 can(v1);
 vector<int> med = meds(v1);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = arg4;
 string v5 = arg5;
 string v6 = "x=" + v2 + ":y=" + v3 + ":w=" + v4 + ":h=" + v5;
 string v7 = arg6;
 if (v7 == "") v7 = "black";
 string v8 = "drawbox=" + v6 + ":color=" + v7 + "@1:t=fill";
 if (v7 == "blank") v8 = win(v1, v2, v3, v4, v5);
 string v9 = "";
 for (int i = 0; i < med[2]; i++) v9 += " -map 0:" + str(i) + "?";
 string v10 = "";
 v10 = uri(v1)[3];
 if (v10 == "") v10 = ".mp4";
 string v11 = uri(v1)[2] + "_CENSORED_" + ts() + v10;
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf " + v8 + v9 + " " + quote(v11);
 // op(s)
 if (arg2 == "") {
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 cout << cmd + cmd2 << endl;
}

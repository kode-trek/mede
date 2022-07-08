/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_cropiv(
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
 string v6 = "crop=x=" + v2 + ":y=" + v3 + ":w=" + v4 + ":h=" + v5;
 string v7 = "";
 for (int i = 0; i < med[2]; i++) v7 += " -map 0:" + str(i) + "?";
 string v8 = "";
 v8 = uri(v1)[3];
 if (v8 == "") v8 = ".mp4";
 string v9 = uri(v1)[2] + "_CROPPED_" + ts() + v8;
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) +
 R"( 2>&1 | grep -oP 'Stream .*, \K[0-9]+x[0-9]+')";
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf " + v6 + v7 + " " + quote(v9);
 // op(s)
 if (arg2 == "") {
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 cout << cmd + cmd2 << endl;
}

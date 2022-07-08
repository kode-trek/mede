/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_rotiv(string arg1, string arg2) {
 /* variable(s)
 [v1] input-media
 [v2] input-transpose
 [v3] transpose-code
 [v4] map
 [v5] extension
 [v6] output-media
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
 if (v2 == "") v2 = "left";
 string v3 = "";
 if (v2 == "right") v3 = "transpose=1";
 if (v2 == "left") v3 = "transpose=2";
 if (v2 == "flip") v3 = "transpose=0, transpose=1";
 if (v2 == "up-side-down") v3 = "transpose=1, transpose=1";
 string v4 = "";
 for (int i = 0; i < med[2]; i++) v4 += " -map 0:" + str(i) + "?";
 string v5 = "";
 v5 = uri(v1)[3];
 if (v5 == "") v5 = ".mp4";
 string v6 = uri(v1)[2] + "_ROTATED_" + ts() + v5;
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) + " -vf " + quote(v3) + v4 + " " +
 quote(v6);
 // op(s)
 cout << cmd + cmd1 << endl;
}

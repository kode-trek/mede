/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_adds(string arg1, string arg2) {
 /* variable(s)
 [v1] input-subtitle
 [v2] input-media
 [v3] <ass>-subtitle
 [v4] extension
 [v5] output-media
 [v6] map
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
 string v2 = arg2;
 can(v2);
 vector<int> med = meds(v2);
 string v3 = "." + uri(v1)[2] + ".ass";
 string v4 = "";
 v4 = uri(v2)[3];
 if (v4 == "") v4 = ".mp4";
 string v5 = uri(v2)[2] + "_SUBBED_" + ts() + v4;
 string v6 = "";
 for (int i = 0; i < med[2]; i++) v6 += " -map 0:" + str(i) + "?";
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) + " " + quote(v3);
 string cmd2 = "ffmpeg -i " + quote(v2) + " -vf ass=" + quote(v3) + v6 + " " +
 quote(v5);
 // op(s)
 cout <<
 cmd + cmd1 + "\n" +
 cmd + cmd2 + "\n" +
 cmd + "rm " + quote(v3)
 << endl;
}

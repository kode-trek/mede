/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_pub(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] input-media
 [v2] video-track
 [v3] audio-track
 [v4] output-media
 [v5] output-audio
 [v6] output-player
 [v7] width
 [v8] length
 [v9] video-html5-code
 [v10] audio-html5-code
 [med] media-info
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = can(arg1);
 media_info med = imed(v1, true);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = uri(v1, "file-name") + "_POLISHED_" + ts() + ".mp4";
 string v5 = uri(v1, "file-name") + "_POLISHED_" + ts() + ".mp3";
 string v6 = uri(v1, "file-name") + "_PLAYER_" + ts() + ".htm";
 int v7 = 0;
 int v8 = 0;
 if (f1(v1)[0] > 640) v7 = 640;
 if (f1(v1)[0] <= 640) v7 = f1(v1)[0];
 if (f1(v1)[1] > 480) v8 = 480;
 if (f1(v1)[1] <= 480) v8 = f1(v1)[1];
 string v9 =
 "<video controls width='" + str(v7) + "' length='" + str(v8) + "'>""\n"
 "<source src=" + quote(v4) + ">""\n"
 "</video>";
 string v10 =
 "<audio controls>""\n"
 "<source src=" + quote(v5) + ">""\n"
 "</audio>";
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) + " -map_metadata -1 -map_chapters -1 "
 + quote(v4);
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf tblend=all_mode=normal -vsync 2"
 " -map_metadata -1 -map_chapters -1 -c:a libmp3lame " + quote(v5);
 string cmd3 = "";
 if ((v2 == "") or (v3 == "")) cmd3 = cmd1;
 else {
  cmd3 = "ffmpeg -i " + quote(v1) + " -map 0:" + v2 + " -map 0:" + v3 +
  " -map_metadata -1 -map_chapters -1 -strict experimental -c:a aac -async 1 "
  + quote(v4);
 }
 // op(s)
 if (med.type == "vid") {
  cout << cmd + cmd1 << endl;
  cout << "code-lines in " + quote(v6) + ":""\n" + v9 << endl;
  exit(0);
 }
 if (med.type == "aud") {
  cout << cmd + cmd2 << endl;
  cout << "code-lines in " + quote(v6) + ":""\n" + v10 << endl;
  exit(0);
 }
 cout << cmd + cmd3 << endl;
 drop(v6, v9);
}

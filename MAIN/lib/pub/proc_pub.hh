/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_pub(string arg1, string arg2, string arg3) {
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
 string inp1 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
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
 // message(s)
 string msg1 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 out1 + uri(v4, "full-name") + "\n" +
 cmd + "preparing media to get published...";
 string msg2 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 out1 + uri(v5, "full-name") + "\n" +
 cmd + "preparing media to get published...";
 string msg3 =
 inp1 + uri(v1, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 out1 + uri(v4, "full-name") + "\n" +
 cmd + "preparing media to get published...";
 // command(s)
 int e = 0;
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
 volume_f1(v1, true);
 volume_f2(true);
 if (med.type == "vid") {
  note(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   rm(v4);
   exit(1);
  }
  drop(v6, v9);
  cout << out2 << endl;
  exit(0);
 }
 if (med.type == "aud") {
  note(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   rm(v4);
   exit(1);
  }
  drop(v6, v10);
  cout << out2 << endl;
  exit(0);
 }
 note(msg3);
 e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err1 + cmd3 << endl;
  rm(v4);
  exit(1);
 }
 drop(v6, v9);
 cout << out2 << endl;
}

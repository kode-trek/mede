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
 [v7] video-html5-code
 [v8] audio-html5-code
 [v9] map
 [med] media-info
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 can(v1);
 media_info med = imed(v1, true);
 string v2 = arg2;
 string v3 = arg3;
 string v4 = uri(v1, "file-name") + "_POLISHED_" + ts() + ".mp4";
 string v5 = uri(v1, "file-name") + "_POLISHED_" + ts() + ".mp3";
 string v6 = uri(v1, "file-name") + "_PLAYER_" + ts() + ".htm";
 string v7 =
 "<video controls width='640' length='320'>""\n"
 "<source src=" + quote(v4) + ">""\n"
 "</video>";
 string v8 =
 "<audio controls>""\n"
 "<source src=" + quote(v5) + ">""\n"
 "</audio>";
 string v9 = " -map 0:0 -map 0:a";
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) + " -map_metadata -1 -map_chapters -1 "
 "-pix_fmt yuv320p -vcodec libx264 -acodec avc " + quote(v4);
 string cmd2 = "ffmpeg -i " + quote(v1) + " -vf tblend=all_mode=grainextract "
 "-map_metadata -1 -map_chapters -1 -c:a libmp3lame " + quote(v5);
 string cmd3 = "";
 if ((v2 == "") or (v3 == "")) {
  cmd3 = "ffmpeg -i " + quote(v1) + v9 + " -map_metadata -1 -map_chapters -1 "
  "-strict experimental -c:a aac -async 1 " + quote(v4);
 } else {
  cmd3 = "ffmpeg -i " + quote(v1) + " -map 0:" + v2 + " -map 0:" + v3 +
  " -map_metadata -1 -map_chapters -1 -strict experimental -c:a aac -async 1 "
  + quote(v4);
 }
 // op(s)
 volume_f1(v1);
 volume_f2();
 //
 if (med.type == "vid") {
  cout <<
  cmd + cmd1 + "\n"
  "context of " + quote(v6) + ":\n" + v7
  << endl;
  exit(0);
 }
 if (med.type == "aud") {
  cout <<
  cmd + cmd2 + "\n"
  "context of " + quote(v6) + ":\n" + v8
  << endl;
  exit(0);
 }
 cout <<
 cmd + cmd1 + "\n"
 "context of " + quote(v6) + ":\n" + v7
 << endl;
}

//cmd + "creates " + quote(v7) + " which consists:" + "\n" +

//  "code-line(s) in " + quote(v7) + ":\n" + v8

//		<< quote(out) << "\n"
//		"[...] establishes <*player*.htm> with the following codes inside:" "\n" <<
//		vid_play_htm


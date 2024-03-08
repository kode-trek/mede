/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_laud(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input-media
 [v3] extension
 [v4] audio-track
 [v5] map
 [v6] output-media
 [med] media-info
 */
 string inp1 = mark("[inp] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[out] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("[WARNING] ", "yellow");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = can(arg2);
 media_info med = imed(v2);
 string v3 = uri(v2, "extension");
 if (v3 == "") v3 = ".mkv";
 string v4 = arg3;
 if (med.type == "vid-aud-sub") v4 = "0";
 if ((med.naud > 1) and (v4 == "")) v4 = "1";
 if (v4 == "") v4 = "a";
 string v5 = "";
 for (int i = 0; i < med.nstream; i++) v5 += " -map 0:" + str(i) + "?";
 string v6 = "";
 if (v1 == "--mute") v6 = uri(v2, "file-name") + "_MUTED_" + ts() + v3;
 if (v1 == "--dmute") v6 = uri(v2, "file-name") + "_DIRTY-MUTED_" + ts() + v3;
 if (v1 == "--icu") v6 = uri(v2, "file-name") + "_BLINDED_" + ts() + v3;
 if (v1 == "--sound") v6 = uri(v2, "file-name") + "_SOUND_" + ts() + ".mp3";
 // message(s)
 string msg1 =
 inp1 + uri(v2, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 cmd + "eliminating audio in media...";
 string msg2 =
 inp1 + uri(v2, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 cmd + "eliminating video in media...";
 string msg3 =
 inp1 + uri(v2, "full-name") + "\n" +
 out1 + uri(v6, "full-name") + "\n" +
 cmd + "extracting sound from media...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -i " + quote(v2) + " 2>&1 | grep -oP 'Stream .* Audio'";
 string cmd2 = "ffmpeg -i " + quote(v2) + " -f lavfi -t 0.1 -i "
 "anullsrc -filter_complex '[0:v:0][1:a] concat=n=1:v=1:a=1' " + quote(v6);
 string cmd3 = "ffmpeg -i " + quote(v2) + " -c copy -an " + quote(v6);
 string cmd4 = "ffmpeg -i " + quote(v2) + " -vf "
 "drawbox=x=0:y=0:w=0:h=0:color=black@1:t=fill" + v5 + " " + quote(v6);
 string cmd5 = "timidity " + quote(v2) + " -Ow -o - 2>/dev/null | ffmpeg -i - "
 "-acodec libmp3lame -ab 64k " + quote(v6);
 string cmd6 = "ffmpeg -i " + quote(v2) + " -map 0:" + v4 + " -vf "
 "tblend=all_mode=grainextract -map_metadata -1 -map_chapters -1" + " -c:a "
 "libmp3lame " + quote(v6);
 // op(s)
 if (v1 == "--aud") {
  if (midi(v2)) {
   cout << err1 + "media is MIDI." << endl;
   exit(0);
  }
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << mark("NONE.", "yellow") << endl;
   exit(e);
  }
  cout << endl;
  sys(cmd1 + " 2>/dev/null");
  exit(0);
 }
 volume_f1(v2, true);
 volume_f2(true);
 if (((v1 == "--mute") or (v1 == "--dmute")) and (med.type == "aud")) {
  cout << err1 + "media is an audio-type." << endl;
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (midi(v2))) {
  cout << err1 + "media is an audio-type." << endl;
  exit(0);
 }
 if (v1 == "--mute") {
  note(msg1);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd2 << endl;
   rm(v6);
   exit(e);
  }
  cout << out2 << endl;
  exit(0);
 }
 if (v1 == "--dmute") {
  note(msg1);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd3 << endl;
   rm(v6);
   exit(e);
  }
  cout << out2 << endl;
  exit(0);
 }
 if ((v1 == "--icu") and (med.type == "aud")) {
  cout << err1 + "no video-track found in media." << endl;
  exit(0);
 }
 if ((v1 == "--icu") and (midi(v2))) {
  cout << err1 + "no video-track found in media." << endl;
  exit(0);
 }
 if (v1 == "--icu") {
  note(msg2);
  e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd4 << endl;
   rm(v6);
   exit(e);
  }
  cout << out2 << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (med.type == "vid")) {
  cout << err1 + "no audio-track found in media." << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (midi(v2))) {
  note(msg3);
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd5 << endl;
   rm(v6);
   exit(e);
  }
  cout << out2 << endl;
  exit(0);
 }
 if (v1 == "--sound") {
  note(msg3);
  e = sys(cmd6 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err2 + cmd6 << endl;
   rm(v6);
   exit(e);
  }
  cout << out2 << endl;
  exit(0);
 }
}

//	disp("[] converting <inp-med> to <out-aud.MP3> and degrading quality...");
//	out = uri(inp)[2] + "_squeezed_" + ts() + ".mp3";
//	cmd1 = "ffmpeg -i " + as_is(inp) + " -map 0:1" + \
//	" -vf tblend=all_mode=grainextract -map_metadata -1 -map_chapters -1 " + \
//	"-acodec libmp3lame -b:a 8k -ac 1 -ar 11025 " + as_is(out);
//	cmd2 = "ffmpeg -i " + as_is(inp) + \
//	" -vf tblend=all_mode=grainextract -map_metadata -1 -map_chapters -1 " + \
//	"-acodec libmp3lame -b:a 8k -ac 1 -ar 11025 " + as_is(out);

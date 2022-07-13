/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_laud(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input-media
 [v3] extension
 [v4] audio-track
 [v5] output-media
 [med] media-info
 */
 string cmd = mark("[] ", "blue");
 string err1 = mark("[WARNING] ", "yellow");
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
 if (v1 == "--mute") v5 = uri(v2, "file-name") + "_MUTED_" + ts() + v3;
 if (v1 == "--dmute") v5 = uri(v2, "file-name") + "_DIRTY-MUTED_" + ts() + v3;
 if (v1 == "--icu") v5 = uri(v2, "file-name") + "_BLINDED_" + ts() + v3;
 if (v1 == "--sound") v5 = uri(v2, "file-name") + "_SOUND_" + ts() + ".mp3";
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v2) + " 2>&1 | grep -oP 'Stream .* Audio'";
 string cmd2 = "ffmpeg -i " + quote(v2) + " -af \"volume=0.0\" -c:v copy " +
 quote(v5);
 string cmd3 = "ffmpeg -i " + quote(v2) + " -c copy -an " + quote(v5);
 string cmd4 = "ffmpeg -i " + quote(v2) + " -vf "
 "drawbox=x=0:y=0:w=0:h=0:color=black@1:t=fill " + quote(v5);
 string cmd5 = "timidity " + quote(v2) + " -Ow -o - 2>/dev/null | ffmpeg -i - "
 "-acodec libmp3lame -ab 64k " + quote(v5);
 string cmd6 = "ffmpeg -i " + quote(v2) + " -map 0:" + v4 + " -vf "
 "tblend=all_mode=grainextract -map_metadata -1 -map_chapters -1" + " -c:a "
 "libmp3lame " + quote(v5);
 // op(s)
 if (v1 == "--aud") {
  if (midi(v2)) {
   cout << err1 + "media is an audio-type." << endl;
   exit(0);
  }
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (med.type == "aud")) {
  cout << err1 + "media is an audio-type." << endl;
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (midi(v2))) {
  cout << err1 + "media is an audio-type." << endl;
  exit(0);
 }
 if (v1 == "--mute") {
  cout << cmd + cmd2 << endl;
  exit(0);
 }
 if (v1 == "--dmute") {
  cout << cmd + cmd3 << endl;
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
  cout << cmd + cmd4 << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (med.type == "vid")) {
  cout << err1 + "no audio-track found in media." << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (midi(v2))) {
  cout << cmd + cmd5 << endl;
  exit(0);
 }
 if (v1 == "--sound") {
  cout << cmd + cmd6 << endl;
  exit(0);
 }
}

/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_laud(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input-media
 [v3] extension
 [v4] audio-track
 [v5] map
 [v6] output-media
 [med] media-info
 0: number-of-video-track(s)
 1: number-of-audio-track(s)
 2: number-of-channel(s)
 3: media-type (1:video-only 2:audio-only 3:aud/vid/sub)
 [cmd] mark-command
 [err] mark-error/warning
 */
 string cmd = mark("blue", "[] ");
 string err1 = mark("yellow", "[WARNING] ");
 //
 string v1 = arg1;
 string v2 = arg2;
 can(v2);
 vector<int> med = meds(v2);
 string v3 = "";
 v3 = uri(v2)[3];
 if (v3 == "") v3 = ".mp4";
 string v4 = arg3;
 if (med[3] == 2) v4 = "0";
 if ((med[1] > 1) and (v4 == "")) v4 = "1";
 if (v4 == "") v4 = "a";
 string v5 = "";
 for (int i = 0; i < med[2]; i++) v5 += " -map 0:" + str(i) + "?";
 string v6 = "";
 if (v1 == "--mute") v6 = uri(v2)[2] + "_MUTED_" + ts() + v3;
 if (v1 == "--dmute") v6 = uri(v2)[2] + "_DIRTY-MUTED_" + ts() + v3;
 if (v1 == "--icu") v6 = uri(v2)[2] + "_BLINDED_" + ts() + v3;
 if (v1 == "--sound") v6 = uri(v2)[2] + "_SOUND_" + ts() + ".mp3";
 // command(s)
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
  if (is_midi(v2)) {
   cout << err1 + "media is MIDI." << endl;
   exit(0);
  }
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (med[3] == 1)) {
  cout << err1 + "media is already muted." << endl;
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (med[3] == 2)) {
  cout << err1 + "media is an audio-type." << endl;
  exit(0);
 }
 if (((v1 == "--mute") or (v1 == "--dmute")) and (is_midi(v2))) {
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
 if ((v1 == "--icu") and (med[3] == 1)) {
  cout << err1 + "media is muted." << endl;
  exit(0);
 }
 if ((v1 == "--icu") and (med[3] == 2)) {
  cout << err1 + "no video-track found in media." << endl;
  exit(0);
 }
 if ((v1 == "--icu") and (is_midi(v2))) {
  cout << err1 + "no video-track found in media." << endl;
  exit(0);
 }
 if (v1 == "--icu") {
  cout << cmd + cmd4 << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (med[3] == 1)) {
  cout << err1 + "media is muted." << endl;
  exit(0);
 }
 if ((v1 == "--sound") and (is_midi(v2))) {
  cout << cmd + cmd5 << endl;
  exit(0);
 }
 if (v1 == "--sound") {
  cout << cmd + cmd6 << endl;
  exit(0);
 }
}

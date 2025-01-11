/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

struct media_info {
 int nvid;
 int naud;
 int nsub;
 int nstream;
 string type;
};

media_info imed (string arg1, bool arg2 = false) {
 /* variable(s)
 [v1] input-media
 [v2] temporary-text-file
 [v3] attached-picture
 [v4] display-warning
 */
 string out1 = mark("[OUT] ", "blue");
 string err1 = mark("[WARNING] ", "yellow");
 //
 media_info v0;
 string v1 = arg1;
 string v2 = "~/." + ts();
 int v3 = 0;
 v0.nvid = 0;
 v0.naud = 0;
 v0.nsub = 0;
 v0.nstream = 0;
 v0.type = "";
 bool v4 = arg2;
 // message(s)
 string msg1 = err1 + "multiple video-tracks found.""\n";
 string msg2 = err1 + "multiple audio-tracks found.""\n";
 string msg3 = err1 + "unusual stream(s) found.""\n";
 // command(s)
 string cmd1 = "ffmpeg -i " + quote(v1) +
 " 2>&1 | grep -oP 'Stream .* Video.* pic' | grep -c pic > " + v2;
 string cmd2 = "ffmpeg -i " + quote(v1) +
 " 2>&1 | grep -oP 'Stream .* Video' | grep -c Video > " + v2;
 string cmd3 = "ffmpeg -i " + quote(v1) +
 " 2>&1 | grep -oP 'Stream .* Audio' | grep -c Audio > " + v2;
 string cmd4 = "ffmpeg -i " + quote(v1) +
 " 2>&1 | grep -oP 'Stream .* Subtitle' | grep -c Subtitle > " + v2;
 string cmd5 = "ffmpeg -i " + quote(v1) +
 " 2>&1 | grep -oP 'Stream .*' | grep -c Stream > " + v2;
 string cmd6 = "ffmpeg -i " + quote(v1) + " 2>&1 | grep -oP 'Stream .* Video'";
 string cmd7 = "ffmpeg -i " + quote(v1) + " 2>&1 | grep -oP 'Stream .* Audio'";
 string cmd8 = "ffmpeg -i " + quote(v1) + " 2>&1 | grep -oP 'Stream .*'";
 // op(s)
 sys(cmd1);
 v3 = str2num(cat(v2));
 rm(v2);
 sys(cmd2); v0.nvid = str2num(cat(v2)); rm(v2);
 sys(cmd3); v0.naud = str2num(cat(v2)); rm(v2);
 sys(cmd4); v0.nsub = str2num(cat(v2)); rm(v2);
 sys(cmd5);
 v0.nstream = str2num(cat(v2));
 rm(v2);
 if (v4) {
  if (v0.nvid > 1) {
   note(msg1);
   sys(cmd6);
  }
  if (v0.naud > 1) {
   note(msg2);
   sys(cmd7);
  }
  if ((v0.nvid + v0.naud + v0.nsub) != v0.nstream) {
   note(msg3);
   sys(cmd8);
  }
 }
 if (v0.nvid == 1) v0.type = "vid";
 if ((v0.naud == 1) or ((v0.naud == 1) and (v3 == 1))) v0.type = "aud";
 if ((v0.nvid + v0.naud > 1) and (v3 != 1)) v0.type = "vid-aud-sub";
 return v0;
}

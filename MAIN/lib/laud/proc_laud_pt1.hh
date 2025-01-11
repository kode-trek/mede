/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

bool midi(string arg1) {
 /* variable(s)
 [v1] input-media
 [v2] temporary-text-file
 */
 string cmd = mark("[] ", "blue");
 string err1 = mark("[WARNING] ", "yellow");
 //
 string v1 = arg1;
 string v2 = "~/." + ts();
 // command(s)
 string cmd1 = "echo `file -b --mime-type " + quote(v1) + "` > " + v2;
 // op(s)
 volume_f1(v2, true);
 int e = sys(cmd1);
 if ((cat(v2)).substr(0, (cat(v2)).size() - 1) == "audio/midi") {
  rm(v2);
  return 1;
 } else {
  rm(v2);
  return 0;
 }
}

/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void proc_mergem(string arg1) {
 /* variable(s)
 [v1] input-directory
 [v2] list-of-item(s)-in-[v1]
 [v3] extension
 [v4] text-file-with-[v2]-enlisted
 [v5] output-media
 [inp] mark-input
 [cmd] mark-command
 [out] mark-output
 [err] mark-error/warning
 */
 string inp1 = mark("blue", "[inp] ");
 string cmd = mark("blue", "[] ");
 string out1 = mark("blue", "[out] ");
 string out2 = mark("green", "DONE.");
 string err1 = mark("yellow", "[WARNING] ");
 string err2 = mark("red", "HALTED.""\n""[FAILED] ");
 //
 string v1 = arg1;
 if (not dir(v1)) {
  cout <<
  inp1 + v1 + "\n" +
  err1 + "directory not found."
  << endl;
  exit(1);
 }
 vector<string> v2 = tree(v1, false);
 string v3 = "";
 v3 = uri(v2[0])[3];
 if (v3 == "") v3 = ".mp4";
 string v4 = ".list_" + ts() + ".txt";
 string v5 = uri(v1)[1] + "_MERGED_" + ts() + v3;
 // message(s)
 string msg1 =
 inp1 + uri(v1)[1] + "\n" +
 out1 + uri(v5)[1] + "\n" +
 cmd + "merging file(s) in directory...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -f concat -safe 0 -i " + v4 + " -c copy " + quote(v5);
 // op(s)
 if (not write_access()) {
  cout << err1 + "write-permission denied!" << endl;
  exit(1);
 }
 for (int i = 0; i < v2.size(); i++) {
  for (int j = 0; j < v2[i].size(); j++)
   if (v2[i][j] == '\'') {
    cout <<
    inp1 + v2[i] + "\n" +
    err1 + "single-quote (') in naming."
    << endl;
   }
 }
 note(msg1);
 for (int i = 0; i < v2.size(); i++) drop(v4, "file '" + v2[i] + "'\n");
 e = sys(cmd1 + " -y 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err2 + cmd1 + "\n""item(s) inside " + quote(v4) + ":" << endl;
  cout << cat(v4).txt;
  rm(v4);
  rm(v5);
  exit(1);
 }
 rm(v4);
 cout << out2 << endl;
}

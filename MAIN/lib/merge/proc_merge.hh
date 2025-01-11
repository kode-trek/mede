/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_merge(string arg1) {
 /* variable(s)
 [v1] input-directory
 [v2] list of item(s) in [v1]
 [v3] extension
 [v4] text-file with [v2] listed //text-file-contains-[v2]
 [v5] list of item(s) in [v1] (char ' replaced)
 [v6] output-media
 */
 string inp1 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("[WARNING] ", "yellow");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
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
 vector<string> v5 = {};
 string v3 = uri(v2[0], "extension");
 if (v3 == "") v3 = ".mkv";
 string v4 = ".list_" + ts() + ".txt";
 string v6 = uri(v1, "full-name") + "_MERGED_" + ts() + v3;
 // message(s)
 string msg1 =
 inp1 + uri(v1, "file-name") + "\n" +
 out1 + uri(v6, "file-name") + "\n" +
 cmd + "merging file(s) in directory...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -f concat -safe 0 -i " + v4 + " -c copy " + quote(v6);
 // op(s)
 volume_f1(v1, true);
 volume_f2(true);
 for (int i = 0; i < v2.size(); i++) {
  if (has(v2[i], '\''))
   v5.push_back(replace(v2[i], "'", "'\\''"));
  if (not has(v2[i], '\''))
   v5.push_back(v2[i]);
 }
 note(msg1);
 for (int i = 0; i < v5.size(); i++) drop(v4, "file '" + v5[i] + "'\n");
 e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err2 + cmd1 + "\n""item(s) inside " + v4 + ":" << endl;
  cout << cat(v4);
  rm(v4);
  rm(v6);
  exit(1);
 }
 rm(v4);
 cout << out2 << endl;
}

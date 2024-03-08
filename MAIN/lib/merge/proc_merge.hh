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
 [v4] text-file with [v2] enlisted
 [v5] output-media
 */
 string inp1 = mark("[inp] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[out] ", "blue");
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
 string v3 = uri(v2[0], "extension");
 if (v3 == "") v3 = ".mkv";
 string v4 = ".list_" + ts() + ".txt";
 string v5 = uri(v1, "full-name") + "_MERGED_" + ts() + v3;
 // message(s)
 string msg1 =
 inp1 + uri(v1, "file-name") + "\n" +
 out1 + uri(v5, "file-name") + "\n" +
 cmd + "merging file(s) in directory...";
 // command(s)
 int e = 0;
 string cmd1 = "ffmpeg -f concat -safe 0 -i " + v4 + " -c copy " + quote(v5);
 // op(s)
 volume_f1(v1, true);
 volume_f2(true);
 for (int i = 0; i < v2.size(); i++) { // grep in txt-file?
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
 e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
 if (e) {
  cout << err2 + cmd1 + "\n""item(s) inside " + v4 + ":" << endl;
  cout << cat(v4);
  rm(v4);
  rm(v5);
  exit(1);
 }
 rm(v4);
 cout << out2 << endl;
}

//vector<string> l = tree(inp, false);
//string in = "";
//for (int i = 0; i < l.size(); i++) in += " -i " + quote(l[i]);
//string filter = "";
//for (int i = 0; i < l.size(); i++)
// filter += "[" + str(i) + ":v:0][" + str(i) + ":a:0]";
//string cmd = "ffmpeg " + in + " -filter_complex '" + filter +
//" concat=n=" + str(l.size()) + ":v=1:a=1 [v][a]' -map '[v]' -map '[a]' "
//+ quote(v6);

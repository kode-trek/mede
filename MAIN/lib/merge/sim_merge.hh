/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_merge(string arg1) {
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
 string err1 = mark("[WARNING] ", "yellow");
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
 string v4 = "list_" + ts() + ".txt";
 string v6 = uri(v1, "full-name") + "_MERGED_" + ts() + v3;
 // command(s)
 string cmd1 = "ffmpeg -f concat -safe 0 -i " + v4 + " -c copy " + quote(v6);
 // op(s)
 for (int i = 0; i < v2.size(); i++) {
  if (has(v2[i], '\''))
   v5.push_back(replace(v2[i], "'", "'\\''"));
  if (not has(v2[i], '\''))
   v5.push_back(v2[i]);
 }
 cout << cmd + "item(s) inside " + quote(v4) + " to get merged:" << endl;
 for (int i = 0; i < v5.size(); i++) cout << "file '" + v5[i] + "'" << endl;
 cout << cmd + cmd1 << endl;
}

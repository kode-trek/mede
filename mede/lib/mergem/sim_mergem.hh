/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_mergem(string arg1) {
 /* variable(s)
 [v1] input-directory
 [v2] list-of-item(s)-in-[v1]
 [v3] extension
 [v4] text-file-with-[v2]-enlisted
 [v5] output-media
 [inp] mark-input
 [cmd] mark-command
 [err] mark-error/warning
 */
 string inp1 = mark("blue", "[inp] ");
 string cmd = mark("blue", "[] ");
 string err1 = mark("yellow", "[WARNING] ");
 //
 string v1 = arg1;
 if (not dir(v1)) {
  cout <<
  inp1 + v1 + "\n" +
  err1 + "directory not found."
  << endl;
  exit(0);
 }
 vector<string> v2 = tree(v1, false);
 string v3 = "";
 v3 = uri(v2[0])[3];
 if (v3 == "") v3 = ".mp4";
 string v4 = ".list_" + ts() + ".txt";
 string v5 = uri(v1)[1] + "_MERGED_" + ts() + v3;
 // command(s)
 string cmd1 = "ffmpeg -f concat -safe 0 -i " + v4 + " -c copy " + quote(v5);
 // op(s)
 cout << cmd + "item(s) inside " + quote(v4) + ":" << endl;
 for (int i = 0; i < v2.size(); i++) cout << "file '" + v2[i] + "'" << endl;
 cout <<
 cmd + cmd1 + "\n" +
 cmd + "rm " + quote(v4)
 << endl;
}

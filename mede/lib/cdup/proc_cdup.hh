/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void proc_cdup(string arg1) {
 /* variable(s)
 [v1] directory
 [v2] list-of-file(s)-in-[v1]
 [v3] same-list-with-folder(s)-excluded
 [v4] size(s)-of-file(s)-in-[v3]
 [inp] mark-input
 [cmd] mark-command
 [out] mark-output
 [err] mark-error/warning
 */
 string inp1 = mark("blue", "[inp] ");
 string inp2 = mark("blue", "[pwd] ");
 string cmd = mark("blue", "[] ");
 string out1 = mark("green", "DONE.");
 string err1 = mark("yellow", "[WARNING] ");
 //
 string v1 = arg1 + "/";
 vector<string> v2 = {};
 vector<string> v3 = {};
 vector<int> v4 = {};
 // message(s)
 string msg1 = cmd + "clustering file(s)...";
 // op(s)
 if (not dir(v1)) {
  cout <<
  inp1 + v1 + "\n" +
  err1 + "directory not found."
  << endl;
  exit(0);
 }
 if (not write_access()) {
  cout <<
  inp2 + pwd() + "\n" +
  err1 + "write-permission denied!"
  << endl;
  exit(1);
 }
 //
 note(msg1);
 v2 = tree(v1, false);
 for (int i = 0; i < v2.size(); i++) {
  if (dir(v2[i])) continue;
  else v3.push_back(v2[i]);
 }
 for (int i = 0; i < v3.size(); i++) {
  v4.push_back(fsize(v3[i]));
  md(v1 + str(fsize(v3[i])));
  mv(v3[i], v1 + str(fsize(v3[i])));
 }
 // re-using [v2]
 v2 = unique(str(v4));
 // eliminates clusters with only 1 item
 for(int i = 0; i < v2.size(); i++) {
  if (tree(v1 + v2[i], false).size() == 1) {
   mv(tree(v1 + v2[i], false)[0], v1);
   rm(v1 + v2[i]);
  }
  else mv(v2[i], v1);
 }
 cout << out1 << endl;
}

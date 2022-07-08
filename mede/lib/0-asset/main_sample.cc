/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
int main() {
 /* variable(s)
 [v1] source
 [v2] target
 [inp] mark-input
 [cmd] mark-command
 [out] mark-output
 [err] mark-error/warning
 */
 string inp1 = mark("blue", "[source] ");
 string inp2 = mark("blue", "[target] ");
 string cmd = mark("blue", "[] ");
 string out1 = mark("blue", "[out] ");
 string out2 = mark("green", "DONE.");
 string err1 = mark("yellow", "[WARNING] ");
 string err2 = mark("red", "HALTED.""\n""[FAILED] ");
 //
 string v1 = "/usr/lib/mede/mede-asset";
 string v2 = "~/mede-asset";
 // message(s)
 string msg1 =
 out1 + v2 + "\n" +
 cmd + "providing sample-assets...";
 // op(s)
 if (exist(v2)) {
  cout <<
  out1 + v2 + "\n" +
  err1 + "file found."
  << endl;
  exit(0);
 }
 note(msg1);
 bool e = cp(v1, "~");
 if (e) {
  cout <<
  err2 + "file(s) not copied.""\n" +
  inp1 + v1 + "\n" +
  inp2 + v2
  << endl;
  exit(1);
 }
 cout << out2 << endl;
}

/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

#include "../volume.hh"

int main() {
 /* variable(s)
 [v1] source
 [v2] target
 */
 string inp1 = mark("[source] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[out] ", "blue");
 string out2 = mark("DONE.", "green");
 string out3 = mark("[target] ", "blue");
 string err1 = mark("[WARNING] ", "yellow");
 string err2 = mark("HALTED.""\n""[FAILED] ", "red");
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
 volume_f1(v2, true);
 volume_f2(true);
 note(msg1);
 bool e = cp(v1, "~");
 if (e) {
  cout <<
  inp1 + v1 + "\n" +
  out3 + v2 + "\n" +
  err2 + "file(s) not copied."
  << endl;
  exit(1);
 }
 cout << out2 << endl;
}

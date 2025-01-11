/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void volume_f1(string arg1, bool arg2=false) {
 /* variable(s)
 [v1] input-file/folder
 */
 string out1 = mark("[OUT] ", "blue");
 string err1 = mark("[WARNING] ", "yellow");
 //
 string v1 = can(arg1);
 // op(s)
 if (not vol(v1)) {
  cout <<
  out1 + pwd() + "\n" +
  err1 + "no free space left."
  << endl;
  if (arg2) exit(0);
 }
}

void volume_f2(bool arg1=false) {
 /* variable(s) */
 string out1 = mark("[OUT] ", "blue");
 string err1 = mark("[WARNING] ", "yellow");
 // op(s)
 if (not write_access()) {
  cout <<
  out1 + pwd() + "\n" +
  err1 + "write-permission denied."
  << endl;
  if (arg1) exit(0);
 }
}

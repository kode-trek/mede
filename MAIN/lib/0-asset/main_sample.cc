/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

int main() {
 /* variable(s)
 [v1] path to mede-asset
 */
 string out1 = mark("[] ", "blue");
 //
 string v1 = "/usr/lib/mede/mede-asset";
 // op(s)
 cout << out1 + "ls -l " + v1 << endl;
}

/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_meta(string arg1) {
 /* variable(s)
 [v1] input
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 // command(s)
 string cmd1 = "ffprobe " + quote(v1) + " 2>&1 | grep -A90 'Metadata'";
 string cmd2 = "ffprobe " + quote(v1) + " 2>&1 | grep -oP 'Stream .*'";
 // op(s)
 cout <<
 cmd + cmd1 + "\n" +
 cmd + cmd2
 << endl;
}

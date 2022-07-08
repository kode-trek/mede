/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void sim_meta(string arg1) {
 /* variable(s)
 [v1] input
 [cmd] mark-command
 */
 string cmd = mark("blue", "[] ");
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

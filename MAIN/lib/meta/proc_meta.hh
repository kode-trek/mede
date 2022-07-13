/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_meta(string arg1) {
 /* variable(s)
 [v1] input-media
 */
 string inp = mark("[INP] ", "blue");
 //
 string v1 = arg1;
 // message(s)
 string msg1 = inp + uri(v1, "full-name") + "\n\n";
 // command(s)
 int e = 0;
 string cmd1 = "ffprobe " + quote(v1) + " 2>&1 | grep -A90 'Metadata'";
 string cmd2 = "ffprobe " + quote(v1) + " 2>&1 | grep -oP 'Stream .*'";
 // op(s)
 note(msg1);
 e = sys(cmd1 + " 2>/dev/null");
 note("\n");
 e = sys(cmd2 + " 2>/dev/null");
}

/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
void proc_meta(string arg1) {
 /* variable(s)
 [v1] input-media
 [inp] mark-input
 */
 string inp = mark("blue", "[inp] ");
 //
 string v1 = arg1;
 // message(s)
 string msg1 = inp + uri(v1)[1] + "\n\n";
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

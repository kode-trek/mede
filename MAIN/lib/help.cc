/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

int main() {
 string v1 = mark("[MEDia Editor] ", "blue");
 string v2 = mark("[PATTERN] ", "blue");
 string v3 = mark("Linux Mint 21.3 (virginia)", "yellow");
 string v4 = mark("[DEVELOPMENT] ", "yellow");
 // op(s)
 cout <<
 v1 + "edits images/audios/videos preparing them for publishin' on the web.""\n""\n" +
 v2 + "mede sample""\n"
 "provides sample-media in '~/mede-asset'.""\n" +
 v2 + "mede cmd""\n"
 "lists commands.""\n" +
 v2 + "mede <cmd> --help""\n"
 "displays manual for <cmd>-command.""\n" +
 v2 + "mede <cmd> --sim [arg(s)...]""\n"
 "simulates process by displaying corresponding <cmd>-command associated with "
 "supplied argument(s).""\n"
 "\n"
 "this terminal-app had a test-drive on " + v3 + " platform.""\n" +
 v4 + "github.com/kode-trek/mede"
 << endl;
}

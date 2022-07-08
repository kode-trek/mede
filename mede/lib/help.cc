/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
int main() {
 /* variable(s)
 [v1] mark-title
 [v2] mark-pattern
 [v3] OS
 */
 string v1 = mark("blue", "-- M E D ia E ditor --");
 string v2 = mark("blue", "[PATTERN] ");
 string v3 = mark("yellow", "Linux Mint 20.2 (uma)");
 // op(s)
 cout <<
 v1 + "\n" +
 "edits images/audios/videos preparing them for publishin' on the web.""\n" +
 v2 + "mede sample""\n"
 "provides sample-media in '~/mede-asset'.""\n" +
 v2 + "mede cmd""\n"
 "enlists commands.""\n" +
 v2 + "mede <cmd> --help""\n"
 "displays manual for <cmd>.""\n" +
 v2 + "mede <cmd> --sim [arg(s)...]""\n"
 "simulates process by displaying corresponding <cmd> associated with "
 "supplied argument(s).""\n""\n"
 "this terminal-app has been tested on " + v3 + " platform.""\n"
 "[development] github.com/kode-trek"
 << endl;
}

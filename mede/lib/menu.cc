/*
 The MIT License (MIT)
 Copyright (c) 2022 Emeer Adhamian (github.com/kode-trek)
 https://github.com/kode-trek/mede/blob/main/LICENSE
 https://github.com/kode-trek/archive/blob/main/LICENSE
*/
int main() {
 /* variable(s)
 [v1] key-value
 */
 map<string, string> v1;
 v1["adds"] = "\t""\t""adds hard subtitles to video.";
 v1["cdup"] = "\t""\t""clusters file(s) into multiple group(s).";
 v1["ceniv"] = "\t""\t""censors certain part of image/video.";
 v1["cropiv"] = "\t""crops image/video.";
 v1["ena"] = "\t""\t""enumerates file(s).";
 v1["laud"] =
 "\t""\t""mutes video.""\n"
 "\t""\t""extracts sound from video.""\n"
 "\t""\t""blinds screen.""\n"
 "\t""\t""converts MIDI to MP3.";
 v1["mergem"] = "\t""merges multiple media-files into one whole.";
 v1["meta"] = "\t""\t""elicits meta-data including stream(s) in media.";
 v1["pubm"] = "\t""\t""prepares media-file for publishin' on the web.";
 v1["rotiv"] = "\t""\t""rotates image/video.";
 v1["snap"] =
 "\t""\t""takes screenshot.""\n"
 "\t""\t""converts image to JPEG.""\n"
 "\t""\t""combines multiple image(s) into one PDF.""\n"
 "\t""\t""combines multiple image(s) into one video-clip.""\n"
 "\t""\t""records screen.""\n"
 "\t""\t""converts video to GIF.";
 v1["trimm"] = "\t""\t""trims media-file.";
 // op(s)
 for (auto item : v1)
  cout << "[" + mark("blue", item.first) + "]" + item.second << endl;
 cout <<
 "\n""*if " + mark("red", "[FAILED] ") +
 "proceed with successor line to debug in details."
 << endl;
}

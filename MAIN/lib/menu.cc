/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

int main() {
 /* variable(s)
 [v1] key-value
 */
 string err1 = mark("[FAILED] ", "red");
 //
 map<string, string> v1;
 v1["sub"] = "\t""adds hard subtitles to video.";
// v1["cdup"] = "\t""clusters file(s) into multiple group(s).";
 v1["cen"] = "\t""censors certain part of image/video.";
 v1["crop"] = "\t""crops image/video.";
// v1["ena"] = "\t""renames/enumerates file(s).";
 v1["laud"] =
 "\t""enlists audio-track(s) in media.""\n"
 "\t""mutes video.""\n"
 "\t""blinds screen.""\n"
 "\t""extracts sound from video.""\n"
 "\t""converts MIDI to MP3.";
// "\t\t""excludes wind-noise from recorded meeting-voice.""\n"
 v1["merge"] = "\t""merges multiple media-files into one whole.";
 v1["meta"] = "\t""elicits meta-data including stream(s) in media.";
 v1["pub"] = "\t""prepares media-file for publishin' on the web.";
 v1["rot"] = "\t""rotates image/video.";
 v1["snap"] =
 "\t""takes screenshot.""\n"
 "\t""converts image to JPEG.""\n"
//	"\t\t""degrades quality of JPEG (JPG).""\n"
 "\t""combines multiple image(s) into one PDF.""\n"
 "\t""combines multiple image(s) into one video-clip.""\n"
 "\t""records screen.""\n"
 "\t""converts video to GIF.";
 v1["trim"] = "\t""trims image/video."; // image? audio/video OR media-file
 // op(s)
 for (auto item : v1)
  cout << "[" + mark(item.first, "blue") + "]" + item.second << endl;
 cout <<
 "\n""*if " + err1 + "proceed with successor line to debug in details."
 << endl;
}

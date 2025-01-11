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
 v1["cen"] = "\t""censors certain part of image/video.";
 v1["crop"] = "\t""crops image/video.";
 v1["laud"] =
 "\t""lists audio-track(s) in media.""\n"
 "\t""mutes video.""\n"
 "\t""blinds screen.""\n"
 "\t""extracts sound from video.";
 v1["merge"] = "\t""merges multiple audio/video-files into one whole.";
 v1["meta"] = "\t""elicits meta-data including stream(s) in media.";
 v1["pub"] = "\t""prepares media-file for publishin' on the web.";
 v1["rot"] = "\t""rotates image/video.";
 v1["snap"] =
 "\t""takes screenshot.""\n"
 "\t""converts image(s) to JPEG one(s).""\n"
 "\t""combines multiple image(s) into one PDF document.""\n"
 "\t""combines multiple image(s) into one video-clip.""\n"
 "\t""records screen.""\n"
 "\t""converts video to GIF image.";
 v1["trim"] = "\t""trims audio/video.";
 // op(s)
 for (auto item : v1)
  cout << "[" + mark(item.first, "blue") + "]" + item.second << endl;
 cout <<
 "\n""*if " + err1 + "proceed with successor line to debug in details."
 << endl;
}

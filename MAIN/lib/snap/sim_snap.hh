/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void sim_snap(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input-media
 [v3] gap/quality
 [v4] output-media
 */
 string cmd = mark("[] ", "blue");
 //
 string v1 = arg1;
 string v2 = arg2;
 can(v2);
 string v3 = arg3;
 string v4 = "";
 if ((v1 == "--jpg") or (v1 == "--pdf") or (v1 == "--mov"))
  if (v2 == "") v2 = " ";
 if (v1 == "--shot") v4 = "SCREEN-SHOT_" + ts() + ".png";
 if (v1 == "--jpg") {
  if (v3 == "") v3 = "100";
  v4 = uri(v2, "file-name") + "_JPEG_" + ts() + ".jpg";
 }
 if (v1 == "--pdf") v4 = uri(v2, "file-name") + "_PDF_" + ts() + ".pdf";
 if (v1 == "--mov") v4 = uri(v2, "file-name") + "_SLIDE_" + ts() + ".mp4";
 if (v1 == "--roll") v4 = "SCREEN-RECORD_" + ts();
 if (v1 == "--gif") v4 = uri(v2, "file-name") + "_GIF_" + ts() + ".gif";
 // command(s)
 string cmd1 = "import -window root -delay 128 " + quote(v4);
 string cmd2 = "convert " + quote(v2) + " -quality " + v3 + " " + quote(v4);
 string cmd3 = "convert " + quote(v2) + " " + quote(v4);
 string cmd4 = "recordmydesktop --on-the-fly-encoding -o=" + v4;
 string cmd5 = "ffmpeg -i " + quote(v2) + " -vf \"fps=10,scale=320:-1:flags="
 "lanczos,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse\" -loop 0 " +
 quote(v4);
 // op(s)
 volume_f1(v2);
 volume_f2();
 //
 if (v1 == "--shot") {
  cout << cmd + cmd1 << endl;
  exit(0);
 }
 if (v1 == "--jpg") {
  cout << cmd + cmd2 << endl;
  exit(0);
 }
 if (v1 == "--pdf") {
  if (dir(v2)) cmd3 = "convert " + quote(v2) + "/* " + quote(v4);
  cout << cmd + cmd3 << endl;
  exit(0);
 }
 if (v1 == "--mov") {
  if (not dir(v2))
   cmd3 = "convert -delay 128 " + quote(v2) + " " + quote(v4);
  if (dir(v2))
   cmd3 = "convert " + quote(v2 + "/*") + " " + quote(v4);
  cout << cmd + cmd3 << endl;
  exit(0);
 }
 if (v1 == "--roll") {
  cout << cmd + cmd4 << endl;
  exit(0);
 }
 if (v1 == "--gif") {
  cout << cmd + cmd5 << endl;
  exit(0);
 }
}

// if (v1 == "--mov") {
//  if (v3 == "")
//   cmd3 = "convert -delay 128 " + quote(v2) + "/*[x] " + quote(v4);
//  if ((v3 == "on") and (dir(v2)))
//   cmd3 = "convert -delay 128 " + quote(v2) + "/*[x] " + quote(v4);
//  if ((v3 == "off") and (dir(v2)))
//   cmd3 = "convert " + quote(v2) + "/*[x] " + quote(v4);
//  if ((v3 != "") and (dir(v2)) and ((v3 != "on") or (v3 != "off")))
//   cmd3 = "convert -delay 128 " + quote(v2) + "/*[" + v3 + "x] " + quote(v4);
//  cout << cmd + cmd3 << endl;
//  exit(0);
// }

/*
 The MIT License (MIT)
 Copyright (c) 2024 Emeer Adhamian (github.com/kode-trek)
 https://raw.githubusercontent.com/kode-trek/mede/main/LICENSE
*/

void proc_snap(string arg1, string arg2, string arg3) {
 /* variable(s)
 [v1] operation
 [v2] input-media
 [v3] gap/quality
 [v4] output-media
 */
 string inp1 = mark("[INP] ", "blue");
 string cmd = mark("[] ", "blue");
 string out1 = mark("[OUT] ", "blue");
 string out2 = mark("DONE.", "green");
 string err1 = mark("HALTED.""\n""[FAILED] ", "red");
 //
 string v1 = arg1;
 string v2 = can(arg2);
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
 // message(s)
 string msg1 =
 out1 + v4 + "\n" +
 cmd + "saving screen-shot...";
 string msg2 =
 inp1 + uri(v2, "full-name") + "\n" +
 out1 + v4 + "\n" +
 cmd + "converting image to JPEG...";
 string msg3 =
 inp1 + uri(v2, "full-name") + "\n" +
 out1 + v4 + "\n" +
 cmd + "combining image(s) into PDF...";
 string msg4 =
 inp1 + uri(v2, "full-name") + "\n" +
 out1 + v4 + "\n" +
 cmd + "combining image(s) into video-clip...";
 string msg5 =
 mark("[STOP] ", "yellow") + "<CTRL> + <ALT> + S""\n" +
 out1 + v4 + "\n" +
 cmd + "recording screen...";
 string msg6 =
 inp1 + uri(v2, "full-name") + "\n" +
 out1 + v4 + "\n" +
 cmd + "converting video to GIF...";
 // command(s)
 int e = 0;
 string cmd1 = "import -window root -delay 128 " + quote(v4);
 string cmd2 = "convert " + quote(v2) + " -quality " + v3 + " " + quote(v4);
 string cmd3 = "convert " + quote(v2) + " " + quote(v4);
 string cmd4 = "recordmydesktop --on-the-fly-encoding -o=" + v4;
 string cmd5 = "ffmpeg -i " + quote(v2) + " -vf \"fps=10,scale=320:-1:flags="
 "lanczos,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse\" -loop 0 " +
 quote(v4);
 // op(s)
 volume_f1(v2, true);
 if (v1 == "--shot") {
  note(msg1);
  e = sys(cmd1 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd1 << endl;
   rm(v4);
   exit(e);
  }
  cout << out2 << endl;
  exit(e);
 }
 if (v1 == "--jpg") {
  note(msg2);
  e = sys(cmd2 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd2 << endl;
   rm(v4);
   exit(e);
  }
  cout << out2 << endl;
  exit(0);
 }
 if (v1 == "--pdf") {
  note(msg3);
  if (dir(v2)) cmd3 = "convert " + quote(v2) + "/* " + quote(v4);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd3 << endl;
   rm(v4);
   exit(e);
  }
  cout << out2 << endl;
  exit(e);
 }
 if (v1 == "--mov") {
  note(msg4);
  if (not dir(v2))
   cmd3 = "convert -delay 128 " + quote(v2) + " " + quote(v4);
  if (dir(v2))
   cmd3 = "convert " + quote(v2 + "/*") + " " + quote(v4);
  e = sys(cmd3 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd3 << endl;
   rm(v4);
   exit(e);
  }
  cout << out2 << endl;
  exit(e);
 }
 if (v1 == "--roll") {
  note(msg5);
  int e = sys(cmd4 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd4 << endl;
   rm(v4);
   exit(e);
  }
  cout << out2 << endl;
  exit(e);
 }
 if (v1 == "--gif") {
  note(msg6);
  e = sys(cmd5 + " 1>/dev/null 2>/dev/null");
  if (e) {
   cout << err1 + cmd5 << endl;
   rm(v4);
   exit(e);
  }
  cout << out2 << endl;
  exit(e);
 }
}

//convert -delay 128 -loop 0 bb/*.jpg[400x] myimage.gif
// string cmd5 = "ffmpeg -i " + quote(v2) + " -vf \"fps=10,scale=320:-1:flags="
// "lanczos,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse\" -loop 0 " +
// quote(v4);

//	string inp = arg1; abbr(inp);
//	string gap = arg2; if (gap == "") gap = "off";
//	string dly = " -delay 128 "; if (gap == "off") dly = " ";
// if (v1 == "--mov") {
//  if (v3 == "")
//   cmd3 = "convert -delay 128 " + quote(v2) + "/*[x] " + quote(v4);
//  if ((v3 == "on") and (dir(v2)))
//   cmd3 = "convert -delay 128 " + quote(v2) + "/*[x] " + quote(v4);
//  if ((v3 == "off") and (dir(v2)))
//   cmd3 = "convert " + quote(v2) + "/*[x] " + quote(v4);
//  if ((v3 != "") and (dir(v2)) and ((v3 != "on") or (v3 != "off")))
//   cmd3 = "convert -delay 128 " + quote(v2) + "/*[" + v3 + "x] " + quote(v4);
//  disp(msg4);

//convert original.png -resize 100x100 new.png

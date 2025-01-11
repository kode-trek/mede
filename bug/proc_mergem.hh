void proc_mergem(string arg1, string arg2) {
 //var(s)
 string inp = "";
 if (arg1 != "") {
  unsigned short int idx = strlen(arg1.c_str()) - 1;
  if (arg1[idx] != '/') inp = arg1 + "/";
  else inp = arg1;
 }
 if (not exist(inp)) {
  cout << "directory not found: " << shortq(inp) << endl;
  exit(1);
 }
 if (empty(inp)) {
  cout << "directory is empty: " << uri(inp)[1] << endl;
  exit(1);
 }
 vector<string> l = tree(inp, false);
 string list = "";
 for (unsigned long long int i = 0; i < l.size(); i++)
  list += " -i " + quote(l[i]);
 string map = "";
 for (unsigned long long int i = 0; i < l.size(); i++)
  map += "[" + str(i) + ":v:0][" + str(i) + ":a:0]";
 string ext = ""; ext = uri(l[0])[3];
 if (ext == "") ext = ".mp4";
 string out = "merged_" + ts() + ext;
 string lst_f = "list_" + ts() + ".txt";
 //msg(s)
 string msg1 =
 "[inp] " + uri(inp)[1] + "\n"
 "[out] " + uri(out)[1] + "\n"
 "[] merging file(s) in directory...";
 //cmd(s)
 int c = 0;
 string cmd1 = "ffmpeg " + list + " -filter_complex '" + map +
 " concat=n=" + str(l.size()) + ":v=1:a=1 [v][a]' -map '[v]' -map '[a]' "
 + quote(out);
 string cmd2 = "ffmpeg -f concat -safe 0 -i " + lst_f + " -c copy " +
 quote(out);
 //op(s)
 disp(msg1);
 if (arg2 == "--dirty") {
  for (int i = 0; i < l.size(); i++)
   drop(lst_f, "file " + squote(l[i]) + "\n");
  c = sys(cmd2 + " -y 1>/dev/null 2>/dev/null");
  if (c) {
   cout << "HALTED.""\n""[FAILED] " << cmd1 << endl;
   cout << "Line(s) inside " << squote(lst_f) << ":" << endl;
   sys("cat -n " + lst_f);
   rm(out);
   rm(lst_f);
   exit(1);
  }
  rm(lst_f);
  cout << "DONE." << endl;
 }
 if (arg2 != "--dirty") {
  c = sys(cmd1 + " -y 1>/dev/null 2>/dev/null");
  if (c) {
   cout << "HALTED.""\n""[FAILED] " << cmd1 << endl;
   rm(out);
   exit(1);
  }
  cout << "DONE." << endl;
 }
}

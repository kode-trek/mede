void sim_trimm(string arg1, string arg2, string arg3) {
	//var(s)
	string inp = arg1;
	abbr(inp);
	string t1 = arg2;
	string t2 = arg3;
	string map = "";
	int n_channel = meds(inp)[2];
	for (short int i = 0; i < n_channel; i++) map += " -map 0:" + str(i);
	string ext = ""; ext = uri(inp)[3]; if (ext == "") ext = ".mp4";
	string out = uri(inp)[2] + "_trimmed_" + ts() + ext;
	//op(s)
	cout <<
	"[...] trims " << shortq(uri(inp)[1]) << ".""\n"
	"[] ffmpeg -i " << quote(inp) << " -ss " << t1 << " -to " << t2 << map <<
	" " << quote(out)
	<< endl;
}
//"[] ffmpeg -i " << quote(inp) <<
//"-strict experimental -c:a aac -async 1 -ss " << quote(t1) << " -to " <<
//quote(t2) << " " << quote(out)

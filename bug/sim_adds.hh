

//	string cmd2 = "ffmpeg -i " + as_is(inp) + " -c:a aac -async 1 -vf ass=" + \
//	as_is(ass) + " " + as_is(out);

void sim_adds(string arg1, string arg2) {
	//var(s)
	string sub = arg1; abbr(sub);
	string inp = arg2; abbr(inp);
	string ass = "." + uri(sub)[2] + ".ass";
	string map = "";
	short int n_channel = str2num(media_type(inp)[0]);
	for (int i = 0; i < n_channel; i++) map += " -map 0:" + to_string(i);
	string out = uri(inp)[2] + "_subbed_" + time_stamp() + uri(inp)[3];
	//op(s)
	cout <<
	"[...] converts <.SRT> to <.ASS>.""\n"
	"[] ffmpeg -i " << quote(sub) << " " << quote(ass) << "\n"
	"[...] adds <inp-sub.ASS> to <inp-vid>.""\n"
	"[] ffmpeg -i " << quote(inp) << " -vf ass=" << quote(ass) << map << " " <<
	quote(out)
	<< endl;
}

void proc_caud(string arg1, string arg2) {
	int c = 0;
	string cmd1, cmd2 = "";
	//
	string inp = arg1;
	string out = uri(inp)[2] + "_sound_" + ts() + ".mp3";
	bool squeez = false; if (arg2 == "--squeez") {squeez = true;}
	//
	if (squeez == false) {
		disp("[] converting <inp-med> to <out-aud.MP3>...");
		cmd1 = "ffmpeg -i " + as_is(inp) + " -map 0:1" + \
		" -vf tblend=all_mode=grainextract " + \
		" -map_metadata -1 -map_chapters -1 -c:a libmp3lame " + as_is(out);
		cmd2 = "ffmpeg -i " + as_is(inp) + \
		" -vf tblend=all_mode=grainextract " + \
		" -map_metadata -1 -map_chapters -1 -c:a libmp3lame " + as_is(out);
		c = sys(cmd1 + " -y 2>/dev/null");
		if (c != 0) {
			rm(out);
			c = sys(cmd2 + " -y 2>/dev/null");
			if (c != 0) {cout << endl << "[FAILED] " << cmd2 << endl; rm(out);
			exit(1);}
		}
		cout << "DONE." << endl;
		//
		cout << "[OK] sound extracted from <inp-med>." << endl; exit(1);
	}
	//
	disp("[] converting <inp-med> to <out-aud.MP3> and degrading quality...");
	out = uri(inp)[2] + "_squeezed_" + ts() + ".mp3";
	cmd1 = "ffmpeg -i " + as_is(inp) + " -map 0:1" + \
	" -vf tblend=all_mode=grainextract -map_metadata -1 -map_chapters -1 " + \
	"-acodec libmp3lame -b:a 8k -ac 1 -ar 11025 " + as_is(out);
	cmd2 = "ffmpeg -i " + as_is(inp) + \
	" -vf tblend=all_mode=grainextract -map_metadata -1 -map_chapters -1 " + \
	"-acodec libmp3lame -b:a 8k -ac 1 -ar 11025 " + as_is(out);
	c = sys(cmd1 + " -y 2>/dev/null");
	if (c != 0) {
		rm(out);
		c = sys(cmd2 + " -y 2>/dev/null");
		if (c != 0) {cout << endl << "[FAILED] " << cmd2 << endl; rm(out); exit(1);}
	}
	cout << "DONE." << endl;
	//
	cout << "[OK] audio lost quality." << endl; exit(1);
}

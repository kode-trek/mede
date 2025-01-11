#include "../media.hh"

void proc_snap(string arg1,string arg2) {
	//var(s)
	string inp = arg1; abbr(inp);
	string gap = arg2; if (gap == "") gap = "off";
	string dly = " -delay 128 "; if (gap == "off") dly = " ";
	string tmp = ts();
	string out = "";
	out = tmp + "/" + uri(inp)[2] + "_JPEG_" + ts() + ".jpg";
	if (dir(inp)) out = uri(inp)[2] + "_SLIDE_" + ts() + ".mp4";
	//msg(s)
	string msg1 = "[] converting " + shortq(uri(inp)[1]) + " to " + tmp + "/" +
	shortq(uri(out)[1]) + "...";
	string msg2 = "[] combining images within " + shortq(uri(inp)[1]) + " into " +
	shortq(uri(out)[1]) + "...";
	string msg3 = "[OK] screenshot saved in " +
	quote(pwd() + "/" + tmp + ".png") + ".";
	//cmd(s)
	int c = 0;
	string cmd1 = "convert " + quote(inp) + " " + quote(out);
	string cmd2 = "convert" + dly + "-quality 100 " + quote(inp) + "/* " +
	quote(out);
	string cmd3 = "import -window root -delay 200 " + tmp + ".png";
	//op(s)
	if(inp == "--shot") {
		c = sys(cmd3 + " 1>/dev/null 2>/dev/null");
		if (c) {cout << "[FAILED] " << cmd3 << endl; exit(1);}
		cout << msg3 << endl;
		exit(0);
	}
	if(dir(inp)) {
		disp(msg2);
		c = sys(cmd2 + " 1>/dev/null 2>/dev/null");
		cout << "DONE." << endl; exit(0);
	}
	disp(msg1);
	mkdir(tmp);
	c = sys(cmd1 + " 1>/dev/null 2>/dev/null");
	if (c) {cout << "HALTED.""\n""[FAILED] " << cmd1 << endl; rm(tmp); exit(1);}
	cout << "DONE." << endl;
}

int main(int argc, char* argv[]) {
	vector<string> v = tree(argv[1]);
	enlist(v);
	for (int i = 0; i < v.size(); i++) {
		if (dir(v[i])) {cout << "DIR" << endl; continue;}
		sys("ffprobe " + quote(v[i]) + R"( 2>&1 | grep -A90 'Metadata:')");
	}
}

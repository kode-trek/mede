#include "proc_laud.hh"
#include "sim_laud.hh"

int main(int argc, char* argv[]) {
	if (str(argv[1]) == "") {
		cout <<
		"-- L eak A U D io --""\n"
		"mutes video.""\n"
		"extracts sound from video.""\n"
		"excludes wind-noise from recorded meeting-voice.""\n"
		"blinds screen.""\n"
		"\n"
		"medp laud --help"
		<< endl;
		exit(0);
	}
	if (str(argv[1]) == "--help") {
		cout <<
		"[PATTERN] medp laud <inp-med>""\n"
		"displays audio-tracks of <inp-med>.""\n"
		"\n"
		"[PATTERN] medp laud <inp-vid> <--mute>""\n"
		"converts <inp-vid> to silent <out-vid.MP4>.""\n"
		"\n"
		"[PATTERN] medp laud <inp-med> <--sound> [<aud>=0]""\n"
		"converts <inp-med> to <out-aud.MP3>. maps '0:aud' audio-track.""\n"
		"\n"
		"[PATTERN] medp laud <inp-med> <--squeeze> [<aud>=0]""\n"
		"compresses <inp-med> to quality-degraded <out-aud.MP3>.""\n"
		"maps '0:aud' audio-track.""\n"
		"\n"
		"[PATTERN] medp laud <inp-vid> <--blind> [<aud>=0]""\n"
		"converts <inp-vid> to <out-vid.MP4>.""\n"
		"eliminates '0:0' video-track. maps '0:aud' audio-track.""\n"
		"\n"
		"[EXAMPLE] medp laud 'my-vid.avi' '--sound' '2'""\n"
		"extracts '0:2' audio-track from 'my-vid.avi'.""\n"
		"\n"
		"[EXAMPLE] medp laud 'my-rec.wav' '--squeeze'""\n"
		"compresses 'my-rec.wav'. attempts to omit wind-noise."
		<< endl;
		exit(0);
	}
	if (str(argv[1]) == "--sim") {sim_laud(argv[2], argv[3], argv[4]); exit(0);}
	proc_laud(argv[1], argv[2], argv[3]);
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string replace(const string& src, const char *f, const char *r)
{
	string s(src);
	size_t pos = s.find(f);
	for (; pos != string::npos; pos = s.find(f)) {
		s.replace(pos, 2, r);
	}
	return s;
}
int main(int argc, char *argv[])
{
	vector<string> short_cut;
	const char keys[] = "ABXY";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			string conf;
			conf += keys[i];
			conf += keys[j];
			short_cut.push_back(conf);
		}
	}

	string cmd;
	getline(cin, cmd);
	getline(cin, cmd);

	int len = cmd.size();
	vector<string>::const_iterator sc1, sc2;
	for (sc1 = short_cut.begin(); sc1 != short_cut.end(); ++sc1) {
		for (sc2 = short_cut.begin(); sc2 != short_cut.end(); ++sc2) {
			if (*sc1 == *sc2) break;
			string c = replace(cmd, sc1->c_str(), "L");
			int new_len = replace(c, sc2->c_str(), "R").size();
			if (new_len < len) len = new_len;
		}
	}
	cout << len << endl;
	
	return 0;
}

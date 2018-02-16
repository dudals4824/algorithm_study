#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string animal;
string sound;
string goes;
string words;

int main(void) {
	int T, test_case;
	int pos;

	cin >> T;
	cin.ignore();
	for (test_case = 0; test_case < T; test_case++) {
		getline(cin, words);
		while (true) {
			cin >> animal >> goes >> sound;
			if (animal == "what" && goes == "does") {
				break;
			}
			pos = 0;
			while (true) {
				if (pos != 0) pos++;
				pos = words.find(sound, pos);
				if (pos == string::npos) break;
				if (pos!=0 && words[pos - 1] == ' ') {
					words.erase(pos, sound.length() + 1);
					pos = 0;
				}
				else if (pos + sound.length() != words.length() -1 && words[pos + sound.length()] == ' ') {
					words.erase(pos, sound.length() + 1);
					pos = 0;
				}
			}	
		}
		cout << words << endl;
		getline(cin, goes);
	}

	return 0;
}
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

static int test_case;
static string s;
static stack<string> str[26];
static stack<string> cmp;

int main(void) {

	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {
		cin >> s;


		for (int k = 0; k < s.size(); k = k + 2) {
			int idx = s.substr(k, 2).at(0) % 97;
			int stack_size = str[idx].size();
			string temp;

			if (str[idx].empty())
				str[idx].push(s.substr(k, 2));

			else {
				temp = s.substr(k, 2);
				while (str[idx].size() != stack_size + 1) {
					
					if (str[idx].empty()){
						str[idx].push(temp);
					
						while (!cmp.empty()) {
							str[idx].push(cmp.top());
							cmp.pop();
						}

					}

					else if (str[idx].top().at(1) < temp.at(1)){
						str[idx].push(temp);
						
						while (!cmp.empty()) {
							str[idx].push(cmp.top());
							cmp.pop();
						}
					}

					else {
						cmp.push(str[idx].top());
						str[idx].pop();
					}
				}

			}
		}


		for (int k = 0; k < 26; k++) {
			while (!str[k].empty()) {
				cmp.push(str[k].top());
				str[k].pop();
			}
			while (!cmp.empty()) {
				cout << cmp.top();
				cmp.pop();
			}
		}

		cout << endl;
	}// test_case

	system("pause");

	return 0;
}


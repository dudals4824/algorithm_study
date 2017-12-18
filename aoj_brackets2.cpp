#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

static int test_case;
static stack<char> s;
static string bracket;
static string Answer = "YES";

int main(void) {

	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {
		cin >> bracket;

		for (int k = 0; k < bracket.length(); k++) {
			char temp = bracket.at(k);

			if (temp == '(' || temp == '{' || temp == '[')
				s.push(temp);

			else if (temp == ')') {
				if (s.empty()) {
					Answer = "NO";
					break;
				}
				else if (s.top() == '(')
					s.pop();

				else {
					Answer = "NO";
					break;
				}
			}

			else if (temp == '}') {
				if (s.empty()) {
					Answer = "NO";
					break;
				}
				else if (s.top() == '{')
					s.pop();
				else {
					Answer = "NO";
					break;
				}
			}

			else if (temp == ']') {

				if (s.empty()) {
					Answer = "NO";
					break;
				}
				else if (s.top() == '[')
					s.pop();
				else {
					Answer = "NO";
					break;
				}
			}

		}

		if (!s.empty())
			Answer = "NO";

		cout << Answer << endl;

		while (!s.empty())
			s.pop();

		Answer = "YES";
	}// test_case
	system("pause");
	return 0;
}


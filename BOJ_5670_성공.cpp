#include <iostream>
#include<algorithm>
#include <string.h>

using namespace std;
bool first;
static char arr[100000][81];
struct Trie {
	Trie * next[26];
	bool eol;
	int notNull = 0;
	// 생성자
	Trie() {
		eol = false;
		memset(next, NULL, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}
	void insert(char * num) {
		// 맨 마지막 숫자일때 끝이라고 표시
		if (*num == '\0') eol = true;
		else {
			char cur_num = *num - 'a';

			if (next[cur_num] == NULL) {
				notNull++; next[cur_num] = new Trie;
			}
			next[cur_num]->insert(num + 1);
		}
	}
	void check(char * num, int & check) {
		if (*num == '\0') return;
		// 만약, 글자가 끝나지 않았는데 true가 있다면
		// 입력해야할 문자가 하나 더있다는 뜻이니까 그때 하나 더 추가
		int cur_num = *num - 'a';
		if (first) {
			first = false; check++;
		}
		else {
			if (eol) {
				check++;
			}
			else if (notNull >= 2) check++;
			// 트라이중에 채워져 있는 문자가 2개 이상일 경우 확인 후 숫자 올려줌
		}
		return next[cur_num]->check(num + 1, check);
	}
};
int main(void) {
	int * num;
	int N = 0;
	double Answer = 0;

	//freopen("input.txt", "r", stdin);

	while (cin >> N) {
		num = new int[N];
		Answer = 0;
		//문자열 처럼 입력
		for (int i = 0; i < N; i++) {
			cin >> arr[i]; num[i] = 0;
		}
		// root 밑에 0~9까지 Trie 노드 생김
		Trie * root = new Trie;

		// Trie에 넣어야함.
		for (int i = 0; i < N; i++) { 
			root->insert(arr[i]); 
		}

		for (int i = 0; i < N; i++) {
			first = true;
			root->check(arr[i], num[i]);
		}

		for (int i = 0; i < N; i++) { 
			Answer += num[i];
		}
		delete root;

		cout << fixed;
		cout.precision(2);

		cout << (double)Answer / (double)N << endl;
	}
	return 0;
}
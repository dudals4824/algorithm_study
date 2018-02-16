#include <iostream>
#include<algorithm>
#include <string>

using namespace std; 
struct Trie {
	Trie * next[10];
	bool eol;
	// 생성자
	Trie() {
		eol = false;
		memset(next, NULL, sizeof(next));
	}

	void insert(char * num) {
		// 맨 마지막 숫자일때 끝이라고 표시
		if (*num == '\0') eol = true;
		else{
		int cur_num = *num - '0';

		if (next[cur_num] == NULL) next[cur_num] = new Trie();

		next[cur_num]->insert(num + 1);
		}
	}

	// 이게 일관성 있는지 아닌지 알려면
	// 1개의 도로? 트리? 안에 true가 중간에 있으면 안돼
	// 만약에 true가 중간에 껴있는게 확인 되면 그때 No라고 출력하면된다. 바로 깨버리고

	bool check(char * num) {
		if (*num == '\0') return true;
		if (eol) return false;
		
		int cur_num = *num - '0';
		return next[cur_num]->check(num + 1);
	}

};

int main(void){

	char arr[10000][10];
	int T, tc;
	int N;
	bool flag = true;

	cin >> T;
	for (tc = 0; tc < T; tc++) {
		cin >> N;
		flag = true;
		//문자열 처럼 입력
		for (int i = 0; i < N; i++) cin >> arr[i];

		// root 밑에 0~9까지 Trie 노드 생김
		Trie * root = new Trie();

		// Trie에 넣어야함.
		for (int i = 0; i < N; i++) {
			root->insert(arr[i]);
		}

		for (int i = 0; i < N; i++) {
			if (!root->check(arr[i])) { flag = false; break; }
		}
		if (!flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}
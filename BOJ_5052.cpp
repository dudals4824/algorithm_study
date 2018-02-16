#include <iostream>
#include<algorithm>
#include <string>

using namespace std; 
struct Trie {
	Trie * next[10];
	bool eol;
	// ������
	Trie() {
		eol = false;
		memset(next, NULL, sizeof(next));
	}

	void insert(char * num) {
		// �� ������ �����϶� ���̶�� ǥ��
		if (*num == '\0') eol = true;
		else{
		int cur_num = *num - '0';

		if (next[cur_num] == NULL) next[cur_num] = new Trie();

		next[cur_num]->insert(num + 1);
		}
	}

	// �̰� �ϰ��� �ִ��� �ƴ��� �˷���
	// 1���� ����? Ʈ��? �ȿ� true�� �߰��� ������ �ȵ�
	// ���࿡ true�� �߰��� ���ִ°� Ȯ�� �Ǹ� �׶� No��� ����ϸ�ȴ�. �ٷ� ��������

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
		//���ڿ� ó�� �Է�
		for (int i = 0; i < N; i++) cin >> arr[i];

		// root �ؿ� 0~9���� Trie ��� ����
		Trie * root = new Trie();

		// Trie�� �־����.
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
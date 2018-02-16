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
	// ������
	Trie() {
		eol = false;
		memset(next, NULL, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}
	void insert(char * num) {
		// �� ������ �����϶� ���̶�� ǥ��
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
		// ����, ���ڰ� ������ �ʾҴµ� true�� �ִٸ�
		// �Է��ؾ��� ���ڰ� �ϳ� ���ִٴ� ���̴ϱ� �׶� �ϳ� �� �߰�
		int cur_num = *num - 'a';
		if (first) {
			first = false; check++;
		}
		else {
			if (eol) {
				check++;
			}
			else if (notNull >= 2) check++;
			// Ʈ�����߿� ä���� �ִ� ���ڰ� 2�� �̻��� ��� Ȯ�� �� ���� �÷���
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
		//���ڿ� ó�� �Է�
		for (int i = 0; i < N; i++) {
			cin >> arr[i]; num[i] = 0;
		}
		// root �ؿ� 0~9���� Trie ��� ����
		Trie * root = new Trie;

		// Trie�� �־����.
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
#include <iostream>
#include<algorithm>
#include <string.h>

using namespace std;
int iter = 1;
static char arr[100000][81];
struct Trie {
	Trie * next[26];
	bool eol;
	// ������
	Trie() {
		eol = false;
		memset(next, NULL, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])delete(next[i]);
	}
	void insert(char * num) {
		// �� ������ �����϶� ���̶�� ǥ��
		if (*num == '\0') eol = true;
		else {
			char cur_num = *num - 'a';

			if (next[cur_num] == NULL) next[cur_num] = new Trie();

			next[cur_num]->insert(num + 1);
		}
	}
	void check(char * num, int & check) {

		int notNull = 0;

		if (*num == '\0') return;
		// ����, ���ڰ� ������ �ʾҴµ� true�� �ִٸ�
		// �Է��ؾ��� ���ڰ� �ϳ� ���ִٴ� ���̴ϱ� �׶� �ϳ� �� �߰�
		if (eol) {
			check++;
			return;
		}
		// �ݺ�Ƚ�� 1ȸ �϶� �ϳ� ������ �÷��ش�.
		if (iter == 1) check++;
		int cur_num = *num - 'a';
		// Ʈ�����߿� ä���� �ִ� ���ڰ� 2�� �̻��� ��� Ȯ�� �� ���� �÷���
		for (int i = 0; i < 26; i++)
			if (next[cur_num]->next[i] != NULL)
				notNull++;
		if (notNull >= 2 && next[cur_num]->eol != true) check++;
		iter++;
		return next[cur_num]->check(num + 1, check);
	}
};
int main(void) {
	int * num;
	int N = 0;
	float Answer = 0;

	freopen("input.txt", "r", stdin);

	while (cin >> N) {
		num = new int[N];
		Answer = 0;
		//���ڿ� ó�� �Է�
		for (int i = 0; i < N; i++) {
			cin >> arr[i]; num[i] = 0;
		}
		// root �ؿ� 0~9���� Trie ��� ����
		Trie * root = new Trie();

		// Trie�� �־����.
		for (int i = 0; i < N; i++) { 
			root->insert(arr[i]); 
		}

		for (int i = 0; i < N; i++) {
			iter = 1;
			root->check(arr[i], num[i]);
		}

		for (int i = 0; i < N; i++) { 
			Answer += num[i];
			cout << num[i] << " ";
		}
		cout << endl;
		delete(root);

		cout << fixed;
		cout.precision(2);

		cout << Answer / N << endl;
	}
	return 0;
}
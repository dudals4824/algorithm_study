#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

static int Answer = 0;
int N, M;
vector<int> coin;
void func(int preIdx, int sum);
int main(void) {

	cin >> N >> M;

	int temp;

	for (int i = 0; i < M; i++) {
		cin >> temp;
		coin.push_back(temp);
	}


	sort(coin.begin(), coin.end());
	
	func(0, 0);

	cout << Answer << endl;

	return 0;
}
void func(int curIdx, int sum) {
	cout << "���� �ε��� : " << curIdx << " ������� ��" << sum << endl;
	if (sum > N) return;

	if (sum == N) {
		Answer++; return;
	}
	if (curIdx >= M) return;

	// ���� �ε����� �����Ҷ�
	func(curIdx, sum + coin.at(curIdx));
	// ���� �ε����� �������� ������
	func(curIdx + 1, sum);
}

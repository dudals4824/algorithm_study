#include<iostream>
#include<string>
using namespace std;

static int value[10001];
static int num[101];

int main(void) {

	int N, K;
	
	cin >> N >> K;

	//동전 가치 입력
	for (int i = 1; i <= N; i++)
		cin >> num[i];

	for (int i = 1; i <= K; i++)
		value[i] = 0;

	value[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - num[i] >= 0)
				value[j] += value[j - num[i]];
		}
	}

	cout << value[K] << endl;

	system("pause");

	return 0;
}


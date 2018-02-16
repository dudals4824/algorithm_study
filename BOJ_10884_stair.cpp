#include<iostream>
#include<algorithm>
#define DIV 1000000000
using namespace std;

int N;
long long int Answer = 0;
long long int ** arr;
int main(void) {

	cin >> N;

	arr = new long long int*[N + 1];
	for (int i = 1; i <= N; i++)
		arr[i] = new long long int[10];

	arr[1][0] = 0;
	for (int i = 1; i < 10; i++)
		arr[1][i] = 1;

	if (N != 1) {
		for (int i = 1; i < N; i++) {
			arr[i + 1][0] = arr[i][1] % DIV;
			for (int k = 1; k < 10; k++)
				arr[i + 1][k] = arr[i][k - 1] % DIV + arr[i][k + 1] % DIV;
			arr[i + 1][9] = arr[i][8] % DIV;
		}

		for (int i = 0; i < 10; i++){
			Answer += arr[N][i] % DIV;
			Answer %= DIV;
		}
	}
	else
		for (int i = 1; i < 10; i++)
			Answer += arr[1][i];

	cout << Answer % DIV << endl;
	return 0;
}

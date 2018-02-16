#include <iostream>
#include <algorithm>
using namespace std;

int V[101];
int N, S, M;
int func(int mid, int next);
int main(void) {

	int mid;
	int a, b;
	int Answer;

	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}
	if (N != 1) {
		mid = S + V[1];
		if (mid <= M) {
			a = func(mid, 2);
		}

		mid = S - V[1];
		if (mid >= 0) {
			b = func(mid, 2);
		}
		Answer = max(a, b);
		if (Answer < 0 || Answer > M) {
			cout << -1 << endl;
		}
		else {
			cout << Answer << endl;
		}
	}
	else {
		if (S + V[1] <= M) {
			cout << S + V[1] << endl;
		}
		else {
			if (S - V[1] >= 0) {
				cout << S - V[1] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
int func(int mid, int next) {
	if (mid > M || mid < 0) return -1;

	if (next == N) {
		if (mid + V[N] <= M) {
			return mid + V[N];
		}
		else
			return mid - V[N];
	}

	int tempA = -100, tempB = -100;

	mid = mid + V[next];
	tempA = func(mid, next + 1);

	mid = mid - V[next]*2;
	tempB = func(mid, next + 1);

	return max(tempA, tempB);
}
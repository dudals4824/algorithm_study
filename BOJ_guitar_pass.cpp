#include <iostream>
#include <algorithm>
using namespace std;

int V[101];
int N, S, M, P;
bool dp[101][1001];
bool flag = false;
int main(void) {

	cin >> N >> S >> M;
	V[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}

	for (int i = 0; i <= N; i++) {
		for (int k = 0; k <= M; k++) {
			dp[i][k] = false;
		}
	}

	dp[0][S] = true;
	for (int i = 0; i <= N; i++) {
		for(int k = 0 ; k<=M ; k++){
			if (dp[i][k]) {
				P = k;
				if (P + V[i + 1] <= M) dp[i + 1][P + V[i + 1]] = true;
				if (P - V[i + 1] >= 0) dp[i + 1][P - V[i + 1]] = true;
			}
		}
	}

	for (int k = M; k >= 0; k--) {
		if (dp[N][k]) {
			cout << k << endl;
			flag = true;
			break;
		}
	}

	if (!flag) cout << -1 << endl;
	return 0;
}

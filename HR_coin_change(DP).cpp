#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
unsigned long int ** dp;
vector<int> coin;
int func(int preIdx, int sum);
int main(void) {

	cin >> N >> M;

	int temp;

	for (int i = 0; i < M; i++) {
		cin >> temp;
		coin.push_back(temp);
	}

	dp = new unsigned long int*[M+1];
	for (int i = 0; i <= M; i++) dp[i] = new unsigned long int[N+1];

	for (int i = 0; i <= M; i++)
		for (int k = 0; k <= N; k++)
			dp[i][k] = -1;

	sort(coin.begin(), coin.end());
	
	func(0, 0);

	cout << dp[0][0] << endl;

	return 0;
}
int func(int curIdx, int sum) {
	unsigned long int ret = 0;

	if (sum == N) return 1;

	if (sum > N) return ret;
	
	if (curIdx >= M) return ret;

	if (dp[curIdx][sum] >= 0) return dp[curIdx][sum];

	// 현재 인덱스를 포함할때
	ret += func(curIdx, sum + coin.at(curIdx));
	// 현재 인덱스를 포함하지 않을때
	ret += func(curIdx + 1, sum);
	
	dp[curIdx][sum] = ret;

	return ret;
}

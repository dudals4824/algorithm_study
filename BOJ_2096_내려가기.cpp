#include <iostream>
#include <algorithm>
using namespace std;
short arr[3];
int max_dp[2][3];
int min_dp[2][3];
int max_Answer = 0;
int min_Answer = INT_MAX;
int main(void)
{
	int N;
	cin >> N;


	for (int i = 0; i < N; i++)
		for (int k = 0; k < 3; k++) {
			max_dp[i][k] = 0; min_dp[i][k] = 0;
		}
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k < 3; k++) cin >> arr[k];

		max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + arr[0];
		max_dp[1][1] = max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2])) + arr[1];
		max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + arr[2];

		max_dp[0][0] = max_dp[1][0];
		max_dp[0][1] = max_dp[1][1];
		max_dp[0][2] = max_dp[1][2];

		min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + arr[0];
		min_dp[1][1] = min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2])) + arr[1];
		min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + arr[2];

		min_dp[0][0] = min_dp[1][0];
		min_dp[0][1] = min_dp[1][1];
		min_dp[0][2] = min_dp[1][2];

	}
	
	max_Answer = max(max_dp[1][0], max(max_dp[1][1], max_dp[1][2]));
	min_Answer = min(min_dp[1][0], min(min_dp[1][1], min_dp[1][2]));
	cout << max_Answer << " "<< min_Answer << endl;
	return 0;
}


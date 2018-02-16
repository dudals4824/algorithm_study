#include <iostream>
#include <algorithm>
using namespace std;

int subsequence_sum;
int subarray_sum =0;
int ** dp;
bool check = false;
int * arr;
int func(int start, int length);
int main(void)
{
	int T, test_case;
	int N;
	
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		subsequence_sum = 0;
		subarray_sum = 0;
		check = false;
		arr = new int[N];

		dp = new int *[N];
		for (int i = 0; i < N; i++) dp[i] = new int[N + 1];

		for (int i = 0; i < N; i++) cin >> arr[i];


		for (int i = 0; i < N; i++)
			for (int k = 1; k <= N; k++)
				dp[i][k] = INT8_MIN;

		for (int i = 0; i < N; i++) subarray_sum += arr[i];

		func(0, N);

		if (N == 1) subsequence_sum = arr[0];
		else{
			sort(arr, arr + N);

			for (int i = 0; i < N; i++)
				if (arr[i] > 0){
					subsequence_sum += arr[i];
					check = true;
				}

			if (!check) subsequence_sum = arr[N - 1];
		}
		cout << subarray_sum << " " << subsequence_sum << endl;

	}
	return 0;
}
int func(int start, int length) {

	int sum = 0;

	if (length < 1) return INT8_MIN;

	if (start < 0) return INT8_MIN;

	if (dp[start][length] != INT8_MIN) return dp[start][length];

	for (int i = start; i < start + length; i++) sum += arr[i];

	subarray_sum = max(subarray_sum, func(start, length - 1));

	subarray_sum = max(subarray_sum, func(start + 1, length - 1));

	dp[start][length] = subarray_sum;

	return sum;
}

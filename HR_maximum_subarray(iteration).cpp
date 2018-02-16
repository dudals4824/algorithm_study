#include <iostream>
#include <algorithm>
using namespace std;

int subsequence_sum;
int subarray_sum = 0;
bool check = false;
int * arr;
int N;
int func(int start);

int main(void)
{
	int T, test_case;
	

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		subsequence_sum = 0;
		subarray_sum = 0;
		check = false;
		arr = new int[N];


		for (int i = 0; i < N; i++) cin >> arr[i];

		subarray_sum = func(0);

		if (N == 1) subsequence_sum = arr[0];
		else {
			sort(arr, arr + N);

			for (int i = 0; i < N; i++)
				if (arr[i] > 0) {
					subsequence_sum += arr[i];
					check = true;
				}

			if (!check) subsequence_sum = arr[N - 1];
		}
		cout << subarray_sum << " " << subsequence_sum << endl;

	}
	return 0;
}
int func(int start) {
	int sum = 0;
	int answer = 0;
	int min = INT8_MIN;
	bool check = false;

	for (int i = start; i < N; i++) {
		sum += arr[i];
		
		if (sum < 0) sum = 0;
		if (arr[i] < 0) min = max(arr[i], min);

		answer = max(answer, sum);


	}

	if (answer == 0 && min != INT8_MIN)
		answer = min;

	return answer;
}

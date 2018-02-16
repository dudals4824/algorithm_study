#include <iostream>
using namespace std;
int arr[100000];
int main(void) {
	int N, K;
	int max;
	int a, b;

		cin >> N >> K;

		for (a = 0; a < N; a++) {
			cin >> arr[a];
		}

		for (a = 0; a < N; a++) {
			max = N - a;
		
			if (arr[a] == max) continue;

			for (b = a+1; b < N; b++)
				if (arr[b] == max) {
					arr[b] = arr[a];
					arr[a] = max;
					K--;
					break;
				}
			if (K == 0) break;
		}

		for (a = 0; a < N; a++) {
			cout << arr[a] << " ";
		}
		cout << endl;
	
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static int test_case;
static int n, m; // n은 사람 숫자, m은 짝의 숫자

bool areFriends[10][10];

int countParings(bool taken[10]);

int main(void) {

	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {
		cin >> n >> m;
		
		bool taken[10];
		int left, right;
		int Answer = 0;

		for (int k = 0; k < n; k++) taken[k] = false;

		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++)
				areFriends[k][j] = false;
		

		for (int k = 0; k < m; k++) {
			cin >> left >> right;
			areFriends[left][right] = true;
		}
		
		Answer = countParings(taken);

		cout << Answer << endl;

	}// test_case
	//system("pause");
	return 0;
}

int countParings(bool taken[10]) {
	int firstFree = -1;

	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}
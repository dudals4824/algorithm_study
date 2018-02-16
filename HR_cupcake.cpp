#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <functional>
using namespace std;

int N;
int cal[40];
long long miles;
long long temp = 0;

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cal[i];
	}

	//내림 차순 정렬
	sort(cal, cal + N, greater<int>());

	for (int i = 0; i < N; i++) {
		temp = pow(2.0, i) * cal[i];
		miles += temp;
	}

	cout << miles << endl;

	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

static int N, S;
// 숫자 저장할 배열
static int * num;
// 조합을 위한 배열
static int * cArr;
static int Answer = 0;

void combination(int arr[], int index, int n, int r, int target);
void sum(int arr[], int length);
int main(void) {

	cin >> N >> S;

	num = new int[N];
	cArr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		cArr[i] = i;
	}
	

	for (int i = 1; i <= N; i++) combination(cArr, 0, N, i, 0);


	cout << Answer << endl;


	return 0;
}


void combination(int arr[], int index, int n, int r, int target) {
	if (r == 0) sum(arr, index);

	else if (target == n) return;

	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1);
		combination(arr, index, n, r, target + 1);
	}
}
void sum(int arr[], int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) sum += num[arr[i]];
	
	if (sum == S) Answer++;

}
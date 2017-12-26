#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static int test_case;
int n; // 체스판 크기, 말의 개수
int chess[12][12];

int func(bool queen[12]);
void check_func(int left, int right);
void check_func2(int left, int right);
int main(void) {

	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {
		int Answer = 0;
		bool queen[12];

		cin >> n;

		for (int k = 0; k < n; k++) queen[k] = false;

		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++)
				chess[k][j] = 0;


		Answer = func(queen);

		cout << Answer << endl;
	}// test_case
	return 0;
}

int func(bool queen[12]) {
	int ret = 0;
	int first = -1;

	for (int i = 0; i < n; i++) {
		if (!queen[i]) {
			first = i;
			break;
		}
	}

	if (first == -1) return 1;

	
	for (int i = 0; i < n; i++) {
		
		queen[first] = true;

		if (chess[first][i] != 0){
			queen[first] = false;
			continue;
		}
		else
			chess[first][i] += 1;

		// 8방향에 1더하는 게 필요 
		// 중간에 2가 넘는지 체크하게 되면 다시 1을 빼게될 때, 함수가 복잡해질 가능성 커짐
		// 다 1을 추가 시킨뒤에 하는걸로 변경

		check_func(first, i);
		ret += func(queen); 
		check_func2(first, i);

		queen[first] = false;
	}

	return ret;

}

void check_func(int left, int right) {

	for (int k = 1; k < n; k++) {

		// 왼쪽 위
		if (left - k >= 0 && right - k >= 0)
			chess[left - k][right - k] += 1;
		// 위
		if (left - k >= 0)
			chess[left - k][right] += 1;
		// 오른쪽 위
		if (left - k >= 0 && right + k < n)
			chess[left - k][right + k] += 1;

		// 왼쪽
		if (right - k >= 0)
			chess[left][right - k] += 1;

		// 오른쪽
		if (right + k < n)
			chess[left][right + k] += 1;

		//왼쪽 아래
		if (left + k < n && right - k >= 0)
			chess[left + k][right - k] += 1;

		//아래쪽
		if (left + k < n)
			chess[left + k][right] += 1;

		//오른쪽 아래
		if (left + k < n && right + k < n)
			chess[left + k][right + k] += 1;
	}

}

void check_func2(int left, int right) {

	chess[left][right] -= 1;

	for (int k = 1; k < n; k++) {

		// 왼쪽 위
		if (left - k >= 0 && right - k >= 0)
			chess[left - k][right - k] -= 1;
		// 위
		if (left - k >= 0)
			chess[left - k][right] -= 1;
		// 오른쪽 위
		if (left - k >= 0 && right + k < n)
			chess[left - k][right + k] -= 1;

		// 왼쪽
		if (right - k >= 0)
			chess[left][right - k] -= 1;

		// 오른쪽
		if (right + k < n)
			chess[left][right + k] -= 1;

		//왼쪽 아래
		if (left + k < n && right - k >= 0)
			chess[left + k][right - k] -= 1;

		//아래쪽
		if (left + k < n)
			chess[left + k][right] -= 1;

		//오른쪽 아래
		if (left + k < n && right + k < n)
			chess[left + k][right + k] -= 1;
	}

}
#include <iostream>
#include <algorithm>
using namespace std;
int arr[9][9];
bool check(int xIdx, int yIdx, int value) {
	// 행 고정하고 검사
	for (int i = 0; i < 9; i++) {
		if (arr[xIdx][i] == value)
			return false;
	}

	// 열 고정하고 검사
	for (int i = 0; i < 9; i++) {
		if (arr[i][yIdx] == value)
			return false;
	}

	int xs = xIdx / 3 * 3;
	int ys = yIdx / 3 * 3;
	for (int i = xs; i < xs + 3; i++)
		for (int k = ys; k < ys + 3; k++)
			if (arr[i][k] == value) return false;

	return true;
}
void Sudoku() {
	int xIdx = -1, yIdx = -1;
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			if (arr[i][k] == 0) {
				xIdx = i;
				yIdx = k;
				break;
			}
		}
		if (xIdx != -1) break;
	}

	if (xIdx == -1) {
		for (int i = 0; i < 9; i++) {
			for (int k = 0; k < 9; k++) {
				cout << arr[i][k] << " ";
			}
			cout << endl;
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (check(xIdx, yIdx, i)) {
			arr[xIdx][yIdx] = i;
			Sudoku();
			arr[xIdx][yIdx] = 0;
		}
	}
}
int main(void) {

	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			cin >> arr[i][k];
		}
	}
	
	Sudoku();

	return 0;
}

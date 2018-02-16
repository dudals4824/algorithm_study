#include <iostream>
#include <algorithm>
using namespace std;
int zeroNum=0;
struct Sudoku {
	int num;
	bool check[10];

	Sudoku() {
		for (int i = 0; i < 10; i++){
			check[i] = true;
		}
	}

	void candidate(int x, int y, Sudoku arr[9][9]) {
		int xs = x / 3 * 3;
		int ys = y / 3 * 3;
		// 같은 행 검사
		for (int i = 0; i < 9; i++) {
			check[arr[x][i].num] = false;
		}
		// 같은 열 검사
		for (int i = 0; i < 9; i++) {
			check[arr[i][y].num] = false;
		}
		// 정사각형 검사
		for (int i = xs; i < xs + 3; i++) {
			for (int k = ys; k < ys + 3; k++) {
				check[arr[i][k].num] = false;
			}
		}
	}

	void inspect(int x, int y, Sudoku arr[9][9], int cur) {
		arr[x][y].check[cur] = false;

		if (zeroNum == 0) return;

		for (int i = 1; i <= 9; i++) {
			if (arr[x][y].check[i]) {
				cur = i;
				arr[x][y].num = cur;
				zeroNum--;

				int xs = x / 3 * 3;
				int ys = y / 3 * 3;
				// 같은 행 검사
				for (int k = 0; k < 9; k++) {
					if (arr[x][k].num == 0){
						inspect(x, k, arr, cur);
					}
				}


				// 같은 열 검사
				for (int k = 0; k < 9; k++) {
					if (arr[k][y].num == 0) {
						inspect(k, y, arr, cur);
					}
				}


				// 정사각형 검사
				for (int k = xs; k < xs + 3; k++) {
					for (int j = ys; j < ys + 3; j++) {
						if (arr[k][j].num == 0) {
							inspect(k, j, arr, cur);
						}
					}
				}
		
			}
		}
	}
};
int main(void) {

	Sudoku arr[9][9];

	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			cin >> arr[i][k].num;
			if (arr[i][k].num == 0) {
				zeroNum++;
			}
		}
	}
	// 후보 숫자 check
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			if (arr[i][k].num == 0) {
				arr[i][k].candidate(i, k, arr);
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			if (arr[i][k].num == 0) {
				arr[i][k].inspect(i, k, arr, 0);
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			cout << arr[i][k].num << " ";
		}
		cout << endl;
	}
	return 0;
}

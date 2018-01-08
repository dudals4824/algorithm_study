#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static int test_case;
int h, w;
char board[20][20];

int func(int hidx, int widx);
int block(int hidx, int widx, int block_count);
void unblock(int hidx, int widx, int block_num);

int main(void) {

	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {
		int Answer = 0;
		cin >> h >> w;

		//board판 입력
		for (int k = 0; k < h; k++)
			for (int j = 0; j < w; j++)
				cin >> board[k][j];

		Answer = func(0, 0);

		cout << Answer << endl;

	}// test_case
	system("pause");
	return 0;
}

int func(int hidx, int widx) {
	int ret = 0;
	int block_num = -1;

	if (h*w <= 4) return 0;

	//맨 끝 칸
	if (hidx == h - 2 && widx == w - 2) {
		block_num = block(hidx, widx, 0);

		for (int i = 0; i < h; i++)
			for (int k = 0; k < w; k++)
				if (board[i][k] == '.') {
					unblock(hidx, widx, block_num);
					return 0;
				}

		unblock(hidx, widx, block_num); return 1;
	}

	for (int i = 0; i < 4; i++) {

		block_num = block(hidx, widx, i);

		if (block_num == -1) {

			if (widx == w - 2)
				ret += func(hidx + 1, 0);

			else
				ret += func(hidx, widx + 1);
			
		}

		if (widx == w - 2)
			ret += func(hidx + 1, 0);

		else
			ret += func(hidx, widx + 1);


		unblock(hidx, widx, block_num);
		
	}



	return ret;
}

int block(int hidx, int widx, int block_count) {

	for(int i = block_count ; i<4 ; i++){
		if (i == 0){
			if (board[hidx][widx] == '.' && board[hidx + 1][widx] == '.' && board[hidx + 1][widx + 1] == '.') {
				board[hidx][widx] = 'a';
				board[hidx + 1][widx] = 'a';
				board[hidx + 1][widx + 1] = 'a';
				return 0;
			}
		}
		
		else if (i == 1){
			if (board[hidx][widx + 1] == '.' && board[hidx + 1][widx] == '.' && board[hidx + 1][widx + 1] == '.') {
				board[hidx][widx +1] = 'a';
				board[hidx + 1][widx] = 'a';
				board[hidx + 1][widx + 1] = 'a';
				return 1;}
		}

		else if (i == 2){
			if (board[hidx][widx] == '.' && board[hidx][widx + 1] == '.' && board[hidx + 1][widx] == '.') {
				board[hidx][widx] = 'a';
				board[hidx][widx + 1] = 'a';
				board[hidx + 1][widx] = 'a';
				return 2;
			}
		}

		else if (i == 3){
			if (board[hidx][widx] == '.' && board[hidx][widx + 1] == '.' && board[hidx + 1][widx + 1] == '.') {
				board[hidx][widx] = 'a';
				board[hidx][widx+1] = 'a';
				board[hidx + 1][widx + 1] = 'a';
				return 3;
			}
		}
	}
	return -1;
}
void unblock(int hidx, int widx, int block_num) {

	if (block_num == 0) {
		board[hidx][widx] = '.';
		board[hidx + 1][widx] = '.';
		board[hidx + 1][widx + 1] = '.';
	}
	else if (block_num == 1) {
		board[hidx][widx + 1] = '.';
		board[hidx + 1][widx] = '.';
		board[hidx + 1][widx + 1] = '.';
	}
	else if (block_num == 2) {
		board[hidx][widx] = '.';
		board[hidx][widx + 1] = '.';
		board[hidx + 1][widx] = '.';
	}
	else if (block_num == 3) {
		board[hidx][widx] = '.';
		board[hidx][widx + 1] = '.';
		board[hidx + 1][widx + 1] = '.';
	}

}
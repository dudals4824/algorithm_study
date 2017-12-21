#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static int test_case;
static int x_arr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 완전탐색 방향
static int y_arr[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

static char boggle[5][5]; // boggle 배열

static string * word;

bool hasWord(int x, int y,int idx, int num) {

	if (x < 0 || y < 0) return false;
	
	if (x >= 5 || y >= 5) return false;

	if (num == word[idx].length()) return true;

	if (boggle[x][y] != word[idx].at(num)) return false;

	if (word[idx].size() == 1) return true;

	

	for (int direction = 0; direction < 8; direction++) {
		int nextX = x + x_arr[direction];
		int nextY = y + y_arr[direction];
		
		if (hasWord(nextX, nextY, idx, num + 1)){
			return true;
		}
	}
	return false;
}
int main(void) {

	int num;
	bool temp = false;
	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {

		for (int k = 0; k < 5; k++)
			for (int j = 0; j < 5; j++)
				cin >> boggle[k][j];


		cin >> num;
		word = new string[num];

		for (int k = 0; k < num; k++)
			cin >> word[k];

		for (int k = 0; k < num; k++) {
			
			for (int x = 0; x < 5; x++)
				for (int y = 0; y < 5; y++){
					temp = hasWord(x, y, k, 0);
					if (temp == true) {
						cout << word[k] << " YES" << endl;
						x = 5; y = 5;
					}
				}

			if(temp == false) cout << word[k] << " NO"<< endl;
		}

	}// test_case
	system("pause");
	return 0;
}


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static int test_case;
static int x_arr[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // 완전탐색 방향
static int y_arr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
static char boggle[5][5]; // boggle 배열
static bool find;

struct Words {
	string word;
	bool check;
	bool complete;
};

Words * words;

// x : boggle의 x좌표
// y : boggle의 y좌표
// idx : words의 순서
// num : words의 string 안의 idx
void func(int x, int y, int idx, int num);

int main(void) {

	int num;
	cin >> test_case;
	
	for (int i = 1; i <= test_case; i++) {
		
		//boggle 게임판 입력
		for (int k = 0; k < 5; k++)
			for (int j = 0; j < 5; j++)
				cin >> boggle[k][j];
		
		//체크할 string 갯수 입력 및 체크할 string들 입력
		cin >> num;

		words = new Words[num];
		
		for (int k = 0; k < num; k++){
			cin >> words[k].word;
			words[k].check = false;
			words[k].complete = false;
		}

		for (int k = 0; k < num; k++) {
			// words를 돌려야 하자너
			// 찾았는지 안찾았는지 확인할 flag를 하나 두자.
			// 그래야 함수를 계속 돌릴지 말지 확인할 수 있다.
			
			for (int x = 0; x < 5; x++){
				
				for (int y = 0; y < 5; y++) {
					if (words[k].word.at(0) == boggle[x][y]){
						words[k].check = true;
						func(x, y, k, 0);
					}
				}
				
				if (words[k].check == true && words[k].complete == true)
					break;
			
			}
			if (words[k].check == true)
				cout << words[k].word << " " << "YES" << endl;
			else
				cout << words[k].word << " " << "NO" << endl;
		}


	}// test_case
	system("pause");
	return 0;
}

void func(int x, int y, int idx, int num) {


	for (int i = 0; i < 8; i++) {

		if (x + x_arr[i] < 0 || y + y_arr[i] < 0) continue;
		else if (x + x_arr[i] >= 5 || y + y_arr[i] >= 5) continue;
		else{
			
			if (num + 1 == words[idx].word.length())
				words[idx].complete = true;
			

			else if (boggle[x + x_arr[i]][y + y_arr[i]] == words[idx].word.at(num + 1)){
				if (words[idx].complete == false){
					words[idx].check = true;
					func(x + x_arr[i], y + y_arr[i], idx, num + 1);
				}
			}
			
			else 
				if (words[idx].complete == false)
					words[idx].check = false; 

		}
		
	}
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static int test_case;
static int x_arr[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // ����Ž�� ����
static int y_arr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
static char boggle[5][5]; // boggle �迭
static bool find;

struct Words {
	string word;
	bool check;
	bool complete;
};

Words * words;

// x : boggle�� x��ǥ
// y : boggle�� y��ǥ
// idx : words�� ����
// num : words�� string ���� idx
void func(int x, int y, int idx, int num);

int main(void) {

	int num;
	cin >> test_case;
	
	for (int i = 1; i <= test_case; i++) {
		
		//boggle ������ �Է�
		for (int k = 0; k < 5; k++)
			for (int j = 0; j < 5; j++)
				cin >> boggle[k][j];
		
		//üũ�� string ���� �Է� �� üũ�� string�� �Է�
		cin >> num;

		words = new Words[num];
		
		for (int k = 0; k < num; k++){
			cin >> words[k].word;
			words[k].check = false;
			words[k].complete = false;
		}

		for (int k = 0; k < num; k++) {
			// words�� ������ ���ڳ�
			// ã�Ҵ��� ��ã�Ҵ��� Ȯ���� flag�� �ϳ� ����.
			// �׷��� �Լ��� ��� ������ ���� Ȯ���� �� �ִ�.
			
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
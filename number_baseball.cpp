#include<iostream>
#include<string>

using namespace std;

static int arr[10][10][10];
static int N;
static int Answer = 0;

int main(void) {

	int detect;
	int strike;
	int ball;

	int comp_s = 0;
	int comp_b = 0;

	//3차원 배열 선언 및 초기화
	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 9; b++)
			for (int c = 1; c <= 9; c++)
				arr[a][b][c] = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> detect >> strike >> ball;


		for (int a = 1; a <= 9; a++)
			for (int b = 1; b <= 9; b++)
				for (int c = 1; c <= 9; c++)
				{

					if (a == b || b == c || c == a)
						continue;

					//비교할 strike 숫자와 ball 숫자 카운트

					if (detect / 100 == a)
						comp_s++;
					else if ((detect % 100) / 10 == a || (detect % 100) % 10 == a)
						comp_b++;

					if ((detect % 100) / 10 == b)
						comp_s++;
					else if (detect / 100 == b || (detect % 100) % 10 == b)
						comp_b++;

					if ((detect % 100) % 10 == c)
						comp_s++;
					else if (detect / 100 == c || (detect % 100) / 10 == c)
						comp_b++;

					if (comp_s == strike && comp_b == ball)
						arr[a][b][c] ++;
						
					
					comp_s = 0;
					comp_b = 0;
				}
	}

	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 9; b++)
			for (int c = 1; c <= 9; c++) {
				if (arr[a][b][c] == N)
					Answer++;
			}



	cout << Answer << endl;

	return 0;
}
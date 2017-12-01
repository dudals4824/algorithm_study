#include<iostream>
#include<string>

using namespace std;

// 실제 연도 카운트 변수
static int Count = 1;

int main(void) {

	int E, S, M;
	int a=1, b=1, c=1;

	cin >> E >> S >> M;

	while (a != E || b != S || c != M) {
		if (a % 16 != 15) a++;
		else a = 1;

		if (b % 29 != 28) b++;
		else b = 1;

		if (c % 20 != 19) c++;
		else c = 1;
		
		Count++;
	}

	cout << Count << endl;
	
	return 0;
}
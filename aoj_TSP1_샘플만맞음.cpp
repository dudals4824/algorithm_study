#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

static int test_case;

static int N;
static double ** arr;

bool * check;


double func(int start, int next);

int main(void) {

	cin >> test_case;

	for (int i = 1; i <= test_case; i++) {

		double Answer = 10000000000.0;
		cin >> N;

		// N * N 2차원 배열 생성
		arr = new double*[N];
		for (int k = 0; k < N; k++)
			arr[k] = new double[N];

		check = new bool[N];

		for (int k = 0; k < N; k++)
			check[k] = false;
		
		// 
		for (int k = 0; k < N; k++)
			for (int j = 0; j < N; j++)
				cin >> arr[k][j];

		for (int k = 0; k < N; k++)
			for(int j =0 ; j< N ;j ++){
				Answer = min(Answer, func(k, j));
				
				for (int a = 0; a < N; a++)
					check[a] = false;

			}
		
		cout << fixed;
		cout.precision(10);
		cout << Answer << endl;

	}// test_case
	system("pause");
	return 0;
}
//func는 순열을 만드는게 주요 기능.
double func(int start, int next) {
	
	double ret = 0;
	double temp = 0;

	check[start] = true;

	ret += arr[start][next];

	for(int i =0  ; i< N ;i++){
		
		if (start == i) continue;

		if (check[i] == true) continue;

		ret += func(next, i);
	}
		
	return ret;
}


#include<iostream>
#include<string>

using namespace std;

// [왼쪽 다리 번호][오른쪽 다리 번호]
static int arr[31][31];
static int Answer = 0;


int main(void) {

	int test_case;
	int N, M;

	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> N >> M;
		Answer = 0;

		//기저조건 1 :: N과 M이 같으면 경우의 수는 하나
		if (N == M) {
			Answer = 1;
			cout << Answer << endl;
			continue;
		}

		//기저조건 2 :: N이 1이면 오른쪽 Site 수가 모든 경우의 수와 같음.
		if (N == 1) {
			Answer = M;
			cout << Answer << endl;
			continue;
		}


		//왼쪽 1번 Site가 오른쪽 Site에 갈 수 있는 번호를 선택
		// ex) 왼쪽 Site가 3개, 오른쪽 Site가 6개 일때
		//  왼쪽 Site 1번은 오른쪽 Site에서 가장 상단 2개를 제외한 4개(M(6)-N(3)+1)를 왼쪽 1번 Site가 갈 수 있음
		for (int k = 1; k <= (M - N + 1); k++)
			arr[1][k] = 1;


		// [왼쪽 Site 번호][오른쪽 Site 번호] : 왼쪽 특정 Site에서 오른쪽 특정 Site에 갈 때 경우의 수
		// 아래 반복문 EX) [3][5] = [2][2] + [2][3] + [2][4]

		for (int a = 2; a <= N; a++) {
			for (int b = a; b <= (M - N + a); b++) {

				int temp = b;

				while (temp > 0) {
					arr[a][b] += arr[a - 1][temp - 1];
					temp--;
				}


			}
		}

		// 왼쪽 N번째 Site에서 갈 수 있는 모든 경우의 수 합이 답이다.
		for (int a = N; a <= M; a++)
			Answer += arr[N][a];

		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= M; b++) {
				arr[a][b] = 0;
			}
		}

		cout << Answer << endl;

	}

	system("pause");
	return 0;
}
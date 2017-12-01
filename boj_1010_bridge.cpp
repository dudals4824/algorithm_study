#include<iostream>
#include<string>

using namespace std;

// [���� �ٸ� ��ȣ][������ �ٸ� ��ȣ]
static int arr[31][31];
static int Answer = 0;


int main(void) {

	int test_case;
	int N, M;

	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> N >> M;
		Answer = 0;

		//�������� 1 :: N�� M�� ������ ����� ���� �ϳ�
		if (N == M) {
			Answer = 1;
			cout << Answer << endl;
			continue;
		}

		//�������� 2 :: N�� 1�̸� ������ Site ���� ��� ����� ���� ����.
		if (N == 1) {
			Answer = M;
			cout << Answer << endl;
			continue;
		}


		//���� 1�� Site�� ������ Site�� �� �� �ִ� ��ȣ�� ����
		// ex) ���� Site�� 3��, ������ Site�� 6�� �϶�
		//  ���� Site 1���� ������ Site���� ���� ��� 2���� ������ 4��(M(6)-N(3)+1)�� ���� 1�� Site�� �� �� ����
		for (int k = 1; k <= (M - N + 1); k++)
			arr[1][k] = 1;


		// [���� Site ��ȣ][������ Site ��ȣ] : ���� Ư�� Site���� ������ Ư�� Site�� �� �� ����� ��
		// �Ʒ� �ݺ��� EX) [3][5] = [2][2] + [2][3] + [2][4]

		for (int a = 2; a <= N; a++) {
			for (int b = a; b <= (M - N + a); b++) {

				int temp = b;

				while (temp > 0) {
					arr[a][b] += arr[a - 1][temp - 1];
					temp--;
				}


			}
		}

		// ���� N��° Site���� �� �� �ִ� ��� ����� �� ���� ���̴�.
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
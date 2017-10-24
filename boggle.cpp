#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct word {
	string words;
	int curIdx;
	int find;  //find 0Àº NO, 1Àº YES
};

static char boggle[5][5];
int test_case, N;

void func(int xIdx, int yIdx, word* words);
int main(int argc, char** argv)
{
	cin >> test_case;

	for (int i = 0; i < 5; i++)
		for (int k = 0; k < 5; k++)
			cin >> boggle[i][k];

	while (test_case > 0) {

		cin >> N;

		word* words;
		words = new word[N];

		for (int i = 0; i < N; i++) {
			cin >> words[i].words;
			words[i].curIdx = 0;
			words[i].find = 0;
		}

		for (int i = 0; i < 5; i++)
			for (int k = 0; k < 5; k++)
				for (int j = 0; j < N; j++) {
					if (boggle[i][k] == words[j].words.at(words[j].curIdx) && words[j].find == 0) {
						words[j].curIdx = 1;
						words[j].find = 1;
						func(i, k, &words[j]);
					}
					words[j].curIdx = 0;
				}

		for (int i = 0; i < N; i++) {
			if (words[i].find == 1)
				cout << words[i].words << " " << "YES" << endl;
			else
				cout << words[i].words << " " << "NO" << endl;
		}

		test_case--;
	}
	system("pause");
	return 0;
}
void func(int xIdx, int yIdx, word* words) {


	if ((*words).words.length() < (*words).curIdx + 1)
		return;
	
	char curChar = (*words).words.at((*words).curIdx);

	if (boggle[xIdx - 1][yIdx -1] == curChar) {
		(*words).curIdx++;
		func(xIdx - 1, yIdx - 1, words);
	}

	else if (boggle[xIdx -1][yIdx] == curChar) {
		(*words).curIdx++;
		func(xIdx -1, yIdx, words);
	}
	else if (boggle[xIdx -1][yIdx + 1] == curChar) {
		(*words).curIdx++;
		func(xIdx - 1, yIdx + 1, words);
	}

	else if (boggle[xIdx][yIdx-1] == curChar) {
		(*words).curIdx++;
		func(xIdx, yIdx - 1, words);
	}
	
	else if (boggle[xIdx][yIdx +1] == curChar) {
		(*words).curIdx++;
		func(xIdx, yIdx + 1, words);
	}

	else if (boggle[xIdx+1][yIdx - 1] == curChar) {
		(*words).curIdx++;
		func(xIdx+1, yIdx - 1, words);
	}
	else if (boggle[xIdx + 1][yIdx] == curChar) {
		(*words).curIdx++;
		func(xIdx + 1, yIdx, words);
	}
	else if (boggle[xIdx + 1][yIdx + 1] == curChar) {
		(*words).curIdx++;
		func(xIdx + 1, yIdx + 1, words);
	}
	
else if (boggle[xIdx][yIdx] == curChar) {
		(*words).curIdx++;
		func(xIdx, yIdx, words);
	}
	else {
		(*words).curIdx = 0;
		(*words).find = 0;
		return;
	}

}
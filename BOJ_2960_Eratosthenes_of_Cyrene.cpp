#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int N, K;
int Answer;
bool * check;
list<int> l;
int main(void) {
	int min;
	int i = 1;

	cin >> N >> K;
	list<int>::iterator it;

	for (int i = 2; i <= N; i++)
		l.push_back(i);
	
	while(true){
		if (K == 0) break;
		min = l.front();
		for (it = l.begin(); it != l.end(); ++it){
			if (*it%min == 0) {
				//cout << "지금 지우는 숫자 : " << *it << endl;
				K -= 1;
				if (K == 0) { Answer = *it; break;}
				l.erase(it);
				it = l.begin();
			}
		}
	}
	
	cout << Answer << endl;

	return 0;
}

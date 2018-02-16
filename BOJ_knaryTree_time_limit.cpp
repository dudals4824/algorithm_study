#include <iostream>
#include <algorithm>
using namespace std;
long long N;
long long K, Q;
int Answer;
void kTree(long long x, long long y) {
	if (x == y) return;
	if (x > y) {
		x = (x + (x % K)) / K;
		Answer++;
		kTree(x, y);
	}
	else if (x < y) {
		y = (y + (y % K)) / K;
		Answer++;
		kTree(x, y);
	}
}
void kTreeB(long long x, long long y) {
	if (x == y) return;
	if (x > y) {
		x = x / K;
		Answer++;
		kTreeB(x, y);
	}
	else if (x < y) {
		y = y / K;
		Answer++;
		kTreeB(x, y);
	}
}
int main(void) {

	long long x, y;

	cin >> N >> K >> Q;

	if (K != 2) {
		for (int i = 0; i < Q; i++) {
			cin >> x >> y;
			Answer = 0;
			kTree(x, y);
			cout << Answer << endl;
		}
	}
	else if (K == 2) {
		for (int i = 0; i < Q; i++) {
			cin >> x >> y;
			Answer = 0;
			kTreeB(x, y);
			cout << Answer << endl;
		}
	}
	return 0;
}
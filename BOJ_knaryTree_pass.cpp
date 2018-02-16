#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
	long long N, x, y;
	int Q, K;
	scanf("%d %d %d", &N, &K, &Q);
		while (Q--) {
			scanf("%lld %lld", &x, &y);
			if (K < 2) {
				printf("%lld\n", abs(x - y));
				continue;
			}
			int Answer = 0;
			while (x^y) {
				if (y > x) swap(x, y);
				x = (x - 2) / K + 1;
				Answer++;
			}
			printf("%d\n", Answer);
		}
	return 0;
}
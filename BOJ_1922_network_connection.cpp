#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct kruskal {
	int from;
	int to;
	int weight;
};
int N, M;
vector<kruskal> edge;
int parent[100001];
int Answer = 0;
bool flag = false;
int find(int u) {
	if (u == parent[u]) return u;

	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);

	//싸이클이 생기면 종료
	if (u == v) return;

	parent[u] = v;
	flag = true;
}
bool weightComp(kruskal u, kruskal v) {
	return u.weight < v.weight;
}
int main(void) {

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		kruskal e;
		scanf("%d %d %d", &e.from, &e.to, &e.weight);
		edge.push_back(e);
	}
	sort(edge.begin(), edge.end(), weightComp);
	for (int i = 0; i < M; i++) {
		flag = false;
		merge(edge[i].from, edge[i].to);
		if (flag) {
			Answer += edge[i].weight;
		}
	}

	printf("%d\n", Answer);

	return 0;
}
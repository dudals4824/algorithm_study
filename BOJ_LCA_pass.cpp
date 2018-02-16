#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 50001
using namespace std;
vector<int> tree[MAX];
int parentArr[MAX];
int depthArr[MAX];
bool visit[MAX];
void dfs(int node, int depth) {
	if (visit[node]) return;

	depthArr[node] = depth;
	visit[node] = true;

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node].at(i);
		//vector에 from과 to가 각각을 저장하기 때문에
		//본 vector에서 가장 위는 이미 방문한 node일 것이다.
		//visit[next]도 확인해줘야 한다.
		if(!visit[next]){
			parentArr[next] = node;
			dfs(next, depth + 1);
		}
	}
}
void LCA(int va, int vb) {
	if (va == vb) {
		cout << va << endl;
		return;
	}
	if (depthArr[va] > depthArr[vb]) {
		va = parentArr[va];
		LCA(va, vb);
	}
	else if (depthArr[va] < depthArr[vb]) {
		vb = parentArr[vb];
		LCA(va, vb);
	}
	else {
		va = parentArr[va];
		vb = parentArr[vb];
		LCA(va, vb);
	}
}
int main(void) {

	int N, M;
	int from, to;
	
	cin >> N;
	//양방향 그래프를 만든다.
	for (int i = 1; i <= N; i++) visit[i] = false;

	for (int i = 0; i < N-1; i++) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	//depth와 parent를 저장해줄 dfs를 돌린다.
	dfs(1, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		LCA(from, to);
	}
	return 0;
}
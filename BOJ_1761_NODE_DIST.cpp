#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 40001
using namespace std;
vector<pair<int, int>> tree[MAX];
int parentArr[MAX];
int depthArr[MAX];
bool visit[MAX];
int Answer;
void dfs(int node, int depth) {
	if (visit[node]) return;

	depthArr[node] = depth;
	visit[node] = true;

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node].at(i).first;
		//vector에 from과 to가 각각을 저장하기 때문에
		//본 vector에서 가장 위는 이미 방문한 node일 것이다.
		//visit[next]도 확인해줘야 한다.
		if (!visit[next]) {
			parentArr[next] = node;
			dfs(next, depth + 1);
		}
	}
}
void LCA(int va, int vb) {
	if (va == vb) {
		return;
	}
	if (depthArr[va] > depthArr[vb]) {
		for (int i = 0; i < tree[va].size(); i++) {
			if (tree[va].at(i).first == parentArr[va]){
				Answer += tree[va].at(i).second;
				break;
			}
		}
		va = parentArr[va];
		LCA(va, vb);
	}
	else if (depthArr[va] < depthArr[vb]) {
		for (int i = 0; i < tree[vb].size(); i++) {
			if (tree[vb].at(i).first == parentArr[vb]) {
				Answer += tree[vb].at(i).second;
				break;
			}
		}
		vb = parentArr[vb];
		LCA(va, vb);
	}
	else {
		for (int i = 0; i < tree[va].size(); i++) {
			if (tree[va].at(i).first == parentArr[va]) {
				Answer += tree[va].at(i).second;
				break;
			}
		}
		for (int i = 0; i < tree[vb].size(); i++) {
			if (tree[vb].at(i).first == parentArr[vb]) {
				Answer += tree[vb].at(i).second;
				break;
			}
		}
		va = parentArr[va];
		vb = parentArr[vb];
		LCA(va, vb);
	}
}
int main(void) {

	int N, M;
	int from, to, distance;

	cin >> N;
	//양방향 그래프를 만든다.
	for (int i = 1; i <= N; i++) visit[i] = false;

	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to >> distance;
		tree[from].push_back(make_pair(to, distance));
		tree[to].push_back(make_pair(from,distance));

	}
	//depth와 parent를 저장해줄 dfs를 돌린다.
	dfs(1, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		Answer = 0;
		LCA(from, to);
		cout << Answer << endl;
	}
	return 0;
}
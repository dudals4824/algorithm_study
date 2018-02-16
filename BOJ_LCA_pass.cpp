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
		//vector�� from�� to�� ������ �����ϱ� ������
		//�� vector���� ���� ���� �̹� �湮�� node�� ���̴�.
		//visit[next]�� Ȯ������� �Ѵ�.
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
	//����� �׷����� �����.
	for (int i = 1; i <= N; i++) visit[i] = false;

	for (int i = 0; i < N-1; i++) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	//depth�� parent�� �������� dfs�� ������.
	dfs(1, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		LCA(from, to);
	}
	return 0;
}
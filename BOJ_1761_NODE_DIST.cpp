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
		//vector�� from�� to�� ������ �����ϱ� ������
		//�� vector���� ���� ���� �̹� �湮�� node�� ���̴�.
		//visit[next]�� Ȯ������� �Ѵ�.
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
	//����� �׷����� �����.
	for (int i = 1; i <= N; i++) visit[i] = false;

	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to >> distance;
		tree[from].push_back(make_pair(to, distance));
		tree[to].push_back(make_pair(from,distance));

	}
	//depth�� parent�� �������� dfs�� ������.
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
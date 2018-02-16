#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
struct Tree {
	vector<Tree *> child;
	Tree* ancestor;
	vector<int> parentNum;
	int index = 0;
	int dept = 0;
};

void dfs(Tree & node, int dept) {
	node.dept = dept;
	if (node.child.empty()) return;
	for (int i = 0; i < node.child.size(); i++) {
		dfs(*node.child[i], dept + 1);
	}
}
void parentNodeSave(Tree & a) {
	int i = 1;
	Tree * temp;
	while(true){
		int count = (int)pow(2.0, i);
		int dept = a.dept - count;
		if (dept <= 0) return;
		
		temp = a.ancestor; count--;
		while (count > 0) {
			temp = temp->ancestor;
			count--;
		}
		a.parentNum.push_back(temp->index);
		i++;
	}
}
void LCA(int va, int vb, Tree* arr) {
	if (va == vb) {
		cout << va << endl;
		return;
	}

	int deptA = arr[va].dept;
	int deptB = arr[vb].dept;
	
	if (deptA > deptB) {
		for (int i = arr[va].parentNum.size() -1; i >= 0; i--){
			if (arr[arr[va].parentNum[i]].dept >= deptB) {
				LCA(arr[va].parentNum[i], vb, arr);
				break;
			}
		}
	}
	else if(deptA < deptB) {
		for (int i = arr[vb].parentNum.size()-1; i >= 0; i--) {
			if (arr[arr[vb].parentNum[i]].dept >= deptA) {
				LCA(va, arr[vb].parentNum[i], arr);
				break;
			}
		}
	}
	else {
			LCA(arr[va].parentNum[0], arr[vb].parentNum[0], arr);
	}
}
int main(void) {

	int N, M;
	int from, to;
	int v1, v2;

	cin >> N;

	Tree * arr = new Tree[N + 1];

	for (int i = 1; i <= N; i++){
		arr[i].index = i;
	}

	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to;
		if (from < to) {
			arr[from].child.push_back(&arr[to]);
			arr[to].ancestor = &arr[from];
			arr[to].parentNum.push_back(from);
		}
		else {
			arr[to].child.push_back(&arr[from]);
			arr[from].ancestor = &arr[to];
			arr[from].parentNum.push_back(to);
		}
	}

	dfs(arr[1], 1);

	for (int i = 1; i <= N; i++) {
		parentNodeSave(arr[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		LCA(v1, v2, arr);
	}

	return 0;
}

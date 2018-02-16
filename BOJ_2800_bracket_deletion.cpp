#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

static stack<int> s;
static pair<int, int> p[10];
static vector<string> v;
string inp;
string pre_inp;
int * arr;

void combination(int arr[], int index, int n, int r, int target, int rep);
void print(int arr[], int length);
int main(void) {
	cin >> inp;

	int p_idx = 0;
	int count = 0;

	for (int i = 0; i < inp.length(); i++) {
			if (inp.at(i) == '(') s.push(i);

			if (inp.at(i) == ')') {
				p[p_idx] = make_pair(s.top(), i);
				s.pop();
				p_idx++;
			}

	}

	arr = new int[p_idx];

	for (int i = 0; i < p_idx; i++) arr[i] = i;

	for (int i = 1; i <= p_idx; i++) { 
		int rep = 0;
		pre_inp = " ";
		combination(arr, 0, p_idx, i, 0, 0); }

	sort(v.begin(), v.end());
	vector<string>::iterator it;
	pre_inp = " ";
	for (it = v.begin(); it < v.end(); it++) {
		if (pre_inp != *it) {
			cout << *it << endl;
			pre_inp = *it;
		}
	}
		

	return 0;
}

void combination(int arr[], int index, int n, int r, int target, int rep) {
	if (r == 0) { 
		string temp = inp;
		print(arr, index);
		v.push_back(inp);
		inp = temp;
	}

	else if (target == n) return;

	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1, rep + 1);
		combination(arr, index, n, r, target + 1, rep + 1);
	}
}
void print(int arr[], int length) {
	bool check = false;

	for (int i = 0; i < length; i++) {
		inp.replace(p[arr[i]].first, 1, "a");
		inp.replace(p[arr[i]].second, 1, "a");
	}
	
	while (true) {
		check = false;
		for (int i = 0; i < inp.length(); i++)
			if (inp.at(i) == 'a'){
				inp.replace(i, 1, "");
				check = true;
			}
		if (!check) break;
	}
}
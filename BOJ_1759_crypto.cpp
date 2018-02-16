#include<iostream>
#include<algorithm>
using namespace std;
int L, C;
char * ch;
int * com;
void combination(int arr[], int index, int n, int r, int target);
void print(int arr[], int length);
int main(void) {
	
	cin >> L >> C;
	
	ch = new char[C];
	com = new int[C];

	for (int i = 0; i < C; i++) { cin >> ch[i]; com[i] = i; }

	sort(ch, ch + C);

	combination(com, 0, C, L, 0);

	return 0;
}
void combination(int arr[], int index, int n, int r, int target) {
	if (r == 0) print(arr, index);
	else if (target == n) return;
	else {
		arr[index] = target;
		combination(arr, index + 1, n, r - 1, target + 1);
		combination(arr, index, n, r, target + 1);
	}
}
void print(int arr[], int length) {
	int consonant = 0;
	int vowel = 0;

	for (int i = 0; i < length; i++)
		if (ch[arr[i]] == 'a' || ch[arr[i]] == 'e' || ch[arr[i]] == 'i' || ch[arr[i]] == 'o' || ch[arr[i]] == 'u') vowel++;
	
	consonant = length - vowel;

	if (vowel >= 1 && consonant >= 2) {
		for (int i = 0; i < length; i++) 
			cout << ch[arr[i]];
		cout << endl;
	}
}

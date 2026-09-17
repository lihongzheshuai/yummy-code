#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	n %= 26;
	for(int i = 0; i<26; i++) {
		int cur_idx = 'A' + n + i; 
		if (n + i >= 26) {
			cur_idx -= 26; 
		}
		cout << char(cur_idx);
	}
	return 0;
}

#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int mid = (n+1)/2;
	int b = mid;
	int t = mid;
	bool flag = true;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=n; j++) {
			if(j == b|| j == t) {
				cout << "#";
			} else {
				cout << ".";
			}
		}
		cout << endl;
		if(b == 1) {
			flag = false;
		}
		if(flag) {
			b = b - 1;
			t = t + 1;
		}else{
			b = b + 1;
			t = t - 1;
		}
	}
	return 0;
}

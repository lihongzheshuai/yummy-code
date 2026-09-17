#include<bits/stdc++.h>
using namespace std;
string str[105];
bool check(int x, int y) {
	int count = 0;
	count = 0;
	for(int r = x; r<x+4; r++) {
		for(int c = y; c<y+4; c++) {
			if(r==x|r==x+3) {
				if(str[r][c]!='0') {
					count = 1;
				}
			}
			if(c==y||c==y+3) {
				if(str[r][c]!='0') {
					count = 1;
				}
			}
			if((r==x+1||r==x+2)&&(c==y+1||c==y+2)) {
				if(str[r][c]!='1') {
					count = 1;
				}
			}
		}
	}
	if(count==0) {
		return true;
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	for(int i = 0; i<t; i++) {
		int n, m;
		cin >> n >> m;
		for(int j = 0; j<n; j++) {
			cin >> str[j];
		}
		if(n<4||m<4) {
			cout << "No" << endl;
			continue;
		}
		bool flag = false;
		for(int j = 0; j+4 <= n; j++) {
			for(int k = 0; k+4 <= m; k++) {
				if(check(j,k)) {
					flag = true;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(flag){
			cout << "Yes" << "\n";
		}else{
			cout << "No" << "\n";
		}

	}
	return 0;
}

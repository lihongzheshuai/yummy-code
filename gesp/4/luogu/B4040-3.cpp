#include<bits/stdc++.h>
using namespace std;
string str[105];
bool check(int x,int y) {
	int count = 0;
	for(int j = 0; j+4<=x; j++) {
		for(int k = 0; k+4<=y; k++) {
			count = 0;
			for(int r = j; r<j+4; r++) {
				for(int c = k; c<k+4; c++) {
					if(r==j|r==j+3) {
						if(str[r][c]!='0') {
							count = 1;
						}
					}
					if(c==k||c==k+3) {
						if(str[r][c]!='0') {
							count = 1;
						}
					}
					if((r==j+1||r==j+2)&&(c==k+1||c==k+2)) {
						if(str[r][c]!='1') {
							count = 1;
						}
					}
				}
			}
			if(count==0){
				return true;
			}
		}
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
		if(check(n,m)) {
			cout << "Yes" << "\n";
		} else {
			cout << "No" << "\n";
		}
	}
	return 0;
}

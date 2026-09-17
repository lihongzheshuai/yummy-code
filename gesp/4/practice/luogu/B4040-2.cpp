#include<bits/stdc++.h>
using namespace std;
string str[105];
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
		bool flag = true;
		for(int j = 0; j+4<=n; j++) {
			for(int k = 0; k+4<=m; k++) {
				flag = true;
				for(int r = j; r<j+4; r++) {
					for(int c = k; c<k+4; c++) {
						if(r==j|r==j+3) {
							if(str[r][c]!='0') {
								flag = false;
								break;
							}
						}
						if(c==k||c==k+3) {
							if(str[r][c]!='0') {
								flag = false;
								break;
							}
						}
						if((r==j+1||r==j+2)&&(c==k+1||c==k+2)) {
							if(str[r][c]!='1') {
								flag = false;
								break;
							}
						}
					}
				}
				if(flag) {
					cout <<"Yes"<<endl;
					break;
				}
			}
			if(flag) {
				break;
			}
		}
		if(!flag) {
			cout << "No" << endl;
		}
	}
	return 0;
}

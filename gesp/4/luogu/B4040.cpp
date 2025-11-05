#include<bits/stdc++.h>
using namespace std;
string str_ary[105];



int main() {
	int t;
	cin >> t;
	for(int i = 0; i<t; i++) {
		int n, m;
		cin >> n >> m;
		for(int j = 0; j<n; j++) {
			cin >> str_ary[j];
		}
		if (n < 4 || m < 4) {
			cout << "No" << "\n";
			continue;
		}
		// 0 0 0 1 1
		// 1 0 0 1 1
		// 1 1 1 1 1
		// 0 0 0 0 1
		// 0 0 0 0 0

		bool flag = true;
		for(int j = 0; j+4<=n; j++) {
			for(int k = 0; k+4<=m; k++) {
				flag = true;


				for (int r = j ; r < j + 4; r++) {
					for (int c = k; c < k + 4; c++) {
						if (r == j) {
							if (str_ary[r][c] != '0') {
								flag = false;
								break;
							}
						}
						if (r == j + 3) {
							if (str_ary[r][c] != '0') {
								flag = false;
								break;
							}
						}
						if (c == k || c == k + 3) {
							if (str_ary[r][c] != '0') {
								flag = false;
								break;
							}
						}
						if ((r == j + 1 || r == j + 2) && (c == k + 1 || c == k + 2)) {
							if (str_ary[r][c] != '1') {
								flag = false;
								break;
							}
						}
					}
				}
				if (flag) {
					cout << "Yes" << "\n";
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "No" << "\n";
		}
	}
	return 0;
}

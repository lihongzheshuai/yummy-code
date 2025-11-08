#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	int count = 0;
	int time = 0;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	bool flag = false;
	for(int i = 0; i<n; i++) {
		int u = a[i];
		for(int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k) {
					continue;
				}
				if (a[j] + a[k] == a[i]) {
					count++;
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		flag = false;
	}
	cout << count;
	return 0;
}

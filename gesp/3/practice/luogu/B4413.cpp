#include<bits/stdc++.h>
using namespace std;
int a[105];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int count = 0;
	for(int i = 0;; i++) {
		bool flag = true;
		for(int j = 0; j < n; j++) {
			if(a[j]!=0) {
				flag = false;
			}
		}
		if(flag) {
			break;
		}
		int m = 0;
		int mi = 1000000;
		int m_wei;
		for(int j = 0; j<n; j++) {
			if(a[j]>=m) {
				m = a[j];
				m_wei = j;
			}
			if(a[j] <= mi&&a[j] > 0) {
				mi = a[j];
			}
		}
		a[m_wei] = m - mi;
		count++;
	}
	cout << count;
	return 0;
}

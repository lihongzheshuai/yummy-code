#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int b[N];
int main() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	int idx = 0;
	int count = 0; 
	for(int i = 1; i<=n; i++) {
		for(int j = idx; j<=n; j++) {
			if (a[j] >= i) {
				idx = j + 1;
				count++;
				break;
			}
		}
	}
	cout << count;
	return 0;
}

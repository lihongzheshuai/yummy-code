#include<iostream>
using namespace std;
int a[3005];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int min = 30000000;
	for(int i = 0; i<=n-m; i++) {
		int b = 0;
		for(int j = i; j<i+m; j++) {
			b += a[j];
		}
		if(b < min) {
			min = b;
		}
	}
		cout << min;
	return 0;
}

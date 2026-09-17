#include<bits/stdc++.h>
using namespace std;
int a[3005];
bool find(int x) {
	for(int j = 1; j<3005; j++) {
		if(x==a[j-1]) {
			return true;
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	int count = 2;
	a[1] = 1;
	for(int i = 2; i<=n; i++) {
		if(a[i-1]-i>0&&!find(a[i-1]-i)) {
			a[i] = a[i-1] - i;
		} else {
			a[i] = a[i-1] + i;
		}
	}
	sort(a+1,a+n+1);
	for(int i = 1; i<=n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

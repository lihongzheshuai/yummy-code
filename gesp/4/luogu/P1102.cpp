#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
long long c1[1000005];
int main() {
	long long n, c;
	cin >> n >> c;
	for(long long i = 0; i<n; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	for(long long i = 0; i<n; i++) {
		b[a[i]]++;
	}
	long long ans = 0;
	for(long long i = 0; i<n; i++) {
		c1[i] = a[i] + c;
	}
	for(int i = 0;i<n;i++){
		ans+=b[c1[i]];
	}
	cout << ans;
	return 0;
}

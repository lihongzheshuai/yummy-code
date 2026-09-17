#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	for(int i = 0;i<n;i++){
		cin >> b[i];
	}
	sort(b,b+n);
	sort(a,a+n);
	int count = 0;
	int u = 0;
	for(int i = 0; i<n; i++) {
		for(int j = u; j<n;j++) {
			if(a[j]>b[i]) {
				count++;
				u = j+1;
				break;
			}
		}
	}
	cout << count;
	return 0;
}

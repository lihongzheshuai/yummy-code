#include<bits/stdc++.h>
using namespace std;
int a[3005];
int b[3005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	int count = 0;
	for(int i = 0; i<n-1; i++) {
		for(int j = 0; j<n-1; j++) {
			if(a[j]<a[j+1]) {
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
				count++;
			}
			if(a[j]==a[j+1]) {
				if(b[j]<b[j+1]) {
					swap(a[j],a[j+1]);
					swap(b[j],b[j+1]);
					count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}

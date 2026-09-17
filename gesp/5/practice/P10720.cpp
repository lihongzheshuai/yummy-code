#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int b[10000005];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int max = 0;
	for(int i = 0; i<n; i++) {
		if(a[i]>max) {
			max = a[i];
		}
	}
	if(max == 1) {
		for(int i = 0; i<n; i++) {
			cout << 0 << "\n";
		}
		return 0;
	}
	for(int i = 2; i<max; i++) {
		if(max%i==0) {
			if(i==2) {
				b[i] = 1;
			} else {
				bool flag = true;
				for(int j = 2; j<i; j++) {
					if(i%j==0){
						flag = false;
					}
				}
			}
		}
	}
	for(int i = 0; i<n; i++) {
		for(int j = 2; j<max; j++) {
			bool flag = true;

		}
	}
	return 0;
}

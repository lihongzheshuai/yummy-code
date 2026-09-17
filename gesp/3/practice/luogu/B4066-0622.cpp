#include<iostream>
using namespace std;
int main() {
	int n;
	cin >>  n;
	int k;
	cin >> k;
	int a[n];
	int m = 0;
	int mi = 10000000;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		if(a[i] > m) {
			m = a[i];
		}
		if(a[i] < mi) {
			mi = a[i];
		}
	}
	for(int i = 0; i<n; i++) {
		if(a[i] < k) {
			a[i] = mi;
			cout << a[i] << " ";
		} else if(a[i] > k){
			a[i] = m;
			cout << a[i] << " ";
		}else{
			cout << a[i] << " ";
		}
	}
	return 0;
}

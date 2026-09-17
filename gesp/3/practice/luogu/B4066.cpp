#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	int max_1 = -100000000;
	int min_1 = 1000000;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		max_1 = max(a[i],max_1);
		min_1 = min(a[i],min_1);
	}
	for(int i = 0; i<n; i++) {
		if(a[i] > k) {
			a[i] = max_1;
		} else if(a[i] < k) {
			a[i] = min_1;
		}
		cout << a[i] << " ";
	}
	return 0;
}

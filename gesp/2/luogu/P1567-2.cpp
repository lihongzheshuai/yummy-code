#include<iostream>
#include<cmath>
using namespace std;
int a[1000001];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int in_max=1;
	if(n==1) {
		cout << in_max;
		return 0;
	}
	int cur_max = a[0];
	int max_max = 1;
	for(int i = 1; i<=n; i++) {
		if(a[i] > cur_max) {
			max_max++;
		} else {
			in_max = max(in_max, max_max);
			max_max = 1;
		}
		cur_max=a[i];
	}
	in_max = max(in_max, max_max);
	cout << in_max;
	return 0;
}

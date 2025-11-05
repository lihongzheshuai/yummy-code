#include<iostream>
using namespace std;
int a[25][25];
int main() {
	int n;
	cin >> n;
	cout << n; 
	int m=0, n1=(n-1)/2;
	a[m][n1] = 1;
	int l_m = m;
	int l_n = n1;
	for(int i = 2; i<=n*n; i++) {
		cout << "......" << " " << l_m << " " << l_n;
		if(l_m==0) {
			m = n - 1;
		} else {
			m--;
		}
		if(l_n==n-1) {
			n1 = 0;
		} else {
			n1++;
		}
		if(a[m][n1] == 0) {
			a[m][n1] = i;
			l_m = m;
			l_n = n1; 
		} else {
			if(l_m==n-1) {
				m = 0;
				a[m][l_n] = i;
				l_m = m;
			} else {
				l_m++;
				a[l_m][l_n] = i;
			}
		}
		cout << i << " ";
	}
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cout << a[i][j]<< " ";
		}
		cout << "\n";
	}
	return 0;
}

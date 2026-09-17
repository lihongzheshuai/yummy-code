#include<bits/stdc++.h>
using namespace std;
int a[200][200];
int main() {
	int n;
	cin >> n;
	int k = 2;
	int h = 0;
	int l = (n-1)/2;
	a[h][l]  = 1;
	for(int i = 2; i<=n*n; i++) {
		int h1 = h, l1 = l;
		if(h==0&&l!=n-1) {
			h = n-1;
			l = l1+1;
			a[h][l] = k;
			k++;
		} else if(h!=0&&l==n-1) {
			l = 0;
			h = h1 - 1;
			a[h][l] = k;
			k++;
		} else if(h == 0&&l == n-1) {
			h = h1 + 1;
			a[h][l] = k;
			k++;
		}else if(h!=0&&l!=n-1){
			if(a[h-1][l+1]==0){
				h = h1 - 1;
				l = l1 + 1;
				a[h][l] = k;
				k++;
			}else{
				h = h1 + 1;
				a[h][l] = k;
				k++;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j<n;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

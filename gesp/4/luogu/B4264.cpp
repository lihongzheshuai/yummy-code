#include<iostream>
using namespace std;
int a[505][505];
int main(){
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0;i+2<=n;i++){
		for(int j = 0;j+2<=m;j++){
			if(a[i][j]*a[i+1][j+1]==a[i][j+1]*a[i+1][j]){
				ans++;
			} 
		}
	}
	cout << ans;
	return 0;
} 

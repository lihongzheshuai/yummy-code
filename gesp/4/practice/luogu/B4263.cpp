#include<bits/stdc++.h>
using namespace std;
string a[1005];
bool cu(int x, int y,int n,int m) {
	if(x==0) {
		return true;
	} else {
		if(a[x-1][y]=='.') {
			return true;
		}
		return false;
	}
}
bool cd(int x, int y,int n,int m) {
	if(x==n-1) {
		return true;
	} else {
		if(a[x+1][y]=='.') {
			return true;
		}
		return false;
	}
}
bool cl(int x, int y,int n,int m) {
	if(y==0) {
		return true;
	} else {
		if(a[x][y-1]=='.') {
			return true;
		}
		return false;
	}
}
bool cr(int x, int y,int n,int m) {
	if(y==m-1) {
		return true;
	} else {
		if(a[x][y+1]=='.') {
			return true;
		}
		return false;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int count = 0;
	int v=0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j < m; j++) {
			int ans = 0;
			if(a[i][j]=='.') {
				if(cu(i,j,n,m)&&cd(i,j,n,m)&&cl(i,j,n,m)&&cr(i,j,n,m)) {
					count++;
				}
			} else {                                                                                      
				if(i!=0&&a[i-1][j]=='.'){
					if(cu(i-1,j,n,m)&&cl(i-1,j,n,m)&&cr(i-1,j,n,m)){
						ans++;
					}
				}
				if(i!=n-1&&a[i+1][j]=='.'){
					if(cd(i+1,j,n,m)&&cl(i+1,j,n,m)&&cr(i+1,j,n,m)){
						ans++;
					}
				}
				if(j!=0&&a[i][j-1]=='.'){
					if(cu(i,j-1,n,m)&&cd(i,j-1,n,m)&&cl(i,j-1,n,m)){
						ans++;
					}
				}
				if(j!=m-1&&a[i][j+1]=='.'){
					if(cu(i,j+1,n,m)&&cd(i,j+1,n,m)&&cr(i,j+1,n,m)){
						ans++;
					}
				}
				if(cu(i,j,n,m)&&cd(i,j,n,m)&&cl(i,j,n,m)&&cr(i,j,n,m)) {
					ans++;
				}
			}
			v = max(v,ans);
		}
	}
	cout << v+count;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005];
int zui(int x,int y){
	int count = 0;
	int m = min(x,y);
	for(int i = 1;i<=m;i++){
		if(x%i==0&&y%i==0){
			count = i;
		}
	}
	return count;
}
int main(){
	int n,q;
	cin >> n >> q;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=q;i++){
		int ans = a[0]+i;
		for(int j = 1;j<n;j++){
			ans = zui(ans,a[j]+i);
		}
		cout << ans << "\n";
	}
	return 0;
}

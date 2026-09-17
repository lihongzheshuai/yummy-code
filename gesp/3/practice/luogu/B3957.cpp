#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	} 
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			int u = a[i]+a[j];
			for(int k = 0;k<=sqrt(u);k++){
				if(k*k==u){
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

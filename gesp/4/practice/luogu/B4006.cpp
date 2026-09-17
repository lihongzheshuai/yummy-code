#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int max=a[0],m=0;
	for(int i = 0;i<n;i++){
		int count = 0;
		for(int j = i;j<n;j++){
			if(a[j] - a[i]<=k){
				count+=a[j];
			}
		}
		if(count>m){
			m = count;
		}
	}
	cout << m;
	return 0;
} 

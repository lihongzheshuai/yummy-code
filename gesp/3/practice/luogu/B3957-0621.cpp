#include<iostream>
#include<cmath>
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
			int b = a[i] + a[j];
			int u = sqrt(b);
			if(u * u == b){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
} 

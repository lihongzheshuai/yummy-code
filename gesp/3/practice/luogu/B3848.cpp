#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	int m;
	cin >> m;
	for(int i = 0;i<n;i++){
		if(m >= a[i]){
			ans++;
			m -= a[i];
			continue;
		}
	}
	cout << ans;
	return 0;
}

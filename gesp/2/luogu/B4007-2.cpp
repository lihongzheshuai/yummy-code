#include<iostream>
using namespace std;
int main(){
	int n;
	cin >>n ;
	int k;
	cin >> k;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		int t = i;
		while(t!=0){
			if(t%10==k){
				ans++;
			}
			t/=10;
		}
	} 
	cout << ans ;
	return 0;
}

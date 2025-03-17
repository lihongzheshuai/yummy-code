#include<iostream>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		int u = i;
		while(u!=0){
			if(u%10==x){
				ans++;
			}
			u/=10;
		}
	} 
	cout << ans;
	return 0;
}

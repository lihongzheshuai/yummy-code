#include<iostream>
using namespace std;
int main(){
	int m, n;
	cin >> m >> n;
	int ans=0;
	for(int i = m;i <= n;i++){
		if(i % 2 != 0){
			ans += i;
		}
	}
	cout << ans;
	return 0;
} 

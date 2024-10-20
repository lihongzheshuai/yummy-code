#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 1;i <= n;i++){
		if(i > 1)
		ans += (1 + i) * i / 2;     
	}
	cout << ans;
	return 0;
} 

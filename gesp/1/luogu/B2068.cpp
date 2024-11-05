#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	int ans = 0;
	for(int i = 1;i <= n; i++){
		cin >> a;
		int b, c, d, e;
	b = a / 10 / 10 / 10;
	c = a / 10 / 10 % 10;
	d = a / 10 % 10;
	e = a % 10;
	if(e - d - c - b > 0){
		ans += 1;
	}
	}
	cout << ans;
	return 0;
} 

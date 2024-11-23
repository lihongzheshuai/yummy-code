#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	char b;
	cin >> b;
	int ans = 8;
	if(a > 1000){
		a -= 1000;
		ans += (a / 500) * 4;
		if(a % 500 != 0){
			ans += 4;
		}
	}
	if(b == 'y'){
		ans += 5;
	}
	if(b == 'n'){
		ans += 0;
	}
	cout << ans;
	return 0;
} 

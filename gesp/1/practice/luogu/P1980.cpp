#include<iostream>
using namespace std;
int main(){
	int n, x;
	cin >> n >> x;
	int a, b;
	int ans = 0;
	a = n % 10;
	b = n / 10;
	for(int i = 1;i < n;i++){
		if(a == x || b == x){
			ans += 1;
		}
	}
	cout << ans;
	return 0; 
} 

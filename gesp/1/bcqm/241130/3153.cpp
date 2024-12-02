#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int d;
	int ans = 0;
	for(int i = 1;i <= a;i++){
		cin >> d;
		ans += d;
	}
	cout << ans;
	return 0;
} 

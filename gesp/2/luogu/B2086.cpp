#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	for(int i = 0;i < 1000;i++){
		if((c - a * i) >= 0 && (c - a * i) % b == 0){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 

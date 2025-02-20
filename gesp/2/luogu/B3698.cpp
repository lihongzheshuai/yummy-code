#include<iostream>
using namespace std;
int main(){
	int n, k, b;
	cin >> n >> k >> b;
	int x, y;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		cin >> x >> y;
		if(y == k * x + b){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 

#include<iostream>
using namespace std;
int main(){
	int ans = 0;
	int a, b, c, d, e, f, g, h, i, j;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
	int n;
	cin >> n;
	n += 30;
	if(n >= a){
		ans++;
	}
	if(n >= b){
		ans++;
	}
	if(n >= c){
		ans++;
	}
	if(n >= d){
		ans++;
	}
	if(n >= e){
		ans++;
	}
	if(n >= f){
		ans++;
	}
	if(n >= g){
		ans++;
	}
	if(n >= h){
		ans++;
	}
	if(n >= i){
		ans++;
	}
	if(n >= j){
		ans++;
	}
	cout << ans;
	return 0;
} 

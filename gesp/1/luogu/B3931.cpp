#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	if(a > b + c || b > a + c || c > a + b){
		ans += 1;
	}
	cout << ans;
	return 0;
}

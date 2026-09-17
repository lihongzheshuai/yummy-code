#include<iostream>
using namespace std;
int main(){
	double a, b = 2, c = 0;
	cin >> a;
	int ans = 0;
	while(c < a){
		c += b;
		b *= 0.98;
		ans++;
	}
	cout << ans;
	return 0;
} 

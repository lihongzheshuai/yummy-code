#include<iostream>
using namespace std;
int main(){
	int a, b, n;
	cin >> a >> b >> n;
	double ans = (double)a / (double)b; 
	int c = 0;
	for(int i = 1;i <= n;i++){
		ans *= 10;
		int d = (int)ans;
		ans -= d;
	}
	c = (int)ans;
	c %= 10;
	cout << c;
	return 0;
}

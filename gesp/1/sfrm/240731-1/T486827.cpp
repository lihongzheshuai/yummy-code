#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a, b, c, d;
	a = n % 10;
	b = n / 10 % 10;
	c = n / 10 / 10 % 10;
	d = n / 10 / 10 / 10;
	cout << a + b + c + d;
	return 0;
}

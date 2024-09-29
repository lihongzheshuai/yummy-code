#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b, c, d;
	b = a / 100;
	c = a % 100 / 10;
	d = a % 100 % 10;
	int e;
	e = d * 100 + c * 10 + b;
	cout << e;
	return 0;
}

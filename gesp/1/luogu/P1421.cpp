#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	double c = 0;
	b += a * 10;
	b /= 19;
	c = b;
	cout << (int)c;
	return 0;
}

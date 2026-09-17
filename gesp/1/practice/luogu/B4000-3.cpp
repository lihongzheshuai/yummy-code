#include<iostream>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int i = a * 3600 + b * 60 + c;
	int y = i + d;
	cout << y / 3600 << " " << (y % 3600) / 60 << " " << (y % 3600) % 60;
	return 0;
}

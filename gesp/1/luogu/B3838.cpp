#include<iostream>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(b >= 60){
		a += 1;
		b - 60;
	}
	if(d >= 60){
		c += 1;
		d - 60;
	}
	if(d < b){
		c -= 1;
		d += 60;
	}
	cout << (c - a)*60 << d - b;
	return 0;
}

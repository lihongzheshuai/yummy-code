#include<iostream>
using namespace std;
int main(){
	double a,b;
	cin >> a >> b;
	int ans;
	ans = a / b;
	double r;
	r = a - ans * b;
	cout << r;
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int x, y;
	cin >> x >> y;
	double ans = (double)x / (double)y;
	cout << floor(ans);
	return 0;
} 

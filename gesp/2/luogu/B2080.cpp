#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	double x;
	int n;
	cin >> x >> n;
	double ans = 1;
	ans += x * (1 - pow(x,n)) / (1 - x);
	printf("%.2f", ans);
	return 0;
}

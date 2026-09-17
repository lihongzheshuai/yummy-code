#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int  n;
	double x;
	cin >> x >> n;
	double ans = 1;
	double d = 1;
	for(int i = 1;i <= n;i++){
		ans += pow(x,d);
		d++;
	}
	printf("%.2f", ans);
	return 0;
}

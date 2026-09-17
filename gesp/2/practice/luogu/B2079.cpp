#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a;
	cin >> a;
	double ans = 1;
	double r = 1;
	double y = 0;
	for(int i = 1;i <= a;i++){
		int r = 1;
		double y = 0; 
		for(int j = 1;j<=i;j++){
			r *= j;
		}
		y = 1.0 / r;
		ans += y;
	}
	printf("%.10f", ans);
	return 0;
}

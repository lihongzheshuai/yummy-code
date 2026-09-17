#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int x, n;
	cin >> x >> n;
	double c=0;
		c  += x * pow(1.001,n);
	printf("%.4f", c);
	return 0;
}

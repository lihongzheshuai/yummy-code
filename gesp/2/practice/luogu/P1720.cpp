#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	double u=pow(((1+sqrt(5))/2),n);
	double y = pow(((1-sqrt(5))/2),n);
	double fn = (u-y)/sqrt(5);
	printf("%.2f",fn);
	return 0; 
}

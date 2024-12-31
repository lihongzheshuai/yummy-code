#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double ab = sqrt((c-a)*(c-a)+(d-b)*(d-b));
	double bc = sqrt((e-c)*(e-c)+(f-d)*(f-d));
	double ca = sqrt((e-a)*(e-a)+(f-b)*(f-b));
	double s = (ab + bc + ca) / 2; 
	double s1 = sqrt(s * (s-ab) * (s-bc)* (s-ca));
	printf("%.0f", s1);
	return 0;	
} 

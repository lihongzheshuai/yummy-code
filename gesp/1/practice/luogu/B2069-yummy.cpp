#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int p1=1;
	int q1=2;
	int ans = 0;
	double sum = (double)q1 / (double)p1;
	for(int i = 2;i<=n;i++){
		ans = p1;
		p1 = q1;
		q1 = q1 + ans;
		sum += (double)q1 / (double)p1;
	}
	printf("%.4f", sum);
	return 0;
} 

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long ans = 1;
	double sum = 1;
	int d = 1;
	for(int i = 1;i <= n;i++){
		ans *= d;
		d++;
		sum += 1.0 / ans;
	}
	printf("%.10f", sum);
	return 0;
}

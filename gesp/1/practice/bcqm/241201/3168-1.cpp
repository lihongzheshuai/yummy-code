#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	double sum = 1.0;
	for(int i = 1;i <= n;i++){
		long long fm = 1;
		for (int j = 1; j <= i ; j++) {
			fm = fm * j;
		}
		sum += 1.0 / fm;
	}
	printf("%.10f", sum);
	return 0;
}

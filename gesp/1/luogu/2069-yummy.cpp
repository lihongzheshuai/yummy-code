#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int p1=1;
	int q1=2;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		ans = q1 + p1;
		p1 = q1;
		q1 = ans;
	}
	printf("%.4f", ans);
	return 0;
} 

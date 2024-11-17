#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long ans=0;
	for(int i = 1;i <= n;i++){
		ans += i;
		printf("%lld\n", ans);
	}
	return 0;
}

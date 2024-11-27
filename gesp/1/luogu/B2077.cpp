#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	long long n;
	scanf("%d", &n);
	long long ans = 0;//long long， 因为用int可能承受不了。 当n为最大限制时再乘3可能会于int承载范围。 
	long long sum = 0;
	while(n != 1){
		if(n % 2 != 0){
			ans = n * 3 + 1;
			cout << n << "*3+1=" << ans << "\n";
			n = ans;
		}else{
			sum = n >> 1;
			cout << n << "/2=" << sum << "\n";
			n = sum;
		}
	}
	printf("End");
	return 0;
}

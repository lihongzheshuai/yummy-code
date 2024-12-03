#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b;
	double ans = 0;
	for(int i = 1;i<= a;i++){
		cin >> b;
		if(b <= 70){
			ans += 0.1;
		}
		if(b > 70){
			if(b % 70 == 0){
				ans += b / 70 * 0.1;
			} 
			if(b % 70 != 0){
				ans += (b / 70 + 1) * 0.1;
			}
		}
	}
	printf("%.1f", ans);
	return 0;
}

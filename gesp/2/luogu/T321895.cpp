#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b;
	int ans = 0;
	for(int i = 1;i<= a;i++){
		cin >> b;
		ans += b;
	}
	cout << ans << " ";
	printf("%.5f", (double)ans / (double)a);
	return 0;
} 

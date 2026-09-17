#include<iostream>
using namespace std;
int main(){
	int a, b, m, n;
	cin >> a >> b >> m >> n;
	int j=0;
	long long ans = a+b;
	if(a>=m){
		cout << a;
	}
	if(b>=m){
		cout << b;
	}
	for(int i = 1;i<=n-2;i++){
		j=a+b;
		ans+=j;
		if(j>=m){
			break;
		}
		a = b;
		b= j;
	} 
	cout << ans;
	return 0;
}

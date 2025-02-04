#include<iostream>
using namespace std;
int main(){
	int a, b, m, n;
	cin >> a >> b >> m >> n;
	long long  sum =a+b;
	int day = 0;
	if(a>=m){
		cout << a;
		return 0;
	}
	if(b>=m){
		cout << a+b;
		return 0;
	}
	for(int i = 1;i<=n-2;i++){
		day = a + b;
		sum += day;
		if(day>=m){
			break;
		}
		a = b;
		b = day;
		 
	}
	cout << sum;
	return 0;
}

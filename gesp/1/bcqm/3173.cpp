#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b;
	int ans = 0;
	int sum = 0;
	for(int i = 1;i <= a;i++){
		ans += i;
	}
	for(int i = 2;i<= a;i++){
		cin >> b;
		sum += b;
	}
	cout << ans - sum;
	return 0;
}

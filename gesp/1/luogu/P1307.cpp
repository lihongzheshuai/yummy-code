#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	while(a != 0){
		int ans = a % 10;
		cout << ans;
		a /= 10;
	}
	return 0;
}

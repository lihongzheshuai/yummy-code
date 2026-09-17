#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b;
	int ans = 0;
	for(int i = 1;i < a;i++){
		cin >> b;
		ans += b;
	}
	cout << (a - 2) * 180 - ans;
	return 0;
}

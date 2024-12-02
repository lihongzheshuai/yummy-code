#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int ans = 0;
	for(int i = 1;i <= a;i++){
		ans += i;
	}
	cout << ans;
	return 0;
}

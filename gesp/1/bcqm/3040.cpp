#include<iostream>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int c, ans = 0;
	if(c < n && k % c == 0){
		ans += 1;
	}
	cout << ans;
	return 0;
}

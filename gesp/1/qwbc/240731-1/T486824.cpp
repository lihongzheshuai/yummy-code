#include<iostream>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int ans = 0;
	ans = n / m;
	ans += 1;
	cout << ans;
	return 0; 
}

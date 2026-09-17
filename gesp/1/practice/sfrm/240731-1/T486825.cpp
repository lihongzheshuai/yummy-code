#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans;
	ans = n - n / 6;
	cout << ( n - ans ) * 3;
	return 0;
}

#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a;
	a = 3 * (n - n / 6);
	int b;
	b = 3 * n;
	cout << b - a;
	return 0;
}

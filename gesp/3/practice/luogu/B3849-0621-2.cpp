#include<iostream>
using namespace std;
int main() {
	int n, r;
	cin >> n >> r;
	int a[105];
	int count = 0;
	while(n!=0) {
		int yu = n % r;
		a[count] = yu;
		n/=r;
		count++;
	}
	for(int i = count-1; i>=0; i--) {
		if(a[i]>=10) {
			a[i] = a[i] + 'A' - 10;
			cout << (char)a[i];
		} else {
			cout << a[i];
		}
	}
	return 0;
}

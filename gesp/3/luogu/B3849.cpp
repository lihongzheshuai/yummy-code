#include<iostream>
#include<string>
using namespace std;
int main() {
	int n,r;
	cin >> n >> r;
	string a;
	while(true) {
		int ch = n / r;
		int yu = n % r;
		if (yu < 10) {
			a = (char) ('0' + yu) + a;
		} else {
			a = (char) (yu - 10 + 'A') + a;
		}
		if(ch == 0) {
			break;
		} else {
			n = ch;
		}
	}
	cout << a;
	return 0;
}

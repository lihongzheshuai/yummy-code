#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	char a = 'A';
	a += n % 26;
	for(int i = 0; i<26; i++) {
		if(a>='A'&&a<='Z') {
			cout << a;
		} else {
			a = 'A';
			cout << a;
		}
		a++;
	}
	return 0;
}

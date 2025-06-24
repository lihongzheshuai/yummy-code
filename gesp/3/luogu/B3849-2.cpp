#include<iostream>
#include<string>
using namespace std;
int main() {
	int n, r;
	cin >> n >> r;
	char a[105];
	int count = 0;
	while(n!=0) {
		int yu = n%r;
		n /= r;
		if(yu >= 10) {
			a[count] = (char)(yu + 'A' - 10);
		} else {
			a[count] = (char)(yu + '0');
		}
		count++;
	}
	for(int i = count - 1; i>=0; i--) {
		cout << a[i];
	}
	return 0;
}

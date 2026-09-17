#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int out = 1;
	if(n == 0) {
		cout << 1;
	} else {
		for( int i = 0; i < n; i++){
		out = out * 2;
		}
		cout << out;
	}
	return 0;
}
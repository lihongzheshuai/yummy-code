#include<iostream>
using namespace std;
bool su(int x) {
	bool flag = true;
	for(int i = x-1; i>=2; i--) {
		if(x % i == 0)
			flag = false;
	}
	if(flag) {
		int c = x % 10;
		int d = x / 10;
		int e = c*10+d;
		for(int j = e-1;j>=2;j--){
			if(e%j==0){
				flag = false;
			}
		}
	}
		return flag;
}
int main() {
	int a1, b1;
	cin >> a1 >> b1;
	for(int i = a1;i <= b1;i++){
		if(su(i)){
			cout << i << endl;
		}
	}
	return 0;
}

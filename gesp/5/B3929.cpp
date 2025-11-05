#include<bits/stdc++.h>
using namespace std;
int x[100000005];
bool pan(int y) {
	for(int i = 2; i<y; i++) {
		if(i == sqrt(i)*sqrt(i)&&y%i==0) {
			return true;
		}
	}
	return false;
}
int flag(int a,int b) {
	if(a == sqrt(a)*sqrt(a)&&a>=b) {
		return a;
	}
	if(pan(a)&&a>=b){
		return a;
	}
	return flag(a+1,b);
}
int main() {
	int a, n;
	cin >> a >> n;
	for(int i = 0; i<n; i++) {
		cin >> x[i];
	}
	for(int i = 0; i<n; i++) {
		if(x[i] == sqrt(x[i])*sqrt(x[i])&&x[i]>=a) {
			cout << "lucky" << "\n";
			continue;
		} else if(pan(x[i])&&x[i]>=a){
			cout << "lucky" << "\n";
			continue;
		}else {
			if(x[i]==1) {
				x[i] = 2;
			}
			cout << flag(x[i],a) << "\n";
			continue;
		}
	}
	return 0;
}

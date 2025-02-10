#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >>n;
	int a1;
	for(int i = 1; i<=n; i++) {
		cin >> a1;
		bool flag = false;
		for(int k = 1; k*k<a1; k++) {
			double r = sqrt(a1 - k * k);
			int d = (int)r;
			if(d * d + k * k==a1 && d!=0) {
				flag = true;
				break;
			}
		}
		if(flag) {
			cout << "Yes"<<endl;
		} else {
			cout << "No"<<endl;
		}
	}
	return 0;
}

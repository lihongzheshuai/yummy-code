#include<iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for(int i = 0; i<t; i++) {
		int n;
		cin >> n;
		int ans = 0;
		int b[n];
		for(int j = 0; j<n; j++) {
			cin >> b[j];
			if(b[j] > ans) {
				ans = b[j];
			}
		}
		bool flag = true;
		for(int k = 0; k<n; k++) {
			if(ans % b[k] != 0) {
				flag = false;
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

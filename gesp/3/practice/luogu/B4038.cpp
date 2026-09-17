#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		int ans = 0;
		int sum = 0;
		bool flag = false;
		int u;
		cin >> u;
		int a[u];
		for(int j = 0; j<u; j++) {
			cin >> a[j];
			sum += a[j];
		}
		for(int k = 0; k<u; k++) {
			ans+=a[k];
			if(ans == sum - ans) {
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

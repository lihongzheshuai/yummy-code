#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string m;
	for(int i = 0; i<n; i++) {
		cin >> m;
		int l[4] = {1,1,1,1};
		for(int j = 0; j<m.length(); j++) {
			if(m[j] > '1') {
				l[0] = 0;
			}
			if(m[j] > '7') {
				l[1] = 0;
			}
			if(m[j] > '9') {
				l[2] = 0;
			}
			if(m[j] > 'F') {
				l[3] = 0;
			}
		}
		cout << l[0]<<" "<<l[1]<<" "<<l[2]<<" "<<l[3]<<endl;
	}
	return 0;
}

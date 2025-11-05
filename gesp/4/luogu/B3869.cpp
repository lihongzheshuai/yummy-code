#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	string a;
	int jin;
	for(int i = 0; i<n; i++) {
		long long count = 0;
		cin >> jin >> a;
		for(int j = 0; j<a.length(); j++) {
			if(a[j]=='A') {
				long long lin = pow(jin,a.length()-j-1);
				count += ('A'-'A'+10)*lin;
			} else if(a[j] == 'B') {
				long long lin = pow(jin,a.length()-j-1);
				count += ('B'-'A'+10)*lin;
			} else if(a[j] == 'C') {
				long long lin = pow(jin,a.length()-j-1);
				count += ('C'-'A'+10)*lin;
			} else if(a[j] == 'D') {
				long long lin = pow(jin,a.length()-j-1);
				count += ('D'-'A'+10)*lin;
			} else if(a[j] == 'E') {
				long long lin = pow(jin,a.length()-j-1);
				count += ('E'-'A'+10)*lin;
			} else if(a[j] == 'F') {
				long long lin = pow(jin,a.length()-j-1);
				count += ('F'-'A'+10)*lin;
			} else {
				long long lin = pow(jin,a.length()-j-1);
				count += (a[j]-'0')*lin;
			}
		}
		cout << count << endl;
	}
	return 0;
}

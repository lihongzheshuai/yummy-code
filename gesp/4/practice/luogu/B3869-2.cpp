#include<bits/stdc++.h>
using namespace std;
string a;
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		long long count = 0;
		int jin;
		cin >> jin;
		cin >> a;
		for(int j = a.length()-1; j>=0; j--) {
			if(a[j] == 'A') {
				count+=10*pow(jin,a.length()-j-1);
			} else if(a[j] == 'B') {
				count+=11*pow(jin,a.length()-j-1);
			} else if(a[j] == 'C') {
				count+=12*pow(jin,a.length()-j-1);
			} else if(a[j] == 'D') {
				count+=13*pow(jin,a.length()-j-1);
			} else if(a[j] == 'E') {
				count+=14*pow(jin,a.length()-j-1);
			} else if(a[j] == 'F') {
				count+=15*pow(jin,a.length()-j-1);
			} else {
				count+=(a[j]-'0')*pow(jin,a.length()-j-1);
			}
		}
		cout << count << "\n";
	}
	return 0;
}

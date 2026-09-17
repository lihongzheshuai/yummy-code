#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string si = "similar";
	string ns = "not similar";
	for(int i = 0; i<n; i++) {
		string a;
		string b;
		cin >> a >> b;
		if(a==b) {
			cout << si << endl;
			continue;
		}
		if(abs((int)a.length()-(int)b.length())>1) {
			cout << ns << endl;
			continue;
		}
		if(a.length()==b.length()) {
			int count = 0;
			for(int j = 0; j<a.length(); j++) {
				if(a[j]!=b[j]) {
					count++;
				}
			}
			if(count>1) {
				cout << ns << endl;
			} else {
				cout << si << endl;
			}
			continue;
		}
		string s, h;
		if(a.length()>b.length()) {
			s = a;
			h = b;
		} else {
			s = b;
			h = a;
		}
		int count = 0;
		int ans = 0;
		for(int j = 0; j<s.length(); j++) {
			if(s[j]!=h[count]) {
				ans++;
			} else {
				count++;
			}
		}
		if(ans>1) {
			cout << ns << endl;
		} else {
			cout << si << endl;
		}
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >> n;
	n += ',';
	string a;
	int count = 0;
	bool flag = true;
	for(int i = 0; i<n.length(); i++) {
		if(n[i] == ',') {
			a = n.substr(i-count,count);
			count = 0;
			if(a.length()>=6&&a.length()<=12) {
				flag = true;
			} else {
				flag = false;
				continue;
			}
			int ans[4] = {0};
			for(int j = 0; j<a.length(); j++) {
				if(a[j]>='A'&&a[j]<='Z') {
					ans[0] = 1;
				} else if(a[j]>='a'&&a[j]<='z') {
					ans[1] = 1;
				} else if(a[j]>='0'&&a[j]<='9') {
					ans[2] = 1;
				} else if(a[j]=='!'||a[j]=='@'||a[j]=='#'||a[j]=='$') {
					ans[3] = 1;
				} else {
					flag = false;
					break;
				}
			}
			if(flag) {
				if(ans[0]+ans[1]+ans[2]>=2&&ans[3]==1) {
					cout << a<<endl;
				}
			}
		} else {
			count++;
		}
	}
}

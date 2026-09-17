#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >>n;
	int ans = 0;
	bool flag = true;
	for(int i = 0; i<(n.length()+1)/2; i++) {
		ans = n.length()-1-i;
		if(n[i]!=n[ans]) {
			flag = false;
			break;
		} else {
			flag = true;
		}
	}
	if(flag) {
		cout << "yes";
	} else {
		cout << "no";
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >> n;
	for(int i = 0; i<5; i++) {
		for(int j = 0; j<n.length(); j++) {
			if(n[j]=='0') {
				if(i==0||i==4) {
					cout << ".....";
				} else {
					cout << ".***.";
				}
			} else if(n[j]=='1') {
				cout << "****.";
			} else if(n[j]=='2') {
				if(i==0||i==2||i==4) {
					cout << ".....";
				} else if(i==1) {
					cout << "****.";
				} else {
					cout << ".****";
				}
			} else {
				if(i==0||i==2||i==4) {
					cout << ".....";
				} else {
					cout << "****.";
				}
			}
		}
		cout << endl;
	}
	return 0;
}

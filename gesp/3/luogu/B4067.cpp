#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >> n;
	for(int i = 0; i<5; i++) {
		for(int j = 0; j<n.length(); j++) {
			if(i==0) {
				if(n[j]=='0'|| n[j]=='2'||n[j]=='3') {
					cout << ".....";
				} else {
					cout << "****.";
				}
				if(j == n.length()-1) {
					cout << endl;
				}
			} else if(i==1) {
				if(n[j]=='0') {
					cout << ".***.";
				} else {
					cout << "****.";
				}
				if(j == n.length()-1) {
					cout << endl;
				}
			} else if(i==2) {
				if(n[j]=='0') {
					cout << ".***.";
				} else if(n[j]=='1') {
					cout << "****.";
				} else  {
					cout << ".....";
				}
				if(j == n.length()-1) {
					cout << endl;
				}
			} else if(i==3) {
				if(n[j]=='0') {
					cout << ".***.";
				} else if(n[j]=='1'||n[j]=='3') {
					cout << "****.";
				} else {
					cout << ".****";
				}
				if(j == n.length()-1) {
					cout << endl;
				}
			} else if(i==4) {
				if(n[j]=='0'||n[j]=='2'||n[j]=='3') {
					cout << ".....";
				} else {
					cout << "****.";
				}
			}
		}
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >> n;
	string u = n;
	for(int i = 0; i<n.length(); i++) {
		if(n[i]>='a'&&n[i]<='z') {
			n[i]-=32;
		} else if(n[i]>='A'&&n[i]<='Z') {
			n[i]+=32;
		}
		u[n.length()-1-i] = n[i];
		if(u[n.length()-1-i]=='x') {
			u[n.length()-1-i] = 'a';
		} else if(u[n.length()-1-i]=='X') {
			u[n.length()-1-i] = 'A';
		} else if(u[n.length()-1-i]=='y') {
			u[n.length()-1-i] = 'b';
		} else if(u[n.length()-1-i]=='Y') {
			u[n.length()-1-i] = 'B';
		} else if(u[n.length()-1-i]=='z') {
			u[n.length()-1-i] = 'c';
		} else if(u[n.length()-1-i] == 'Z') {
			u[n.length()-1-i] = 'C';
		} else {
			u[n.length()-1-i] = u[n.length()-1-i] + 3;
		}
	}
	cout << u;
	return 0;
}

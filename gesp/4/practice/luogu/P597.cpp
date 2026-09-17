#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	cin >> n;
	int a=0, b=0, c=0;
	string h="";
	for(int i = 0; i<n.length(); i++) {
		if(n[i] == '=') {
			if(isdigit(n[i+1])) {
				if(h == "a") {
					a = n[i+1] - '0';
				} else if(h=="b") { 
					b = n[i+1] - '0';
				} else {
					c = n[i+1] - '0';
				}
			} else {
				if(n[i+1]=='a') {
					if(h=="b") {
						b = a;
					}
					if(h=="c") {
						c = a;
					}
				} else if(n[i+1]=='b') {
					if(h=="a") {
						a = b;
					}
					if(h=="c") {
						c = b;
					}
				} else {
					if(h=="b") {
						b = c;
					}
					if(h=="a") {
						a = c;
					}
				}
			}
			if(n[i+3] == ';') {
				i = i+2;
				break;
			}
			h = "";
		}	else {
			if(n[i]!=':') {
				h = n[i];
			} else {
				continue;
			}
		}
	}

	cout <<  a << " " << b << " " << c;
	return 0;
}

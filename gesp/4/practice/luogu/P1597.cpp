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
			if(n[i+1] == ';') {
				cout << "0";
				continue;
			}
			for(int j = 1;; j++) {
				if(isdigit(n[i+j])) {
					if(h == "a") {
						a = n[i+j] - '0';
//						cout << " " << a << " ";
					} else if(h=="b") {
						b = n[i+j] - '0';
//						cout << "b:" << b << " ";
					} else {
						c = n[i+j] - '0';
//						cout << " " << c << " ";
					}
				} else {
//					cout << "1" << endl;
					if(n[i+j]=='a') {
						if(h=="b") {
							b = a;
						}
						if(h=="c") {
							c = a;
						}
					} else if(n[i+j]=='b') {
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
				if(n[i+j+1] == ';') {
//					cout << " ";
					i = i+j+1;
					break;
				}
			}
			h = "";
		} else {
			if(n[i]!=':') {
				h = n[i];
//				cout << n[i] << endl;
			} else {
				continue;
			}
		}
	}
	cout <<  a << " " << b << " " << c;
	return 0;
}

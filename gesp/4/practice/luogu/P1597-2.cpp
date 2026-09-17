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
				string number_str;
				for(int k = 0;;k++){
					if(n[i+k+1]==';'){
						break;
					}
					number_str += n[i+1+k];
				}
				int number =  stoi(number_str);
				if(h == "a") {
					a = number;
				} else if(h=="b") { 
					b = number;
				} else {
					c = number;
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

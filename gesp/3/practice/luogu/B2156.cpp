#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	getline(cin,n);
	int count = 0;
	int max = 0;
	string max_str;
	for(int i = 0; i<n.length(); i++) {
		if(n[i]!=' ') {
			count++;
		}
		if(n[i]=='.'||n[i]==' ') {
			if(n[i]=='.') {
				string temp = n.substr(i-count+1,count-1);
				if(	max < temp.length()) {
					max = temp.length();

					max_str = temp;
				}
				count = 0;
			} else {
				string temp = n.substr(i-count,count);
				if(	max < temp.length()) {
					max = temp.length();


					max_str = temp;
				}
				count = 0;
			}
		}
	}
	cout << max_str;
	return 0;
}

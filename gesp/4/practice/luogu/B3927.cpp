#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
string pan(string x) {
	if(mp.find(x)!=mp.end()) {
		return mp[x];
	}
	return "UNK";
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i<n; i++) {
		string a;
		string b;
		cin >> a >> b;
		mp[a]=b;
	}
	string str;
	cin >> str;
	str+=".";
	string str_1;
	for(int i = 0; i<str.length(); i++) {
		if(str[i]>='a'&&str[i]<='z') {
			str_1 += str[i];
		} else {
			if(str_1.length()>0) {
				cout << pan(str_1);
				str_1 = "";
			}
			if(i==str.length()-1) {
				break;
			}

			cout << str[i];
		}
	}
	return 0;
}

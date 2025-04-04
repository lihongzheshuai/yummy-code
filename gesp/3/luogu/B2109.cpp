#include<string>
#include<iostream>
using namespace std;
string s; 
int main(){
	getline(cin,s);
	int ans = 0;
	for(int i = 0;i<s.length();i++) {
		if(s[i] >='0'&&s[i]<='9'){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 

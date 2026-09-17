#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
string p(string a){
	if(mp.find(a)!=mp.end()){
		return mp[a];
	}
	return "UNK";
}
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	string c;
	cin >> c;
	c = c+".";
	string c_1;
	for(int i = 0;i<c.length();i++){
		if(c[i]>='a'&&c[i]<='z'){
			c_1 += c[i];
		}else{
			if(c_1.length() > 0){
				cout << p(c_1);
				c_1 = "";
			}
			if(i==c.length()-1){
				break;
			}
			cout << c[i];
		}
	}
	return 0;
}

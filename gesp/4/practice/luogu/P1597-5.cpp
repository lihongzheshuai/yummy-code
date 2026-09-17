#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,string> mp;
string xun(string var_name) {
	if(isdigit(var_name[0])){
		return var_name;
	}
	if(mp.find(var_name)==mp.end()){
		return "0";
	}else{
		return mp[var_name];
	}
}
int main() {
	string n;
	cin >> n;
	int count = 0;
	for(int i = 0; i<n.length();) {
		string str_1;
		string str;
		int x_1 = (int)n.find(":",i);
		str_1 = n.substr(i,x_1-i);
		i = x_1+2;//a:=3;ba:=4;
		int x = (int)n.find(";",i);
		str = n.substr(i,x-i);
		i = x+1;
		str = xun(str);
		mp[str_1] = str;
	}
	cout << mp["a"] << " ";
	cout << mp["b"] << " ";
	cout << mp["c"] << " ";
	return 0;
}


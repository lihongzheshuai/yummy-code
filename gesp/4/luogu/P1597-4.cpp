#include<iostream>
#include<string>
using namespace std;
string str_name[30];
string str_zhi[30];
string find_value(string x){
	for(int i = 0;i<3;i++){
		if(str_name[i]==x){
			return str_zhi[i];
		}
	}
}
string xun(string var_zhi) {
	if(isdigit(var_zhi[0])){
		return var_zhi;
	}
	for(int i = 0; i<30; i++) {
		if(str_name[i] == var_zhi) {
			return str_zhi[i];
		}
	}
	return "0";
}
int pan(string var_name) {
	for(int i = 0; i<30; i++) {
		if(str_name[i] == var_name) {
			return i;
		}
	}
	return -1;
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
		int idx = pan(str_1);
		if(idx==-1) {
			str_name[count] = str_1;
			str_zhi[count] = str;
			count++;
		} else {
			str_zhi[idx] = str;
		}
	}
	string a = "a";
	string b = "b";
	string c = "c";
		cout << find_value(a) << " ";
		cout << find_value(b) << " ";
		cout << find_value(c) << " ";
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	string str_1;  
	while(cin >> str){
		if(islower(str[0])){
			transform(str.begin(),str.end(),str.begin(),::toupper);
		}else if(isupper(str[0])){
			transform(str.begin(),str.end(),str.begin(),::tolower);
		}else{
			reverse(str.begin(),str.end());
		}
		str_1 = str + str_1;
		str_1 = " " + str_1;
	}
	cout << str_1.substr(1) << endl;
	return 0;
}

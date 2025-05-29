#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	while(cin >> str){
		if(str[0] >= 'A' && str[0] <='Z'){
			for(int i = 0;i<str.length();i++){
				str[i] = str[i] + 'a' - 'A';
			}
		}else if(str[0]>='a'&&str[0]<='z'){
			for(int i = 0;i<str.length();i++){
				str[i] = str[i] - 'a' +  'A';
			}
		}
		cout << str << " "; 
	}
	return 0;
}

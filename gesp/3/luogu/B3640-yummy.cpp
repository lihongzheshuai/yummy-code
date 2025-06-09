#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	string str_1[1000];
	int count = 0;
	while(cin>>str){
		if(str[0]>='A'&&str[0]<='Z'){
			for(int i = 0;i<str.length();i++){
				str[i] = str[i] +'a'-'A'; 
			}
		}else if(str[0]>='a'&&str[0]<='z'){
			for(int i = 0;i<str.length();i++){
				str[i] = str[i] +'A'-'a';
			}
		}else if(str[0]>='0'&&str[0]<='9'){
			string e = str;
			for(int i = str.length()-1;i>=0;i--){
				str[str.length()-1-i]=e[i];
			}
		}
		str_1[count] = str;
		count++; 
	}
	for(int i = count-1;i>=0;i--){
		cout << str_1[i] << " ";
	}
	return 0;
}

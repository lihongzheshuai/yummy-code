#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	string str_ary[1000]; 
	int count = 0;
	while(cin >> str){
		if(str[0] >= 'A' && str[0] <='Z'){
			for(int i = 0;i<str.length();i++){
				str[i] = str[i] + 'a' - 'A';
			}
		}else if(str[0]>='a'&&str[0]<='z'){
			for(int i = 0;i<str.length();i++){
				str[i] = str[i] - 'a' +  'A';
			}
		}else if(str[0]>='0'&&str[0]<='9'){
			string temp = str; 
			for(int i = temp.length()-1;i>=0;i--){
				str[str.length() - 1 - i] = temp[i];
			}
		} 
		str_ary[count] = str;
		count++;
	}
	for(int i = count - 1;i >=0;i--){
		cout << str_ary[i] << " ";
	}
	return 0;
}

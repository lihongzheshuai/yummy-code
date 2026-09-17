#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	getline(cin,n);
	bool flag = true;
	if(n[0]>='0'&&n[0]<='9'){
		cout << "no";
		return 0;
	}
	for(int i = 1;i < n.length();i++){
		if(n[i]>='A'&&n[i]<='Z'){
			flag = true;
		}else if(n[i]>='a'&&n[i]<='z'){
			flag = true;
		}else if(n[i]>='0'&&n[i]<='9'){
			flag = true;
		}else if(n[i]=='_'){
			flag = true;
		}else{
			flag = false;
			break;
		}
	}
	if(flag){
		cout << "yes";
	}else{
		cout << "no";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int ss(string str){
	int count = 0;
	int d = 0; 
	if(str[0]=='0'&&str[1] == 'x'){
		d = 2;
	}
	long long ans = 0;
	for(int i = str.length()-1;i>=d;i--){
		int idx = 0;
		if(str[i]>='A'&&str[i]<='F'){
			idx = str[i] - 'A' + 10;
		}else if(str[i]>='a'&&str[i]<='f'){
			idx = str[i] - 'a' + 10;
		}else{
			idx = str[i] - '0';
		}
		ans += idx * pow(16,count);
		count++;
	}
	return ans;
}
int ss1(string a){
	return stoi(a,nullptr,16);
}
char str_4(int x){
	if(x > 10){
		return 'A'+(x-10);
	}
	return '0' + x;
}
string str(int z){
	if(z==0){
		return "0";
	}
	string str_1;
	while(z!=0){
		if(z % 16 >= 10){
			str_1 = str_4(z%16)+ str_1;
			z /= 16;
		}else{
			str_1 = str_4(z%16) + str_1;
			z /= 16; 
		}
	}
	if(str_1.length()<4){
		for(int i = 0;i<=4-str_1.length();i++){
			str_1 = "0" + str_1;
		}
	}
	return str_1;
} 
string pan(string x){
	string str_1;
	for(int i = 0 ;i<x.length();i++){
		if(x[i] >= 'a'&&x[i]<='z'){
			x[i] = x[i] - 32;
			str_1+=x[i];
		}else if(x[i]>='A'&&x[i]<='Z'){
			x[i]+= 32;
			str_1+= x[i];
		}else{
			continue;
		}
	}
	return str_1;
}
bool flag(string x){
	for(int i = 0;i<x.length()-1;i++){
		if(x[i]>x[i+1]){
			return false;
		}
	}
	return true;
}
bool flag_1(string x){
	for(int i = 0;i<x.length()-1;i++){
		if(x[i]<x[i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	string str_1 = "ff";
	int n = 254;
	string str_2 = "0xFE";
	string str_3 = "10"; 
	cout << ss(str_1) << " " << ss(str_2) << " " << ss(str_3) << "\n";
	cout << ss1(str_1) << " " << ss1(str_2) << " " << ss1(str_3) << "\n";
	printf("%x\n",n);
	printf("%#X\n",n);
	printf("%#06x\n",n);
	cout << str(n) << "\n";
	cout << pan("Yummy0708liyizhou")<<"\n";
	cout << flag("abcd") <<"\n";
	cout << flag("dcba") <<"\n";
	cout << flag("acdb") <<"\n";
	cout << flag_1("abcd") <<"\n";
	cout << flag_1("dcba") <<"\n";
	cout << flag_1 ("acdb") <<"\n";
	return 0;
} 

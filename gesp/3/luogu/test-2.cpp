#include<bits/stdc++.h>
using namespace std;
int main(){
	string n = "AbCdEf";
	long long a = 123456711232;
	// 乘以 121的结果
	string str = "123456711232";
	transform(n.begin(),n.end(),n.begin(),::toupper);
	cout << n << endl;
	transform(n.begin(),n.end(),n.begin(),::tolower);
	cout << n << endl;
	n[0]-=32;
	cout << n << endl;
	n[0]+=32;
	n[n.length()-1]-=32;
	cout << n << endl; 
	int b[10]={0};
	while(a!=0){
		int count = a%10;
		b[count]++;
		a /= 10;
	}
	for(int i = 0;i<10;i++){
		cout << b[i] << " ";
	}
	cout << endl;
	a = 123456711232;
	int u[10] = {0};
	string s = to_string(a);
	for(int i = 0;i<s.length();i++){
		u[s[i]-'0']++;
	}
	for(int i = 0;i<10;i++){
		cout << u[i] << " ";
	}
	cout << endl;
	long long ll = stoll(str);
	cout << ll * 121 << endl;
	return 0;
}

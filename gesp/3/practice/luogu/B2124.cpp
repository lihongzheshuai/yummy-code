#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	cin >> n;
	string a;
	for(int i = 0;i<n.length();i++){
		a = n[i] + a;
	}
	if(a==n){
		cout << "yes";
	}else{
		cout << "no";
	}
	return 0;
}

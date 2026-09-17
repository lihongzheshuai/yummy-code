#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	getline(cin,n);
	int count = 0;
	for(int i = 0;i<n.length();i++){
		if(n[i]==' '){
			continue;
		}else{
			count++;
		}
	} 
	cout << count;
	return 0;
} 

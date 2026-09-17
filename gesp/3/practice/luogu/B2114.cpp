#include<iostream>
#include<string>
using namespace std;
int main(){
	string n;
	cin >> n;
	for(int i = 0;i<n.length();i++){
		if(n[i]== 'A'){
			n[i] = 'T';
		}else if(n[i]=='T'){
			n[i] = 'A';
		}else if(n[i] == 'G'){
			n[i] = 'C';
		}else{
			n[i] = 'G';
		}
	}
	cout << n;
	return 0;
} 

#include<iostream>
#include<string> 
using namespace std;
int main(){
	string n;
	getline(cin,n);
	int count  = 0;
	for(int i = 0;i<n.length();i++){
		if(n[i]!=' '){
			if(i==n.length()-1){
				for(int k = i;k>=i-count;k--){
					cout << n[k];
				}
				break;
			} 
			count++;
			
		}else{
			for(int j = i-1;j>=i-count;j--){
				cout << n[j];
			}
			cout << endl;
			count=0;
		}
		
	}
	return 0;
} 

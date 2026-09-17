#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	string k;
	cin >> k;
	int count = 1;
	for(int i = 0;i<k.length();i++){
		if(k[i]==k[i+1]){
			count++;
		}else{
			if(count>=n){
				cout << k[i];
				return 0;
			}else{
				count = 1;
			}
		}
	}
	cout << "No";
	return 0;
} 

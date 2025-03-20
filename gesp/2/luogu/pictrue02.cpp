#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int u = n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(j>=u){
				cout <<"*";
			}else{
				cout <<" ";
			}
		}
		u--;
		cout << endl;
	}
	return 0;
} 

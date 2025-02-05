#include<iostream>
using namespace std;
int main(){
	int n;
	cin >>n;
	for(int i = 1;i<=n;i++){
		cout << "|";
		for(int j = 1;j<=n-2;j++){
			if(i == 1 || i == n || i==(n+1)/2){
				cout << "-";
			}else{
				cout << "x";
			}
		}
		cout << "|" << endl;
	}
} 

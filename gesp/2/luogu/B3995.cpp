#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cout << "|";
		for(int j = 1;j<=n-2;j++){
			if(i == 1 || i == n){
				cout << "-";
			}else if(i == (n+1)/2){
				if(j == (n-2+1)/2){
					cout << "x";
				}else{
					cout << "-";
				}
			}else{
				if(j == (n-2+1)/2){
					cout << "|";
				}else{
					cout << "x";
				}
			}
			
		}
		cout << "|"<< endl;
	}
}

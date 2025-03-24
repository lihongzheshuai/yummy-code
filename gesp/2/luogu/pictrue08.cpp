#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = (n+1)/2;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i==ans||j==ans){
				cout << "*";
			}else if(i<ans){
				if(j==ans-i+1||j==ans+i-1){
					cout <<"*";
				}else{
					cout <<" "; 
				}
			}else{
				if(j==i-ans+1||j==n-i+ans){
					cout << "*";
				}else{
					cout <<" "; 
				}
			}
		}
		cout << endl;
	}
	return 0;
}

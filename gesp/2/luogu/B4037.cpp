#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cout << "+";
		for(int j = 1;j<=n-2;j++){
			if(i==1||i==n){
				cout << "-";
			}else{
			if(j==i-1){
				cout << "+";
			}else{
				cout << "-";
			}
		}
		}
		cout << "+"<<endl;
	}
	return 0;
}

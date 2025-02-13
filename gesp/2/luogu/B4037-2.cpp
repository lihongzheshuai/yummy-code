#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if (j == 1) {
				cout << "+";
				continue;
			}
			if(j==n){
				cout << "+";
				break;
			}
			if(i==1||i==n){
				cout << "-";
			}else{
				if(j==i){
					cout << "+";
				}else{
					cout << "-";
				}
			}
		}
		cout << endl;
	}
	return 0;
}

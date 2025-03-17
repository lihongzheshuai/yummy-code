#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int f = 1;
	int y = n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(j==f||j==y){
				cout << "+";
			}else{
				cout << "-";
			}
		}
		cout << endl;
		f++;
		y--;
	}
	return 0;
} 

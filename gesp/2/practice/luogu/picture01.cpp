#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int g = 1;
	int m = n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(j==g||j==m){
				cout << "*";
			}else{
				cout << " ";
			}
		}
		g++;
		m--;
		cout << endl;
	} 
	return 0;
} 

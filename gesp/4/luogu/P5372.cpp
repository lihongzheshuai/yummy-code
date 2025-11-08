#include<iostream>
using namespace std;
int a[20][20];
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=i;j++){
			if(j == 1||j==i){
				a[i][j] = 1;
				cout << a[i][j] << " ";
			}else{
				a[i][j] = a[i-1][j-1] + a[i-1][j];
				cout << a[i][j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
} 

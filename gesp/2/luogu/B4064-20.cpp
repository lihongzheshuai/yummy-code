#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(pow(j,4)==i){
				cout << j;
			}else{
				cout << "-1";
			}
		}
		cout << endl;
	}
	return 0;
}

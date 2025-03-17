#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		int a;
		cin >> a;
		bool flag = false;
		for(int i = 1;i<=sqrt(a);i++){
			for(int j = 1;j<=sqrt(a);j++){
				if(i*i+j*j==a){
					flag = true;
				}
			}
		}
		if(flag){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0; 
} 

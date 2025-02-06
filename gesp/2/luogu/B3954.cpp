#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b;
	long long ans = 1;
		for(int i = 1;i<=a;i++){
			cin >> b;
			if(ans>1000000){
				cout << ">1000000";
				return 0;
			}else{
				ans*=b;
			}
		}
		cout << ans;
	return 0;
} 

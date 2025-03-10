#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >>b;
	int ans = 0;
	if(a==1){
		cout << "0";
		return 0;
	}
	for(int i = a;i<=b;i++){
		int flag = true;
		for(int j = 2;j<i;j++){
			if(i%j==0){
				flag=false;
			}
		}
		if(flag){
			ans++;
		}
	} 
	cout << ans;
	return 0;
} 

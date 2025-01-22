#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	int ans = 0;
	
	for(int i = a;i <= b;i++){
		bool flag=true;
		for(int j = 2;j<=sqrt(i);j++){
			if(i % j == 0){
				flag = false;
				
			}
		}
		if(flag){
			ans++;
		}
		
	}
	cout << ans;
	return 0;
}

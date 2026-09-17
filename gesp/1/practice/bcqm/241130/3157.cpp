#include<iostream>
using namespace std;
int main(){
	int a;
	int ans = 0;
	while(true){
		cin >> a;
		if(a == -1){
			break;
		}else{
			ans += a;
		}
	}
	cout << ans;
	return 0;
}

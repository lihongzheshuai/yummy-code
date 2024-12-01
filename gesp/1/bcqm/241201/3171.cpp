#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = a;i <= b;i++){
		if(i % 17 == 0){
			ans += i;
		}
	}
	cout << ans;
	return 0;
}

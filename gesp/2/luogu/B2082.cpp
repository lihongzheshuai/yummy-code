#include <iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = a;i<= b;i++){
		int d = i,num;
		while(d != 0){
			num = d % 10;
			if(num == 2){
				ans++;
			}
			d /= 10;
		}
	}
	cout << ans;
	return 0;
}

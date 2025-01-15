#include<iostream>
using namespace std;
int main(){
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int ans = 0;
	for(int i = 0;i <= e;i++){
		for(int j = 0;j <= e;j++){
				int chi = e - i - j;
				if(chi >= 0 && chi % c == 0 && a * i + b * j + chi / c == d){
					ans++;
				}
		}
	}
	cout << ans;
	return 0;
}

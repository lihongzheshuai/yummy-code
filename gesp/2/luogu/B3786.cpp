#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int j = 0;
	int o = 0;
	int ans = 0;
	for(int i = a;i<=b;i++){
		while(){
			int u = i % 10;
			if(u % 2 == 0){
				j += u;
			}else{
				o += u;
			}
			if(j == o){
				ans++;
			}
			
		}
	}
	cout << ans;
	return 0;
}

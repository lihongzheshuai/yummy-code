#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans=0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<= n;j++){
			int a = sqrt(i*i+j*j);
			if(a * a == i * i + j * j && a <= n){
				ans += 1;
			}
		}
	}
	cout << ans;
	return 0;
} 

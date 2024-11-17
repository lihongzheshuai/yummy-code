#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	int ans = 0;
	int m;
	int* count=new int[n];
	for(int i = 1;i <= n;i++){
		cin >> count[i-1];
	}
	cin >> m;
	for(int e = 1;e <= n;e++){
		if(m == count[e-1]){
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}

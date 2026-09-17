#include<iostream>
using namespace std;
int main(){
	int x, y, z, n, m;
	cin >> x >> y >> z >> n >> m;
	int ans=0;
	for(int i = 0;i<=m;i++){
		for(int j = 0;j<=m;j++){
			int count = m-i-j;
			if((count >=0&&count%z==0)&&i*x+j*y+count/z==n){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

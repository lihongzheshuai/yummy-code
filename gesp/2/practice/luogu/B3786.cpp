#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	int ans = 0;
	int bns = 0;
	int count = 0;
	int y = 0;
	for(int i = a;i<=b;i++){
		int c = i;
		while(c!=0){
			y++;
			int u = c%10;
			if(y%2==0){
				ans+=u;
			}else{
				bns+=u;
			}
			c/=10;
		}
		if(ans==bns){
			count++;
		}
		ans = 0;
		bns=0;
	}
	cout << count;
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >>n;
	int ans = 0;
	while(true){
		if(n==495){
			cout << ans;
			break;
		}
		int s1 = n%10;
		int s2 = n/10%10;
		int s3 = n/10/10;
		int ma = max(s1,max(s2,s3));
		int mi = min(s1,min(s2,s3));
		int mid = s1+s2+s3-ma-mi;
		n=ma*100+mid*10+mi-mi*100-mid*10-ma;
		ans++;
	}
	return 0;
}

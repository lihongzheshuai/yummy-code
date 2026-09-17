#include<iostream>
using namespace std;
int main(){
	int n;
	cin >>n;
	int ans = 1;
	for (int i = 1;i<=n;i++){
		ans *= i;
	} 
	
	for(long long i = 1;;i++){
		if(n==1&&i==1){
		cout << 2 << " " << 1 << " " << 1;
		return 0;
	}
		double j = ((ans-n)*i)/(i-1);
		double k = (ans-n)*(i*i)/(i-1)-ans*i;
		if((int)j-(int)k/i==ans&&((int)j-(int)k)/i==n){
			cout << j <<" " << k << " " << i;
			return 0;
		}
	}
	return 0;
}

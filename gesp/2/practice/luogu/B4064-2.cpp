#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		cin >> a;
		if(sqrt(sqrt(a))==(int)(sqrt(sqrt(a)))){
			ans = sqrt(sqrt(a));
		}
		if(ans==0){
			cout << "-1";
		}else{
			cout << ans;
		}
		cout << endl;
		ans = 0;
	}
	return 0;
}

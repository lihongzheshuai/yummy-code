#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans=0;
	int count = 0;
	if(n>=2){
		cout << "2" << endl;
		ans++;
		count+=2;
	}
	for(int i =3;i<=n;i++){
		bool flag = true;
		for(int j = 2;j<=sqrt(i);j++){
			if(i%j==0){
				flag = false;
			}
		}
		if(flag&&count+i<=n){
			cout << i << endl;
			ans++;
			count+=i;
		}
	}
	cout << ans;
	return 0;
}

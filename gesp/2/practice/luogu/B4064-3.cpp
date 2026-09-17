#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		int a;
		cin >> a;
		bool flag = false;
			if(sqrt(sqrt(a))==(int)sqrt(sqrt(a))){
				cout << sqrt(sqrt(a)) << endl;
				flag = true;
			}
		if(flag == false){
			cout << "-1"<<endl;
		}
	}
	return 0;
}

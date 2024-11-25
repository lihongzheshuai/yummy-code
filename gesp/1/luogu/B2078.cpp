#include<iostream>
using namespace std;
int main(){
	long long m, k;
	cin >> m >> k;
	int ans=0;
	while(true){
		
		if(m % 10 == 3){
			ans ++;
		
		}
		m /= 10;
		if(m == 0){
			break;
		}
	}
	if(ans == k){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}

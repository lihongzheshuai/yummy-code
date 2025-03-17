#include<iostream>
using namespace std;
int main(){
	long long x;
	cin >> x;
	char a, b;
	cin >> a >> b;
	long long ans = 0;
	if(a=='A'&&b=='A'){
		cout << x;
		return 0;
	} 
	if((a=='B'&& b!='C')||(a!='C'&& b=='B')){
		ans = x / 10 * 8;
	}else if((a=='C'&& b!='B')||(a!='B'&& b=='C')){
		ans = x / 10 * 7;
	}else{
		ans = x / 10 * 6;
	}
	cout << ans;
	return 0;
} 

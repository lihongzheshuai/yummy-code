#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long s = 0,l=0;
	for(long long i = n;i>=1;i--){
		s+=i*i;
	}
		l = (1+n)* n;
		l+=n*2;
	cout << l << endl;
	cout << s;
	return 0;
} 


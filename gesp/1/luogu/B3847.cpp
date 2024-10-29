#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	char d;
	cin >> a >> b >> c >> d;
	if(d == 'A'){
		cout << a * 3600 + b * 60 + c;
	}
	if(d == 'P'){
		cout << (a + 12) * 3600 + b * 60 + c;
	}
	return 0;	
} 

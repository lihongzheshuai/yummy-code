#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int i = 2;
	while(true) {
		if((a % i == b % i) && (b % i == c % i)){
			cout << i;
			break;
		}
		i++;	
	}
	return 0;	
}

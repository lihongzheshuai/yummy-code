#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int count = 0;
	while(true){
		if(n == 495){
			cout << count;
			break;
		}
		int n1 = n % 10;
		int n2 = n / 10 % 10;
		int n3 = n / 10 / 10;
		
		int n_max = max(n1,max(n2,n3));
		int n_min = min(n1,min(n2,n3)); 
		int n_mid = n1 + n2 + n3 - n_max - n_min;

		n = n_max * 100 + n_mid * 10 + n_min - n_min * 100 - n_mid * 10 - n_max;
		count++;
	
	}
	
	return 0;
}

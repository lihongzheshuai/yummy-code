#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;;i++){
		bool flag = true;
		if(i == 1){
			flag = false;
		}
		if(i == 2){
			flag = true;
		}
		for (int j = 2;j <= sqrt(i);j++) {
			if (i % j == 0) {
				flag = false;
			}
			
			
		}
		if (flag) {
			n--;
			
		}      
		if(n==0){
			cout << i;
			break;
		}
	}
	return 0;
}

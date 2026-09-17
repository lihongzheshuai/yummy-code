#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;i<=2025-n;i++){
		if((n&i)+(n|i)==2025){
			cout << i; 
		}
	} 
	return 0;
}

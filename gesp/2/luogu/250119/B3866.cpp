#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1;;i++){
		int max=0;
		while(n!=0){
			max = n % 10;
			if(n / 10 % 10 > max){
				max = n / 10 % 10;
			}
			
		}
	}
} 

#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int ans = 1;
	for(int i = 1;i<=a;i++){
		int bns = i, d;
		while(bns!=0){
			d = bns % 10;
			if(d == 7 || bns % 7 == 0){
				break;
			}
		}
	}
}

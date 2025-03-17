#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >>n;
	int y = 1;
	for(int i = n;i>=1;i--){
		for(int j = i;j>=1;j--){
			printf("%02d",y);
			y++;
		}
		cout << endl;
	} 
	return 0;
} 

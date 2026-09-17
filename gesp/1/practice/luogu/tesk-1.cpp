#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	printf("%d*2", 5);
	for(int i = 1;i<= n ;i++){
		if(n >= 5){
		printf("%d\n", n);
		continue;
		}
		if(!!n){
			printf("%d\n", n - 1);
		}	
	}
	return 0;
}

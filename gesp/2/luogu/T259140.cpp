#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a;
	cin >> a;
	int b = 1;
	for(int i = 0;i<=a;i){
		for(int j = 1;j<=a;j++){
			if(b / 10 == 0){
				printf("%.02d", b);
			}else{
				printf("%d", b);
			}
			b++;
		}
		cout << endl;
		a -= 1;
	}
	return 0;
} 

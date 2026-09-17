#include<cstdio>
using namespace std;
int main(){
	char n[5];
	scanf("%s", n);
	int i = 0;
	if('D' == n[0] ){
		i += 30;
	}else{
		i += 0;
	}
	if('C' ==  n[1]){
		i += 30;
	}else{
		i += 0;
	}
	if('B' == n[2] ){
		i += 30;
	}else{
		i += 0;
	}
	if('A' == n[3]){
		i += 30;
	}else{
		i += 0;
	}
	if( 'D' == n[4]  ){
		i += 30;
	}else{
		i += 0;
	}
	printf("%d", i);
	return 0;
} 

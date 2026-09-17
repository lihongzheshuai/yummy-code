#include<cstdio>
#include<stdlib.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<= n;i++){
		if((i % 2 != 0) && (i < 50 || i >= 100 && i <=200)){
			printf("%d\n", i);	
		}
	}
	system("pause"); 
	return 0;	
}

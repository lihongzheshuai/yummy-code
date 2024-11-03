#include<cstdio>
int main(){
	int n;
	scanf("%d", &n);
	int a = 1, b = 2;
	int q = b / a;
	for(int i = 1;i <= n;i++){
		q += (b+1.0) / (a+1);	
	}
	printf("%4f",q);
	return 0;
}

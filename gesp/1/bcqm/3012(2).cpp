#include<cstdio>
int main(){
	int a, b, c = 0;
	scanf("%d%d", &a, &b);
	printf("a=%d ", a);
	printf("b=%d\n", b);
	c = b;
	b = a;
 	a = c;
 	printf("a=%d ", a);
	printf("b=%d\n", b);
 	return 0;
}

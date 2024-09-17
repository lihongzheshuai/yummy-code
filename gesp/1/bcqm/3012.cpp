#include<cstdio>
int main(){
	int a = 10, b = 20, c = 0;
	printf("a=%d ", a);
	printf("b=%d\n", b);
	c = b;
	b = a;
 	a = c;
 	printf("a=%d ", a);
	printf("b=%d\n", b);
 	return 0;
}

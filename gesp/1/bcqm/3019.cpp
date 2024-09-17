#include<cstdio>
int main(){
	int x, y, c = 0;
	scanf("%d%d", &x, &y);
	printf("a=%d ", x);
	printf("b=%d\n", y);
	c = y;
	y = x;
 	x = c;
 	printf("a=%d ", x);
	printf("b=%d\n", y);
 	return 0;
}

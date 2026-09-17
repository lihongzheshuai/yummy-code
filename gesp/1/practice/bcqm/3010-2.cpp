#include<cstdio>
using namespace std;
int main(){
	int a, b, c = 0;
	scanf("%d%d", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("a=%d\n", a);
	printf("b=%d", b);
	return 0;
}

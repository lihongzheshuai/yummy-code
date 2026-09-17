#include<cstdio>
using namespace std;
int main(){
	int a;
	scanf("%d", &a);
	int b;
	int ans = 0;
	for(int i = 1;i<=a;i++){
		scanf("%d", &b);
		ans += b;
	} 
	printf("%.2f", (double)ans / (double)a);
	return 0;
}

#include<cstdio>
int main(){
	int n;
	scanf("%d", &n);
	double ans = 0;
	double a;
	for(int i = 0;i < n;i++){
		scanf("%lf", &a);
		ans += a;	
	}
	printf("%.4f", (double)ans / n);	
	return 0;
}

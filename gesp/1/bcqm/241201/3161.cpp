#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int a;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &a);
		ans += a;
	}
	printf("%d %.5f", ans, (double)ans / (double)n);
	return 0;	
} 

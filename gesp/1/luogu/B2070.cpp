#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int ans = 0, bns = 0;
	for(int i = 1;i<=n;i++){
		if(i % 2 != 0){
			ans += i;
		}
		if(i % 2 == 0){
			bns += i;
		}
	}
	printf("%.4f", (1 / (double)ans) - (1 / (double)bns));
	return 0;
}

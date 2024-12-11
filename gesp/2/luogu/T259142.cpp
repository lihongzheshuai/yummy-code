#include<cstdio>
int main(){
	int a, b, ans=0;
	scanf("%d%d", &a,&b);
	for(int i = 1;i<=a;i++){
		int d = i;
		while(d != 0){
			ans = d % 10;
			if(ans == b){
				ans++;
				d = d / 10; 
			}
		}
	}
	printf("%d", ans);
	return 0;
}

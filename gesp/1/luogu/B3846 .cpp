#include<cstdio>
using namespace std;
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = 0;
	for(a + 1;a < b;a++){
		if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0){
			ans += a;
		}
	}
	printf("%d", ans);
	return 0;
}

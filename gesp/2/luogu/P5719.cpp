#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int k;
	cin >> k;
	int a=0,b=0;
	int ans=0,bns=0;
	for(int i = 1;i<=n;i++){
		if(i%k==0){
			a+=i;
			ans++;
		}else{
			b+=i;
			bns++;
		}
	}
	printf("%.1f %.1f",(double)a/(double)ans,(double)b/(double)bns);\
	return 0;
}

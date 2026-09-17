#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int g;
	int max=0;
	int min=11;
	int m=0;
	for(int i = 1;i<=n;i++){
		cin >> g;
		if(g>max){
			max = g;
		}
		if(g<min){
			min = g;
		}
		m+=g;
	} 
	int ans = m - max - min;
	printf("%.2f",(double)ans / (n-2));
	return 0;
}

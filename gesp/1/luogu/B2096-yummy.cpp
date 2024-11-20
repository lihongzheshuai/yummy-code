#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int	a1 = 1;
	int a2 = 2;
	int b1 = 2;
	int b2 = 3;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i<=n;i++){
    	n = a1 + a2;
    	a1 = a2;
    	a2 = (double)n;
    	ans += a2 / a1;
	}
	printf("%.4f", ans); 
    return 0;
}

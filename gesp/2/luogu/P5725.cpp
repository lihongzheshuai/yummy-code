#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	int count = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			count++;
			printf("%02d",count);
		}
		cout << endl;
	}
	cout << endl;
	count = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			
			if (j <= n - i) {
				printf("  "); 
			} else {
				count++;
				printf("%.02d",count);
			}	 
		}
		cout << endl;
	}
}

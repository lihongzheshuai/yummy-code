#include<iostream>
#include<string>
using namespace std;
int c[1000000] = {0};
int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int m = 0;
	int p; 
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=a;j++){
			for(int k = 1;k<=b;k++){
				c[i+j+k]++;
//				cout << i  << " " << j << " " << k  << " ->" << " " << i + j + k<< endl; 
			}
		}
	}
	for(int i = 0;i <= n + a + b;i++){
		if(c[i] > m){
			m = c[i];
			p = i;
		}
	}
	cout << p;
	return 0;
} 

#include<iostream>
using namespace std;
int main(){
	int m, n;
	cin >> m >> n;
	int z[10]={0};
	for(int i = m;i<=n;i++){
		int u = i;
		while(u!=0){
			int count = u % 10;
			z[count]++;
			u /= 10;
		}
	}
	for(int i = 0;i<10;i++){
		cout << z[i] << " ";
	}
	return 0; 
} 

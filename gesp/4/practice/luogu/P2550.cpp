#include<bits/stdc++.h>
using namespace std;
int b[105];
int a[105];
int main(){
	int n;
	cin >> n;
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0;
	for(int i = 0;i<7;i++){
		cin >> b[i];
	}
	for(int i = 0;i<n;i++){
		int count = 0;
		for(int j = 0;j<7;j++){
			cin >> a[j];
		}
		for(int j = 0;j<7;j++){
			for(int k = 0;k<7;k++){
				if(a[j] == b[k]){
					count++;
					break;
				}
			}
		}
		if(count == 1){
			a7++;
		}
		if(count == 2){
			a6++;
		}
		if(count == 3){
			a5++;
		}
		if(count == 4){
			a4++;
		}
		if(count == 5){
			a3++;
		}
		if(count == 6){
			a2++;
		}
		if(count == 7){
			a1++;
		}
	}
	cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << " " << a7;
	return 0; 
} 

#include<bits/stdc++.h>
using namespace std;
string x[15];
int main() {
	int a, b;
	int max = 0;
	cin >> a >> b;
	int ans_0 = 0;
	int ans_1 = 0;
	int count = 0;
	for(int i = 0;i<a;i++){
		cin >> x[i];
	}
	for(int i = 0;i<a;i++){
		for(int j = 0;j<b;j++){
			 for(int k = i;k<a;k++){
			 	for(int w = j;w<b;w++){
			 		for(int y = i;y<=k;y++){
			 			for(int z = j;z <= w;z++){
			 				if(x[y][z] == '0'){
			 					ans_0++;
							 }else{
							 	ans_1++;
							 }
						 }
					 }
					 if(ans_0 == ans_1){
					 	if(ans_0+ans_1 > max){
					 		max = ans_0+ans_1;
						 }
					 	count++;
					 }	
					 ans_0 = 0;
					 ans_1 = 0;
				}
			}
		}
	}
	cout << max;
	return 0; 
}

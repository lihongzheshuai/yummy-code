#include<bits/stdc++.h>
using namespace std;
string a[15];
int main(){
	int n, m;
	cin >> n >> m;
	int count_0 = 0;
	int count_1 = 0;
	int max = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			for(int k = i;k<n;k++){
				for(int w = j;w<m;w++){
					for(int h = i;h<=k;h++){
						for(int s = j;s<=w;s++){
							if(a[h][s] == '0'){
								count_0++;
							}else{
								count_1++;
							}
						}
						if(count_0==count_1){
							if(count_0+count_1>max){
								max = count_0+count_1;
							}
						}
					}
					count_0 = 0;
					count_1 = 0;
				}
			}
		}
	}
	cout << max;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[105][105][105];
int main() {
	int w,x,h;
	cin >> w >> x >> h;
	int q;
	cin >> q;
	for(int i = 1; i<=w; i++) {
		for(int j = 1; j<=x; j++) {
			for(int k = 1; k<=h; k++) {
				a[i][j][k] = 1;
			}
		}
	}
	int count = 0;
	for(int i = 0; i<q; i++) {
		int x1,y1,z1,x2,y2,z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for(int j = x1; j<=x2; j++) {
			for(int k = y1;k<=y2; k++) {
				for(int w = z1; w<=z2; w++) {
					a[j][k][w]=0;
				}
			}
		}
	}
	for(int i = 1;i<=w;i++){
		for(int j = 1;j<=x;j++){
			for(int k = 1;k<=h;k++){
				if(a[i][j][k]==1){
					count++;
				}
			}
		}
	}
	cout <<count; 
	return 0;
}
